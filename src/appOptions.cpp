/*****************************************************************************
* filename : appOptions.cpp
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : Contains application Options form interface
*
*****************************************************************************/
#include "stdafx.h"
#include "fingerprint.h"
#include "appOptions.h"
#include "soundplayer.h"

using namespace FingerPrint;
using namespace System::IO;

appOptions::appOptions(void)
{
    InitializeComponent();
    logFile = SETTINGS_MANAGER().GetLogFileName();
    LoadControlsValue();

    this->nbDatabaseOptions->Enabled = false;
    this->nbGeneralOptions->Enabled = false;
    this->nbMiscellaneousOptions->Enabled=false;
    this->nbEventsOptions->Enabled = true;

    if ( fingerprintApp::GetCurrentOperator()->GetLevel() == ABSEN_ONLY )
    {
    }
    else if ( fingerprintApp::GetCurrentOperator()->GetLevel() == REGISTER_ONLY )
    {
       this->nbGeneralOptions->Enabled = true;
    }
    else if ( fingerprintApp::GetCurrentOperator()->GetLevel() == EDIT_USER_ONLY )
    {
       this->nbMiscellaneousOptions->Enabled=true;
       this->nbDatabaseOptions->Enabled = true;
    }
    else if ( fingerprintApp::GetCurrentOperator()->GetLevel() == SUPERVISOR )
    {
      this->nbDatabaseOptions->Enabled = true;
      this->nbGeneralOptions->Enabled = true;
      this->nbMiscellaneousOptions->Enabled = true;
    }
    else if ( fingerprintApp::GetCurrentOperator()->GetLevel() == ADMINISTRATOR )
    {
      this->nbDatabaseOptions->Enabled = true;
      this->nbGeneralOptions->Enabled = true;
      this->nbMiscellaneousOptions->Enabled = true;
    }
}

System::Void appOptions::SaveControlsValue()
{
    LOG_MANAGER().Log("Saving controls value", LOG_DEBUG);

    SETTINGS_MANAGER().SetLogFileTarget( this->txtLogFile->Text );
    LOG_MANAGER().SetLogFile(this->txtLogFile->Text);
    LOG_MANAGER().Log("Log File Target : " + SETTINGS_MANAGER().GetLogFileTarget(), LOG_DEBUG);

    SETTINGS_MANAGER().SetLogToDatabase( this->enableLogToDatabase );
    LOG_MANAGER().Log("enableLogToDatabase : " + Convert::ToString(SETTINGS_MANAGER().GetLogToDatabase() ), LOG_DEBUG);

    SETTINGS_MANAGER().SetMinLoggingLevel( (int)cbLoggingLevel->SelectedIndex );
    LOG_MANAGER().SetLogLevel( SETTINGS_MANAGER().GetLoggingLevel() );
    LOG_MANAGER().Log("minLoggingLevel: " + Convert::ToString(SETTINGS_MANAGER().GetMinLoggingLevel() ), LOG_DEBUG);

    SETTINGS_MANAGER().SetUserName( this->txtUserName->Text );
    LOG_MANAGER().Log("userName : " + SETTINGS_MANAGER().GetDBUserName(), LOG_DEBUG);

    SETTINGS_MANAGER().SetPassword( txtPassword->Text );
    LOG_MANAGER().Log("password : " + SETTINGS_MANAGER().GetPassword(), LOG_DEBUG);

    SETTINGS_MANAGER().SetServer( txtServer->Text );
    LOG_MANAGER().Log("server : " + SETTINGS_MANAGER().GetServer(), LOG_DEBUG);

    SETTINGS_MANAGER().SetDatabase( this->txtDatabase->Text );
    LOG_MANAGER().Log("database : " + SETTINGS_MANAGER().GetDatabase(), LOG_DEBUG);

    try
    {
       SETTINGS_MANAGER().SetServerPort( Convert::ToInt32(this->txtPort->Text) );
    }
    catch (Exception^ )
    {
        FP_LOGMESSAGE("Error in port number.\n Please enter the correct port number", LOG_ERROR);
        return;
    }
    LOG_MANAGER().Log("port : " + Convert::ToString(SETTINGS_MANAGER().GetServerPort() ), LOG_DEBUG );

    SETTINGS_MANAGER().SetFormVerifyInGreeting(this->txtInGreeting->Text );
    SETTINGS_MANAGER().SetFormVerifyOutGreeting(this->txtOutGreeting->Text );
    SETTINGS_MANAGER().SetOfficeLocation(this->txtLocation->Text);

}
System::Void appOptions::LoadControlsValue()
{
    LOG_MANAGER().Log("Loading Form Options controls value from settingsManager", LOG_DEBUG);
    this->txtLogFile->Text             = SETTINGS_MANAGER().GetLogFileTarget();

    if ( SETTINGS_MANAGER().GetLogToDatabase() )
        this->chkLogToDatabase->Checked = true;
    else
        this->chkLogToDatabase->Checked  = false;

    cbLoggingLevel->SelectedIndex      = SETTINGS_MANAGER().GetMinLoggingLevel();
    this->txtUserName->Text            = SETTINGS_MANAGER().GetDBUserName();
    this->txtPassword->Text            = SETTINGS_MANAGER().GetPassword();
    this->txtServer->Text              = SETTINGS_MANAGER().GetServer();
    this->txtDatabase->Text            = SETTINGS_MANAGER().GetDatabase();
    this->txtPort->Text                = SETTINGS_MANAGER().GetServerPort().ToString();

    this->txtLocation->Text = SETTINGS_MANAGER().GetOfficeLocation();
    this->txtInGreeting->Text = SETTINGS_MANAGER().GetFormVerifyInGreeting();
    this->txtOutGreeting->Text = SETTINGS_MANAGER().GetFormVerifyOutGreeting();

	try
	{
		// sounds items
		this->cbStartWork->Items->Clear();
		this->cbStartWork->Items->AddRange(gcnew cli::array< System::Object^  >(1) {SETTINGS_MANAGER().GetStartOfficeHourSound()} );
		array<String^>^ sound_files4 = Directory::GetFiles( SETTINGS_MANAGER().GetAppSoundsDir(),gcnew String("*.wav"));  
		this->cbStartWork->Items->AddRange(sound_files4);
		cbStartWork->SelectedIndex = 0;
	   
		this->cbEndWork->Items->Clear();
		this->cbEndWork->Items->AddRange(gcnew cli::array< System::Object^  >(1) {SETTINGS_MANAGER().GetEndOfficeHourSound()} );
		array<String^>^ sound_files5 = Directory::GetFiles( SETTINGS_MANAGER().GetAppSoundsDir(),gcnew String("*.wav"));  
		this->cbEndWork->Items->AddRange(sound_files5);
		cbEndWork->SelectedIndex = 0;
	    
		this->cbStartBreak->Items->Clear();
		this->cbStartBreak->Items->AddRange(gcnew cli::array< System::Object^  >(1) {SETTINGS_MANAGER().GetStartBreakTimeSound()} );
		array<String^>^ sound_files6 = Directory::GetFiles( SETTINGS_MANAGER().GetAppSoundsDir(),gcnew String("*.wav"));  
		this->cbStartBreak->Items->AddRange(sound_files6);
		cbStartBreak->SelectedIndex = 0;
	    
		this->cbEndBreak->Items->Clear();
		this->cbEndBreak->Items->AddRange(gcnew cli::array< System::Object^  >(1) {SETTINGS_MANAGER().GetEndBreakTimeSound()} );
		array<String^>^ sound_files7 = Directory::GetFiles( SETTINGS_MANAGER().GetAppSoundsDir(),gcnew String("*.wav"));  
		this->cbEndBreak->Items->AddRange(sound_files7);
		cbEndBreak->SelectedIndex = 0;


		this->cbOkaySounds->Items->Clear();
		this->cbOkaySounds->Items->AddRange(gcnew cli::array< System::Object^  >(1) {SETTINGS_MANAGER().GetSuccessSound()} );
		array<String^>^ sound_files = Directory::GetFiles( SETTINGS_MANAGER().GetAppSoundsDir(),gcnew String("*.wav"));  
		this->cbOkaySounds->Items->AddRange(sound_files);
		cbOkaySounds->SelectedIndex = 0;
	   
		this->cbFailedSounds->Items->Clear();
		this->cbFailedSounds->Items->AddRange(gcnew cli::array< System::Object^  >(1) {SETTINGS_MANAGER().GetFailedSound()} );
		array<String^>^ sound_files1 = Directory::GetFiles( SETTINGS_MANAGER().GetAppSoundsDir(),gcnew String("*.wav"));  
		this->cbFailedSounds->Items->AddRange(sound_files1);
		cbFailedSounds->SelectedIndex = 0;
	    
		this->cbWarnSounds->Items->Clear();
		this->cbWarnSounds->Items->AddRange(gcnew cli::array< System::Object^  >(1) {SETTINGS_MANAGER().GetWarningSound()} );
		array<String^>^ sound_files2 = Directory::GetFiles( SETTINGS_MANAGER().GetAppSoundsDir(),gcnew String("*.wav"));  
		this->cbWarnSounds->Items->AddRange(sound_files2);
		cbWarnSounds->SelectedIndex = 0;
	    
		this->cbErrorSounds->Items->Clear();
		this->cbErrorSounds->Items->AddRange(gcnew cli::array< System::Object^  >(1) {SETTINGS_MANAGER().GetErrorSound()} );
		array<String^>^ sound_files3 = Directory::GetFiles( SETTINGS_MANAGER().GetAppSoundsDir(),gcnew String("*.wav"));  
		this->cbErrorSounds->Items->AddRange(sound_files3);
		cbErrorSounds->SelectedIndex = 0;
	}
	catch (Exception ^e)
    {
      FP_LOGMESSAGE(e->ToString());
    }
}
System::Void appOptions::txtLogFile_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    // create folder browser dialog
    FolderBrowserDialog^ browseFolderDlg = gcnew System::Windows::Forms::FolderBrowserDialog();
    browseFolderDlg->RootFolder = Environment::SpecialFolder::MyComputer;

    // Show the FolderBrowserDialog.
    System::Windows::Forms::DialogResult result = browseFolderDlg->ShowDialog();
    // catch the result
    if ( result == ::DialogResult::OK )
    {
        String^ folderName       = browseFolderDlg->SelectedPath;
        this->txtLogFile->Text   = folderName + logFile;
        logFileTarget            = folderName + logFile;

        LOG_MANAGER().Log("Log File is :  " + this->logFileTarget);
    }
    else
    { }
}

System::Void appOptions::cbLoggingLevel_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
   /*
                minLoggingLevel = (long)cbLoggingLevel->SelectedIndex;
                LOG_MANAGER().Log(String::Format( "Logging level set to : {0}", minLoggingLevel ), LOG_DEBUG);

  */
}
System::Void appOptions::txtUserName_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
  /*
                this->userName = this->txtUserName->Text;
                LOG_MANAGER().Log("UserName set to "+ this->userName);
  */
}
System::Void appOptions::txtPassword_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
  /*
                this->password =  txtPassword->Text;
  */
}
System::Void appOptions::txtServer_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
  /*
                this->server = txtServer->Text;
  */
}
System::Void appOptions::txtPort_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
}
System::Void appOptions::cmdApply_Click(System::Object^  sender, System::EventArgs^  e)
{
    SaveControlsValue();
}
System::Void appOptions::cmdOK_Click(System::Object^  sender, System::EventArgs^  e)
{
    SaveControlsValue();
    this->Close();
}
System::Void appOptions::appOptions_Load(System::Object^  sender, System::EventArgs^  e)
{

}
System::Void appOptions::OnEnableLogToDatabase(System::Object^  sender, System::EventArgs^  e)
{
   enableLogToDatabase = this->chkLogToDatabase->Checked;
   SETTINGS_MANAGER().SetLogToDatabase(this->chkLogToDatabase->Checked);
}
System::Void appOptions::OnTestFailedSound(System::Object^  sender, System::EventArgs^  e)
{
   PlayTheSound(this->cbFailedSounds->SelectedItem->ToString() );
}
System::Void appOptions::OnTestOkaySound(System::Object^  sender, System::EventArgs^  e)
{
   PlayTheSound(this->cbOkaySounds->SelectedItem->ToString() );
}
System::Void appOptions::OnTestWarnSound(System::Object^  sender, System::EventArgs^  e)
{
   PlayTheSound(this->cbWarnSounds->SelectedItem->ToString() );
}
System::Void appOptions::OnTestErrorSound(System::Object^  sender, System::EventArgs^  e)
{
   PlayTheSound(this->cbErrorSounds->SelectedItem->ToString() );
}
System::Void appOptions::OnCbFailedChanged(System::Object^  sender, System::EventArgs^  e)
{
    SETTINGS_MANAGER().SetFailedSound(this->cbFailedSounds->SelectedItem->ToString());
}
 
System::Void appOptions::OnCbOkayChanged(System::Object^  sender, System::EventArgs^  e)
{
    SETTINGS_MANAGER().SetSuccessSound(this->cbOkaySounds->SelectedItem->ToString());
}
System::Void appOptions::OnCbWarnCanged(System::Object^  sender, System::EventArgs^  e)
{
    SETTINGS_MANAGER().SetWarningSound(this->cbWarnSounds->SelectedItem->ToString());
}
System::Void appOptions::OnCbErrorChanged(System::Object^  sender, System::EventArgs^  e)
{
    SETTINGS_MANAGER().SetErrorSound(this->cbErrorSounds->SelectedItem->ToString());
}

System::Void appOptions::OnCbStartWorkChanged(System::Object^  sender, System::EventArgs^  e)
{
   SETTINGS_MANAGER().SetStartOfficeHourSound(this->cbStartWork->SelectedItem->ToString());
}
System::Void appOptions::OnCbWorkEndChanged(System::Object^  sender, System::EventArgs^  e)
{
   SETTINGS_MANAGER().SetEndOfficeHourSound(this->cbEndWork->SelectedItem->ToString());
}
System::Void appOptions::OnCbBreakStartChanged(System::Object^  sender, System::EventArgs^  e)
{
   SETTINGS_MANAGER().SetStartBreakTimeSound(this->cbStartBreak->SelectedItem->ToString());
}
System::Void appOptions::OnCbEndBreakChanged(System::Object^  sender, System::EventArgs^  e)
{
   SETTINGS_MANAGER().SetEndBreakTimeSound(this->cbEndBreak->SelectedItem->ToString());
}

System::Void appOptions::OnBtnStartWork(System::Object^  sender, System::EventArgs^  e)
{
   PlayTheSound(cbStartWork->SelectedItem->ToString() );
}

System::Void appOptions::OnBtnEndWork(System::Object^  sender, System::EventArgs^  e)
{
   PlayTheSound(cbEndWork->SelectedItem->ToString() );
}
System::Void appOptions::OnBtnBreakStart(System::Object^  sender, System::EventArgs^  e)
{
   PlayTheSound(cbStartBreak->SelectedItem->ToString() );
}
System::Void appOptions::OnBtnEndBreak(System::Object^  sender, System::EventArgs^  e)
{
   PlayTheSound(cbEndBreak->SelectedItem->ToString() );
}