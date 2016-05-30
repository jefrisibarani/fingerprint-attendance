/******************************************************************************
* filename : frmVerify.cpp
* author   : Jefri Sibarani
* created  : November 17 2006
* summary  : Form Verify class
*
******************************************************************************/
#include "StdAfx.h"

#include "fingerprint.h"
#include "frmVerify.h"
#include "fpUtils.h"
#include "utils.h"
#include "fpVerify.h"
#include "fpTable.h"
#include "fpUser.h"
#include "fpMessageBox.h"
#include "soundplayer.h"

using namespace FingerPrint;
using namespace System::Diagnostics;

static bool IsNumber(String^ value)
{
    int count = value->Length;
    for ( int i=0; i< count; i++ )
    {
        if ( ! Char::IsNumber(value, i) )
            return false;
    }
    return true;
}
frmVerify::frmVerify(void)
{
	  InitializeComponent();
     m_currentUserDone = false;
     fingerprintApp::formVerifyFingerIsOpen = true;
}
System::Void frmVerify::OnShown(System::Object^  sender, System::EventArgs^  e)
{
     fingerprintApp::formVerifyFingerIsOpen = true;
}
System::Void frmVerify::OnClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
     fingerprintApp::formVerifyFingerIsOpen = false;
}

System::Void frmVerify::InitFPGetTemplateX()
{

    FP_LOGMESSAGE( "Initializing FPGetTemplateX" );
    this->SuspendLayout();
      
    this->m_axFPGetTemplateX = (gcnew AxDPSDKOPSLib::AxFPGetTemplateX()); 
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_axFPGetTemplateX))->BeginInit();

    this->m_axFPGetTemplateX->Enabled = true;
    this->m_axFPGetTemplateX->Location = System::Drawing::Point(0, 210);
    this->m_axFPGetTemplateX->Name = L"m_axFPGetTemplateX";
    //this->m_axFPGetTemplateX->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^  >(resources->GetObject(L"m_axFPGetTemplateX.OcxState")));
    this->m_axFPGetTemplateX->Size = System::Drawing::Size(380, 175);
    this->m_axFPGetTemplateX->TabIndex = 0;
    this->m_axFPGetTemplateX->Done += gcnew AxDPSDKOPSLib::_IFPGetTemplateXEvents_DoneEventHandler(this, &frmVerify::OnAxFPGetTemplateX_Done);

    this->Controls->Add(this->m_axFPGetTemplateX);
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_axFPGetTemplateX))->EndInit();

    this->PerformLayout();
}
fpUser^ frmVerify::GetCurrentUser()
{

   if (m_currentUser != nullptr)
      return m_currentUser;
   else
      m_currentUser = gcnew fpUser();

   return m_currentUser;
}

System::Void frmVerify::OnAxFPGetTemplateX_Done(System::Object^  sender, AxDPSDKOPSLib::_IFPGetTemplateXEvents_DoneEvent^  e)
{
    // template to be verified
    DpSdkEngLib::FPTemplate^ scannedTemplate = (DpSdkEngLib::FPTemplate^)e->pTemplate;
    FP_LOGMESSAGE( "Scanned Verification Template Instance ID : " + scannedTemplate->InstanceID , LOG_INFO);
    if ( GetCurrentUser()->VerifyFinger(scannedTemplate) )
    {
       if ( GetCurrentUser()->SaveAttendance(m_numberOfTry) )
       {

         m_currentUserDone = true;
         MakeLblGuideGreen();
         this->m_lblGuide->Text = L"Finger Verified";
         FP_LOGMESSAGE(String::Concat("currentUserDone", m_currentUserDone.ToString() ));          
          
		   SetStatusText(gcnew String("Finger Verified"));
         FingerPrint::PlaySuccesSound();
         ShowFpMessageBox(GetCurrentUser()->GetGreeting(),GetTimeStamp(L"T"));
         
         NormalizeForm();
       }
       else
          NormalizeForm();

    }
    else
    {
        this->m_lblGuide->Text = L"Maaf data sidik jari tidak cocok, coba jari yang lain";
        SetStatusText(gcnew String("Failed, try another finger please"));
        
		String^ msg1 =  String::Concat(GetCurrentUser()->GetName(),",",GetCurrentUser()->GetID());		
		fingerprintApp::logManager.WriteToDatabase(msg1,"FINGERPRINT_ERROR");
		
		MakeLblGuideRed();
        m_currentUserDone = false;
        FingerPrint::PlayFailedSound();
        Verify();
    }
}
System::Void frmVerify::OnFrmVerifyLoad(System::Object^  sender, System::EventArgs^  e)
{

   m_txtKodeVerifikasi->UseSystemPasswordChar = SETTINGS_MANAGER().GetFormVerifyUseSystemPasswordChar();
   this->InitFPGetTemplateX();
   NormalizeForm();
}
System::Void frmVerify::OnTxtKodeVerifikasiChanged(System::Object^  sender, System::EventArgs^  e)
{
}
System::Void frmVerify::OnTxtKodeVerifikasiKeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{

    // Only act if Enter pressed
    if ( e->KeyChar == (char)13 )
    {
     
       if ( this->m_txtKodeVerifikasi->Text->Length == 0 )
       {
           MessageBox::Show( "\n" + "Anda harus mengisi kode verifikasi terlebih dahulu",
                             "Informasi",
                             MessageBoxButtons::OK,
                             MessageBoxIcon::Information );
           e->Handled = true;
           return;
       }
       else if ( this->m_txtKodeVerifikasi->Text->Length < 4 )
       {
           MessageBox::Show( "\n" + "Kode Verifikasi harus 4 angka",
                             "Informasi",
                             MessageBoxButtons::OK,
                             MessageBoxIcon::Information );
           e->Handled = true;
           return;
       }      

        if ( IsNumber( this->m_txtKodeVerifikasi->Text)  )
        {
            
            if( fingerprintApp::timeChecker.IsTimeChanged() )
               this->m_txtKodeVerifikasi->Enabled = false;
            else
               Verify();

            e->Handled = true;
            return;
        } 
        else
        {
            FP_LOGMESSAGE("Tolong masukkan kode verifikasi yang benar",LOG_ERROR);
            this->m_txtKodeVerifikasi->Text = "";
            
            e->Handled = true;
            return;
        }
        e->Handled = true;
    }
    else
       return;
}

System::Void frmVerify::OnTxtKodeVerifikasiLeave(System::Object^  sender, System::EventArgs^  e)
{
}

System::Void frmVerify::Verify()
{
 
   int maxTry;
   maxTry = SETTINGS_MANAGER().GetFormVerifyMaxTry();  
   if ( maxTry <=1 )
      maxTry =10;
   
   if ( m_numberOfTry < maxTry )
    {   
           String^ rc = GetCurrentUser()->InitFromDB(this->m_txtKodeVerifikasi->Text);
           if (rc == L"USER OK")
           {
               DPSDKOPSLib::AIDevPriorities devPriority;
               devPriority = DPSDKOPSLib::AIDevPriorities::Dp_StdPriority;
               // Set device priority
               this->m_axFPGetTemplateX->SetDevicePriority(devPriority, this->Handle.ToInt32());

               // Set Template type, sice we are going to verify, then give it Tt_Verification
               //if ( this->chkVerification->Enabled )
               this->m_axFPGetTemplateX->TemplateType = DPSDKOPSLib::AITemplateTypes::Tt_Verification;
               //else
               //   this->axFPGetTemplateX->TemplateType = DPSDKOPSLib::AITemplateTypes::Tt_PreRegistration;

               DPSDKOPSLib::AIErrors errCode = this->m_axFPGetTemplateX->CreateOp();
               FP_LOGMESSAGE("axFPGetTemplateX->CreateOp()                : " + AIErrorsToString( (DpSdkEngLib::AIErrors)errCode )) ;
               if ( errCode != DPSDKOPSLib::AIErrors::Er_OK )
               {
                  FP_LOGMESSAGE( String::Concat("Fingerprint device throwing an error ","\n",AIErrorsToString((DpSdkEngLib::AIErrors)errCode) ),LOG_ERROR );
                  NormalizeForm();
                  return;
               }

               // Now, Run() it
               this->m_txtKodeVerifikasi->Enabled = false;
               errCode = this->m_axFPGetTemplateX->Run();
               FP_LOGMESSAGE("axFPGetTemplateX->Run()                : " + AIErrorsToString( (DpSdkEngLib::AIErrors)errCode )) ;
               m_numberOfTry++;
           }
           else
           {
              this->m_txtKodeVerifikasi->Text = L"";
              
           }
    }
    else
    {
        String^ msg =  String::Concat("Maaf, \n" ,
                                      " Setelah ", m_numberOfTry , " kali"
                                      " mencoba Anda tetap gagal.", "\n"
                                      " Mungkin Anda bukan ", GetCurrentUser()->GetName());

        this->m_lblGuide->Text = L"Finger Verification Failed!";
        SetStatusText(String::Concat("Finger Verification Failed after ",m_numberOfTry, " tries"));
        FP_LOGMESSAGE(msg, LOG_ERROR);
		
        String^ msg1 =  String::Concat(GetCurrentUser()->GetName(),",",GetCurrentUser()->GetID());		
		fingerprintApp::logManager.WriteToDatabase(msg1,"FINGERPRINT_ERROR");
		

        MakeLblGuideRed();
        /*myErrorCode = */m_axFPGetTemplateX->Cancel();
        FingerPrint::PlayFailedSound();
        NormalizeForm();
    }
}


System::Void frmVerify::NormalizeForm()
{
   this->m_statusBarLabel0->Text = L"Ready";
   this->m_txtKodeVerifikasi->Enabled = true;
   this->m_txtKodeVerifikasi->Text = L"";

    m_lblGuide->Text = L"Silahkan ketik kode verifikasi anda ( 4 angka )";
    m_numberOfTry = 0;
    m_currentUserDone = false;

    if (m_axFPGetTemplateX != nullptr)
    {   
        delete m_axFPGetTemplateX;
        InitFPGetTemplateX();
    }
    // set focus to txtKodeVerifikasi
    m_txtKodeVerifikasi->Select();
    MakeLblGuideNormal();
    SetStatusText(gcnew String(L"Ready"));
}

/*System::Windows::Forms::DialogResult*/ 
System::Void frmVerify::ShowFpMessageBox(System::String^ msg,System::String^ time)
{
	fpMessageBox^ mb = gcnew fpMessageBox();
	mb->SetMessage(msg);
	mb->SetTime(time);
	mb->ShowDialog(this);

	if ( mb->DialogResult == ::DialogResult::OK )
    {
		return;
	}
   else
      delete mb;
}

System::Void frmVerify::MakeLblGuideGreen()
{
    this->m_lblGuide->BackColor = System::Drawing::Color::LimeGreen;
    this->m_lblGuide->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->m_lblGuide->ForeColor = System::Drawing::SystemColors::ControlText;
}
System::Void frmVerify::MakeLblGuideRed()
{
    this->m_lblGuide->BackColor = System::Drawing::Color::Red;
    this->m_lblGuide->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,static_cast<System::Byte>(0)));
    this->m_lblGuide->ForeColor = System::Drawing::SystemColors::Info;
}
System::Void frmVerify::MakeLblGuideNormal()
{
    //this->m_lblGuide->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
    this->m_lblGuide->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224))); 
    this->m_lblGuide->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->m_lblGuide->ForeColor = System::Drawing::Color::DimGray;
}

System::Void frmVerify::SetStatusText(System::String^ status)
{
   this->m_statusBarLabel0->Text = status;
}

void frmVerify::SetTimeLabel(String^ time_label)
{
   this->lblTimeDigit->Text = time_label;
}
