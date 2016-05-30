/*****************************************************************************
* filename : fingerPrintAppForm.cpp
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : fingerPrintAppForm definitions
*
*****************************************************************************/

#include "StdAfx.h"

#include "fingerprint.h"
#include "fingerPrintAppForm.h"
#include "utils.h"
#include "appOptions.h"
#include "frmRegisterTemplate.h"
#include "frmVerify.h"
#include "dlgNeedPassword.h"
#include "frmEditUser.h"
#include "soundplayer.h"
#include "frmAdminTools.h"

using namespace FingerPrint;


fingerPrintAppForm::fingerPrintAppForm(void)
{
   FP_LOGMESSAGE("fingerPrintAppForm::fingerPrintAppForm(void)", LOG_DEBUG);
   InitializeComponent();
   
   fingerPrintAppForm::verifyForm = nullptr;

   if ( fingerprintApp::settingsManager.GetEnableEditUser() )
      this->m_btnEditUser->Show();
   else
      this->m_btnEditUser->Hide();

   
   this->Text = SETTINGS_MANAGER().GetAppShortName() + ", rev: " + SETTINGS_MANAGER().GetAppRevision()+ ", built: " + SETTINGS_MANAGER().GetAppBuildTime();
}

System::Void fingerPrintAppForm::fingerPrintAppForm_Load(System::Object^  sender, System::EventArgs^  e)
{
   FP_LOGMESSAGE("fingerPrintAppForm::fingerPrintAppForm_Load", LOG_DEBUG);

   if ( !fingerprintApp::IsConnected  )
   {
      this->statusBar_0->Text = L" Not Connected to database";
      this->cmdConnect->Enabled = true;
   }
   else if ( fingerprintApp::GetConnection()->IsOpen() )
      this->statusBar_0->Text = L" Connected to database";
   else
      this->statusBar_0->Text = L" Not Connected to database";
}

System::Void fingerPrintAppForm::cmdRegisterTemplate_Click(System::Object^  sender, System::EventArgs^  e)
{
   OpenNewForm(FORM_REGISTER_TEMPLATE);
}

System::Void fingerPrintAppForm::cmdConnect_Click(System::Object^  sender, System::EventArgs^  e)
{
   if ( fingerprintApp::IsConnected )
      this->statusBar_0->Text = L"Connected to database";
   else
   {
      dlgNeedPassword^ askPassword = gcnew dlgNeedPassword(false );
      askPassword->ShowDialog(this);
      if ( askPassword->DialogResult == ::DialogResult::OK )
      {
         SETTINGS_MANAGER().SetUserName( askPassword->Username() );
         SETTINGS_MANAGER().SetPassword( askPassword->Password() );
         SETTINGS_MANAGER().SetServer(askPassword->Server() );
         SETTINGS_MANAGER().SetDatabase( askPassword->Database() );
         
         int port = 0;
         try
         {
            port = Convert::ToInt32( askPassword->Port());
         }
         catch(System::FormatException^)
         {
            FP_LOGMESSAGE("Error in port number.\n Please enter the correct port number", LOG_ERROR);
            return;
         }
         SETTINGS_MANAGER().SetServerPort(port);

         fingerprintApp::GetConnection();
         if (fingerprintApp::IsConnected )
         {
            this->statusBar_0->Text = L"Connected to database";
            this->EnableControls();
            LogTimeToDatabase();
            WatchTimeChange();
         }
         else 
            this->statusBar_0->Text = L"Not Connected to database";
      }
      else
         delete askPassword;

   }
}
System::Void fingerPrintAppForm::cmdOptions_Click(System::Object^  sender, System::EventArgs^  e)
{
   OpenNewForm(FORM_OPTIONS);
}

System::Void fingerPrintAppForm::cmdInformations_Click(System::Object^  sender, System::EventArgs^  e)
{
}
System::Void fingerPrintAppForm::cmdInitDevice_Click(System::Object^  sender, System::EventArgs^  e)
{
}
System::Void fingerPrintAppForm::cmdLoadFrmVerify_Click(System::Object^  sender, System::EventArgs^  e)
{
   fingerPrintAppForm::verifyForm = gcnew frmVerify();
   fingerPrintAppForm::verifyForm->Show();
}

System::Void fingerPrintAppForm::OnEditUser(System::Object^  sender, System::EventArgs^  e)
{
   OpenNewForm(FORM_EDIT_USER);
}
System::Void fingerPrintAppForm::EnableControls()
{
   FP_LOGMESSAGE("fingerPrintAppForm::EnableControls()", LOG_DEBUG);
   this->label1->Enabled = true;
   this->cmdLoadFrmVerify->Enabled = true;
   this->cmdInitDevice->Enabled = true;
   this->cmdInformations->Enabled = true;
   this->cmdOptions->Enabled = true;
   this->cmdRegisterTemplate->Enabled = true;
   this->statusBar->Enabled = true;

   if ( fingerprintApp::settingsManager.GetEnableEditUser() )
      this->m_btnEditUser->Enabled = false;

   if ( fingerprintApp::IsConnected )
      this->cmdConnect->Enabled = false;
   else
      this->cmdConnect->Enabled = true;
}
System::Void fingerPrintAppForm::DisableControls()
{
   FP_LOGMESSAGE("fingerPrintAppForm::DisableControls()", LOG_DEBUG);
   this->label1->Enabled = false;
   this->cmdLoadFrmVerify->Enabled = false;
   this->cmdInitDevice->Enabled = false;
   this->cmdInformations->Enabled = false;
   this->cmdOptions->Enabled = false;
   this->cmdRegisterTemplate->Enabled = false;
   this->statusBar->Enabled = false;
   
   this->m_btnEditUser->Enabled = false;

   if ( fingerprintApp::IsConnected )
      this->cmdConnect->Enabled = false;
   else
      this->cmdConnect->Enabled = true;;
}
void fingerPrintAppForm::TimerEventProcessor( Object^ /*myObject*/, EventArgs^ /*myEventArgs*/ )
{
      myTimer->Stop();
      
      fingerprintApp::timeChecker.Now();  
      FP_LOGMESSAGE( fingerprintApp::timeChecker.GetTimeStamp(L"F"),LOG_DEBUG );
      
      if( GetTimeStamp("T") == String::Concat( SETTINGS_MANAGER().GetStartOfficeHour(),":00") )
         PlayTheSound(SETTINGS_MANAGER().GetStartOfficeHourSound() );
      if( GetTimeStamp("T") == String::Concat( SETTINGS_MANAGER().GetStartOfficeHour(),":02") )
         PlayTheSound(SETTINGS_MANAGER().GetStartOfficeHourSound() );

      if( GetTimeStamp("T") == String::Concat( SETTINGS_MANAGER().GetEndOfficeHour(),":00") )
         PlayTheSound(SETTINGS_MANAGER().GetEndOfficeHourSound() );
      if( GetTimeStamp("T") == String::Concat( SETTINGS_MANAGER().GetEndOfficeHour(),":02") )
         PlayTheSound(SETTINGS_MANAGER().GetEndOfficeHourSound() );

      if( GetTimeStamp("T") == String::Concat( SETTINGS_MANAGER().GetStartBreakTimeHour(),":00") )
         PlayTheSound(SETTINGS_MANAGER().GetStartBreakTimeSound() );
      if( GetTimeStamp("T") == String::Concat( SETTINGS_MANAGER().GetStartBreakTimeHour(),":02") )
         PlayTheSound(SETTINGS_MANAGER().GetStartBreakTimeSound() );

      if( GetTimeStamp("T") == String::Concat( SETTINGS_MANAGER().GetEndBreakTimeHour(),":00") )
         PlayTheSound(SETTINGS_MANAGER().GetEndBreakTimeSound() );
      if( GetTimeStamp("T") == String::Concat( SETTINGS_MANAGER().GetEndBreakTimeHour(),":02") )
         PlayTheSound(SETTINGS_MANAGER().GetEndBreakTimeSound() );

      if ( fingerprintApp::formVerifyFingerIsOpen )
         fingerPrintAppForm::verifyForm->SetTimeLabel( GetTimeStamp("t") );
      
      if( fingerprintApp::timeChecker.IsTimeChanged() )
      {
         PlayTheSound(SETTINGS_MANAGER().GetErrorSound());
         // disable all timer
         fingerPrintAppForm::StopAllTimer();
         fingerprintApp::logManager.WriteToDatabase("SISTEM MENDETEKSI PERUBAHAN JAM KOMPUTER !","CLOCK_CHANGED");
         FP_LOGMESSAGE("SISTEM MENDETEKSI PERUBAHAN JAM KOMPUTER !",LOG_ERROR );
      }      
      myTimer->Enabled = true;
}

void fingerPrintAppForm::TimeLoggerProcessor( Object^ /*myObject*/, EventArgs^ /*myEventArgs*/ )
{
      m_timerLogger->Stop();
      
      fpDateTime^ theTime = gcnew fpDateTime();     
      
      System::String^ sql;
      System::String^ timeToLog = theTime->GetBase64();

      SETTINGS_MANAGER().SetLastLoggedTime(timeToLog);
      
      if ( ! fingerprintApp::IsConnected )
         return;
      else
      {
         sql = String::Concat("UPDATE fp_last_recorded_time SET last_time =" , "'",timeToLog,"'"," WHERE id = 1" );
         fingerprintApp::GetConnection()->ExecuteUpdate(sql);
      }
      m_timerLogger->Enabled = true;

}
void fingerPrintAppForm::WatchTimeChange(/* System::ComponentModel::BackgroundWorker^ worker, DoWorkEventArgs ^ e */)
{

   FP_LOGMESSAGE("fingerPrintAppForm::WatchTimeChange()", LOG_DEBUG);
   myTimer = gcnew System::Windows::Forms::Timer;   
      /* Adds the event and the event handler for the method that will 
                process the timer event to the timer. */
   myTimer->Tick += gcnew EventHandler( TimerEventProcessor );
      
   // Sets the timer interval to 0.5 seconds.
   myTimer->Interval = 1000;
   myTimer->Start();
}
void fingerPrintAppForm::LogTimeToDatabase()
{
   FP_LOGMESSAGE("fingerPrintAppForm::LogTimeToDatabase()", LOG_DEBUG);

   m_timerLogger = gcnew System::Windows::Forms::Timer;
   m_timerLogger->Tick += gcnew EventHandler( TimeLoggerProcessor );
      
   // Sets the timer interval to 5 minutes.
   m_timerLogger->Interval = (1000 * 60 * 5);
   m_timerLogger->Start();
}

System::Void fingerPrintAppForm::StopAllTimer()
{
   FP_LOGMESSAGE("fingerPrintAppForm::StopAllTimer()", LOG_DEBUG);
   myTimer->Stop();
   m_timerLogger->Stop();
}

System::Void fingerPrintAppForm::OnOpenAdmin(System::Object^  sender, System::EventArgs^  e)
{
   OpenNewForm(FORM_ADMIN_TOOLS);
}
System::Void fingerPrintAppForm::OpenNewForm(fpFormID form_id)
{

   dlgNeedPassword^ askPassword = gcnew dlgNeedPassword();
   askPassword->ShowDialog(this);

   if ( askPassword->DialogResult == ::DialogResult::OK )
   {
        fingerprintApp::GetCurrentOperator()->SetName(askPassword->Username());
        fingerprintApp::GetCurrentOperator()->SetPasswd(askPassword->Password());
        
        if ( fingerprintApp::GetCurrentOperator()->Init() )
        {
           if ( !fingerprintApp::GetCurrentOperator()->Authenticate() )
           {
              fingerprintApp::logManager.WriteToDatabase(String::Concat(askPassword->Username()," , Password Rejected !"),"PASSWORD_ERROR" );
              MessageBox::Show( "\n" + "Sorry, Wrong Password","",MessageBoxButtons::OK,MessageBoxIcon::Error );
           }
           else
           {
               fingerprintApp::logManager.WriteToDatabase(String::Concat(askPassword->Username()," , Authenticated !"),"USER_LOGIN" );
               
               switch (form_id)
               {
               case FORM_OPTIONS:
                  {
                     appOptions^ frmOptions = gcnew appOptions();
                     frmOptions->ShowDialog();
                  }
                  break;
               case FORM_REGISTER_TEMPLATE:
                  {
                     frmRegisterTemplate^ registerTemplateForm = gcnew frmRegisterTemplate();
                     registerTemplateForm->Show();
                  }
                  break;
               case FORM_EDIT_USER:
                  {
                     frmEditUser^ editform = gcnew frmEditUser();
                     editform->Show();
                  }
                  break;
               case FORM_ADMIN_TOOLS:
                  {
                     frmAdminTools^ adminForm = gcnew frmAdminTools();
                     adminForm->ShowDialog();

                  }
                  break;
               case FORM_VERIFY:
                  {
                  }
                  break;
               default:
                     FP_LOGMESSAGE("Error occured when trying to open form", LOG_ERROR);
               }
           }
        }
        else
           fingerprintApp::logManager.WriteToDatabase(String::Concat("No Such User : ",askPassword->Username() ),"USER_ERROR" );
   }
   else
      delete askPassword;

}