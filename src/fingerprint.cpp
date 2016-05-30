/******************************************************************************
* filename : fingerprint.cpp
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : Main application definitions
*
******************************************************************************/
#include "stdafx.h"
#include "fingerprint.h"
#include "utils.h"
#include "soundplayer.h"

using namespace System;
using namespace System::Globalization;
using namespace System::Net;
using namespace System::Net::Mail;
using namespace System::Net::Mime;

using namespace FingerPrint;


[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
   // Enabling Windows XP visual effects before any controls are created
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);       

   fingerprintApp::timeToDecode = String::Empty;
   fingerprintApp::debuggingMode = false;
   fingerprintApp::IsConnected = false;
   
   fingerprintApp::user_name = String::Empty;

   fingerprintApp::formVerifyFingerIsOpen = false;

   if ( args->Length > 0 )
   {
      if ( args[0] == gcnew String("--debug") )
          fingerprintApp::debuggingMode = true;
      else if ( args[0] == gcnew String("decode-time") && (args[1] != String::Empty ) )
         fingerprintApp::timeToDecode = args[1];
      else
          fingerprintApp::debuggingMode = false;
    }

    // Create the main window and run it
    Application::Run(gcnew fingerprintApp());
  
    return 0;
}

fingerprintApp::fingerprintApp(void)
{
   closeClean = true;

   logManager.Log( "+--------------------------------------------------------+" ); 
   logManager.Log( "|           Initializing fingerprint Application         |" );
   logManager.Log( "|* try : fingerprint decode-time <time to decode >       |" );       

   if ( fingerprintApp::debuggingMode )
      logManager.Log( "|                   in debugging mode                    |" );
   else
      logManager.Log( "|         entering  normal mode                          |" );

   logManager.Log( "+--------------------------------------------------------+" );
   
   formCount = 0;

    // Handle the ApplicationExit event to know when the application is exiting.
    Application::ApplicationExit += gcnew EventHandler( this, &fingerprintApp::OnApplicationExit );
    
    // Init FPDevice now
    InitFP_Device();

    // Instantiate connection object
    fingerprintApp::fpConn = new pqxxConn();
    fingerprintApp::GetConnection();
    
    fingerprintApp::m_operator = gcnew fpOperator();

    // Instantiate fingerPrintAppForm
    this->theAppForm = gcnew fingerPrintAppForm();

    // Catch fingerPrintAppForm close event
    this->theAppForm->Closed += gcnew EventHandler( this, &fingerprintApp::OnFormClosed );
    // Catch fingerPrintAppForm closing event
    this->theAppForm->Closing += gcnew CancelEventHandler( this, &fingerprintApp::OnFormClosing );
    this->theAppForm->Show();

    // for test only, will be removed in stable release
    TestDateTime();

    // Show time!
   if ( fingerprintApp::IsConnected )
   {
      // these two function start the timer in main form
      this->theAppForm->LogTimeToDatabase();
      this->theAppForm->WatchTimeChange();

      // ok, now check for valid time. compare last logged time in
      // database with current time
      CheckDateTime();
      fingerprintApp::logManager.WriteToDatabase("FingerPrint Application Start..","APP_START");
   }
   else
   {
      // disable main form
      this->theAppForm->DisableControls();
   }
}
void fingerprintApp::OnApplicationExit( Object^ /*sender*/, EventArgs^ /*e*/ )
{
   
   fingerprintApp::logManager.WriteToDatabase("FingerPrint Application Exit.. ","APP_EXIT");
   logManager.Log( "fingerprintApp::OnApplicationExit", LOG_DEBUG);
   
   if ( fingerprintApp::IsConnected  )
      fingerprintApp::GetConnection()->Close();
   
   
   if ( closeClean && fingerprintApp::timeChecker.IsSystemTimeClean())
    {   
       SETTINGS_MANAGER().SaveFile();
       logManager.Log( "fingerprintApp::OnApplicationExit  closeClean", LOG_DEBUG);
    }
    
    logManager.Log( "+--------------------------------------------------------+" , LOG_INFO); 
    logManager.Log( "|                 FingerPrint Application Exit..         |" , LOG_INFO);
    logManager.Log( "+--------------------------------------------------------+" , LOG_INFO); 

}

void fingerprintApp::OnFormClosing( Object^ sender, CancelEventArgs^ /*e*/ )
{
}

void fingerprintApp::OnFormClosed( Object^ /*sender*/, EventArgs^ /*e*/ )
{
   logManager.Log( "fingerprintApp::OnFormClosed", LOG_DEBUG);
   ExitThread();
}


System::Void fingerprintApp::InitFP_Device()
{
   logManager.Log( "Initializing Device(s)");

   try 
   {
		this->m_deviceList = (gcnew DpSdkEngLib::FPDevices());   // Instantiate devices list object
		this->m_currentDevice = (gcnew DpSdkEngLib::FPDevice());

		logManager.Log( String::Concat("m_currentDevice SN : ",m_currentDevice->SerialNumber), LOG_DEBUG );

		DpSdkEngLib::FPDevice^ dev;                              // Temporary device object

		deviceCount = m_deviceList->Count;

		if ( deviceCount < 1 )
		{
			logManager.Log( String::Concat("No device found ") );
			return;
		}
		if ( deviceCount == 1 )
			logManager.Log( String::Concat("Found ", deviceCount.ToString(), " device" ) ); // Display it
		if ( deviceCount > 1 )
			logManager.Log( String::Concat("Found ", deviceCount.ToString(), " devices" ) );// Display it

		// Enumerate devices
		for each ( dev in m_deviceList )
		{
			logManager.Log( "+--------------------------------------------------------+");
			logManager.Log( "|                    Device Properties                   |");
			logManager.Log( "+--------------------------------------------------------+");
			logManager.Log( "| Device Capabilities   : " + dev->DeviceCaps.ToString() );
			logManager.Log( "| Security Capabilities : " + dev->SecurityCaps );
			logManager.Log( "| Nonce Size            : " + dev->NonceSize );
			logManager.Log( "| Planes                : " + dev->Planes );
			logManager.Log( "| Hardware Revision     : " + dev->HWRevision );
			logManager.Log( "| SerialNumber          : " + dev->SerialNumber );
			logManager.Log( "| Identifier            : " + dev->Identifier );
			logManager.Log( "| Firm Ware Revision    : " + dev->FWRevision );
			logManager.Log( "| Product               : " + dev->Product );

			DpSdkEngLib::AIImageType deviceImageType = dev->ImageType;

			switch (deviceImageType)
			{
				case DpSdkEngLib::AIImageType::It_Unknown:
				logManager.Log("| Product Image Type    : Unknown");
				break;
				case DpSdkEngLib::AIImageType::It_BlackWhite:
				logManager.Log("| Product Image Type    : BlackWhite");
				break;
				case DpSdkEngLib::AIImageType::It_GrayScale:
				logManager.Log("| Product Image Type    : GrayScale");
				break;
				case DpSdkEngLib::AIImageType::It_Color:
				logManager.Log("| Product Image Type    : Color");
				break;
				default:
				logManager.Log("| Product Image Type    : Unknown");
				break;
			} // switch
			logManager.Log( "+--------------------------------------------------------+");

		} // for
		m_currentDeviceSN = dev->SerialNumber;
		// Sets current device
		m_currentDevice = safe_cast<DpSdkEngLib::FPDevice^>( m_deviceList->Device(m_currentDeviceSN) );

		m_currentDevice->FingerLeaving += gcnew DpSdkEngLib::_IFPDeviceEvents_FingerLeavingEventHandler(this,&fingerprintApp::OnFPDevice_FingerLeaving);
		m_currentDevice->FingerTouching += gcnew DpSdkEngLib::_IFPDeviceEvents_FingerTouchingEventHandler(this,&fingerprintApp::OnFPDevice_FingerTouching);
   }
   catch (Exception ^e)
   {
      logManager.Log(e->ToString());
   }

}

DpSdkEngLib::FPDevice^ fingerprintApp::GetDevice()
{
    if ( ! m_currentDevice)
    {
       m_currentDevice = (gcnew DpSdkEngLib::FPDevice());
       return m_currentDevice;
    }
    else
        return  m_currentDevice;
}

System::String^ fingerprintApp::GetDeviceSerialNumber()
{
   return GetDevice()->SerialNumber;
}

int fingerprintApp::GetDeviceCount()
{
    return deviceCount;
}

pqxxConn* fingerprintApp::GetConnection()
{
    
   if (! fingerprintApp::fpConn->IsOpen() )
    {
      String ^username     = SETTINGS_MANAGER().GetDBUserName();
      String ^password     = SETTINGS_MANAGER().GetPassword();
      String ^servername   = SETTINGS_MANAGER().GetServer();
      String ^database     = SETTINGS_MANAGER().GetDatabase();
      int serverport       = SETTINGS_MANAGER().GetServerPort();

      bool connected = fingerprintApp::fpConn->Connect(ToBasicString(servername),
                                              ToBasicString(database),
                                              ToBasicString(username),
                                              ToBasicString(password),
                                              serverport);
      if ( connected )
         fingerprintApp::IsConnected = true;
      else
      {
                MessageBox::Show( "Unable to connect to database",
                                  "Warning ",
                                  MessageBoxButtons::OK,
                                  MessageBoxIcon::Exclamation );
         
                
                fingerprintApp::IsConnected = false;
      }
    }
    return fingerprintApp::fpConn;
}

System::Void fingerprintApp::OnFPDevice_FingerLeaving(/*DpSdkEngLib::_IFPDeviceEvents_Event^  e*/)
{

   LOG_MANAGER().Log("OnFPDevice_FingerLeaving", LOG_DEBUG);

}
System::Void fingerprintApp::OnFPDevice_FingerTouching(/*System::Object^  sender,DpSdkEngLib::_IFPDeviceEvents_Event^  e*/)
{
   LOG_MANAGER().Log("OnFPDevice_FingerTouching");

}
    
void fingerprintApp::TestDateTime()
{
   if (fingerprintApp::timeToDecode != String::Empty )
   {
      LOG_MANAGER().Log("-----------------DateTime Decoding-----------------------");
      String^ binTime = fingerprintApp::timeToDecode;
      LOG_MANAGER().Log(String::Concat(binTime, " decoded to ",GiveMeReadableEncodedDateTime(binTime) ));
      LOG_MANAGER().Log("-----------------DateTime Decoding-----------------------");
   }

}

void fingerprintApp::CheckDateTime()
{
   FP_LOGMESSAGE("fingerprintApp::CheckDateTime()", LOG_DEBUG);
   
   logManager.Log( "+---------------------------------------------------------" ); 
   logManager.Log( "| Checking last logged time in database                   " );

   String^ sql = "SELECT last_time FROM fp_last_recorded_time WHERE id=1";
   String^ lastloggedtime;
   lastloggedtime = fingerprintApp::GetConnection()->ExecuteScalar( sql );  
   fingerprintApp::timeChecker.FromBinary(lastloggedtime);

   logManager.Log( "| if last_logged_time in database == now, it means        " ); 
   logManager.Log( "| this operation might be the first time this app run,    " ); 
   logManager.Log( "| or there is something error in conversion               " ); 
   logManager.Log( "| Valid last_logged_time is < cuttent time                " ); 
   logManager.Log( String::Concat ("| Last logged time in database : ",fingerprintApp::timeChecker.GetTimeStamp(L"f")  ));
   logManager.Log( String::Concat ("| Last logged time in binary   : ", fingerprintApp::timeChecker.GetBase64() ));
   logManager.Log( "+---------------------------------------------------------" ); 

   DateTime current = DateTime::Now;

   if (fingerprintApp::timeChecker.GetDateTime() > current )
   {
      PlayTheSound(SETTINGS_MANAGER().GetErrorSound());

      String^ msg =  L"Perubahan pada jam komputer terdeteksi. ";
      msg += L"\nHubungi  System Administrator, \nAda yang berusaha mengubah jam??";
      msg += L"\nIngat semuanya telah tercatat ";

      // disable main form controls
      this->theAppForm->DisableControls();
      // disable all timer too
      this->theAppForm->StopAllTimer();

      MessageBox::Show( msg,
                        "Ehemmm ",
                        MessageBoxButtons::OK,
                        MessageBoxIcon::Stop );

      closeClean = false;
      logManager.Log( "Disabling main form controls because of system time changed" ); 
   }
}

fpOperator^ fingerprintApp::GetCurrentOperator()
{
      return m_operator;
}


