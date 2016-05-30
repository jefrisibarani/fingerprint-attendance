/******************************************************************************
* filename : frmRegisterTemplate.cpp
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : Form registration fingerprint template definition
*
******************************************************************************/

#include "StdAfx.h"

#include "fingerprint.h"
#include "frmRegisterTemplate.h"
#include "fpUtils.h"
#include "utils.h"
#include "fpTable.h"

using namespace FingerPrint;
using namespace cli;
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
System::Void frmRegisterTemplate::frmRegisterTemplate_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
    FP_LOGMESSAGE("frmRegisterTemplate_KeyPress", LOG_DEBUG);
    if ( e->KeyChar == (char)13 )
    {
        FP_LOGMESSAGE("YOU PRESS ENTER", LOG_DEBUG);

    }
    else
        FP_LOGMESSAGE("YOU PRESS : " + e->KeyChar.ToString(), LOG_DEBUG);

    e->Handled = true;
}
System::Void frmRegisterTemplate::OnCmdNewUSer(System::Object^  sender, System::EventArgs^  e)
{
   InitializeMembers();
   InitFPRegisterTemplateX();
}
frmRegisterTemplate::frmRegisterTemplate(void)
{
	
   FP_LOGMESSAGE("Form daftar absen loading", LOG_DEBUG);

   InitializeComponent();
   
   m_updatingUser = false;
   InitializeMembers();

   InitFPRegisterTemplateX();
   
   // m_fingerCheckBoxArray must be initialized now
   m_fingerCheckBoxArray  = gcnew array<System::Windows::Forms::CheckBox^>(10);
   m_fingerCheckBoxArray[0] = this->m_chkLeftThumb;
   m_fingerCheckBoxArray[1] = this->m_chkLeftIndex;
   m_fingerCheckBoxArray[2] = this->m_chkLeftMiddle;
   m_fingerCheckBoxArray[3] = this->m_chkLeftRing;
   m_fingerCheckBoxArray[4] = this->m_chkLeftPinkie;
   m_fingerCheckBoxArray[5] = this->m_chkRightThumb;
   m_fingerCheckBoxArray[6] = this->m_chkRightIndex;
   m_fingerCheckBoxArray[7] = this->m_chkRightMiddle;
   m_fingerCheckBoxArray[8] = this->m_chkRightRing;
   m_fingerCheckBoxArray[9] = this->m_chkRightPinkie;

}
System::Void frmRegisterTemplate::InitializeMembers(void)
{

   this->m_btnEditCode->Hide();

   this->cmdSaveData->Enabled = false;
   txtNamaKaryawan->Select();
   txtKodeKaryawan->Enabled = false;
   txtKodeKaryawan->Enabled = false;

   m_currentFinger = nullptr;
   m_lblGuide->Text=String::Empty;

   m_overtime = String::Empty;
   userToEdit = nullptr;
   employeeCode = String::Empty;
   verificationCode = String::Empty;
   namaKaryawan = String::Empty;
   device_sn = String::Empty;
   currentTime = String::Empty;
   operatorName = String::Empty;

   // this array must be initilized now
   m_FPTemplateStringArray = gcnew array<String^>(10);
   m_FPTemplateStringArray[0] = String::Empty;
   m_FPTemplateStringArray[1] = String::Empty;
   m_FPTemplateStringArray[2] = String::Empty;
   m_FPTemplateStringArray[3] = String::Empty;
   m_FPTemplateStringArray[4] = String::Empty;
   m_FPTemplateStringArray[5] = String::Empty;
   m_FPTemplateStringArray[6] = String::Empty;
   m_FPTemplateStringArray[7] = String::Empty;
   m_FPTemplateStringArray[8] = String::Empty;
   m_FPTemplateStringArray[9] = String::Empty;

   this->txtNamaKaryawan->Text = String::Empty;
   this->txtKodeKaryawan->Text = String::Empty;
   this->txtVerificationCode->Text = String::Empty;
   this->m_txtPassword->Text = String::Empty;
   this->m_txtStartWorkhour->Text = String::Empty;
   this->m_txtEndWorkHour->Text = String::Empty;
   this->m_txtInGreeting->Text = String::Empty;
   this->m_txtOutGreeting->Text = String::Empty;

   this->m_chkUseGlobalGreeting->Checked = true;
   this->m_chkUseGlobalWorkhour->Checked = true;

   this->m_lblVerifyCodeOK->Text = L"...";   

    
   this->m_chkLeftIndex->Enabled = true;
   this->m_chkLeftMiddle->Enabled = true;
   this->m_chkLeftPinkie->Enabled = true;
   this->m_chkLeftRing->Enabled = true;
   this->m_chkLeftThumb->Enabled = true;
   this->m_chkRightIndex->Enabled = true;
   this->m_chkRightMiddle->Enabled = true;
   this->m_chkRightPinkie->Enabled = true;
   this->m_chkRightRing->Enabled = true;
   this->m_chkRightThumb->Enabled = true;

   this->m_chkLeftIndex->Checked = false;
   this->m_chkLeftMiddle->Checked = false;
   this->m_chkLeftPinkie->Checked = false;;
   this->m_chkLeftRing->Checked = false;
   this->m_chkLeftThumb->Checked = false;
   this->m_chkRightIndex->Checked = false;
   this->m_chkRightMiddle->Checked = false;
   this->m_chkRightPinkie->Checked = false;
   this->m_chkRightRing->Checked = false;
   this->m_chkRightThumb->Checked = false;

}
void frmRegisterTemplate::InitControlsFromDB(System::String^ userID)
{
	try
	{
		m_updatingUser = true;

		this->m_btnEditCode->Show();
		this->m_btnEditCode->Enabled = true;

		this->lblJudul->Text = "Edit User";
		this->m_cmdNewUser->Hide();
		//this->txtVerificationCode->Enabled = false;

		/*fpUser^ */userToEdit = gcnew fpUser();
		userToEdit->InitFromDB(userID);


		this->m_cmdReset->Enabled = false;
		this->cmdSaveData->Enabled = true;
		txtNamaKaryawan->Select();
		m_currentFinger = nullptr;
		m_lblGuide->Text=String::Empty;

		//init template array from database
		m_FPTemplateStringArray = userToEdit->GetFPTemplateArrayString();

		// fill other controls value
		this->txtNamaKaryawan->Text = userToEdit->GetName();
		this->txtKodeKaryawan->Text = userToEdit->GetID();
		this->txtVerificationCode->Text = userToEdit->GetVerifyCode();
		this->m_txtPassword->Text = userToEdit->GetPassword();
		this->m_txtStartWorkhour->Text = userToEdit->GetStartWorkHour();
		this->m_txtEndWorkHour->Text = userToEdit->GetEndWorkHour();
		this->m_txtInGreeting->Text = userToEdit->GetInGreeting();
		this->m_txtOutGreeting->Text = userToEdit->GetOutGreeting();
		this->m_cbOvertime->Text = userToEdit->GetOvertimeMode();

		if ( String::IsNullOrEmpty(userToEdit->GetInGreeting()) )
		  this->m_chkUseGlobalGreeting->Checked = true;
		else
		  this->m_chkUseGlobalGreeting->Checked = false;

		if ( String::IsNullOrEmpty(userToEdit->GetStartWorkHour()) )
		  this->m_chkUseGlobalWorkhour->Checked = true;
		else
		  this->m_chkUseGlobalWorkhour->Checked = false;

		this->m_lblVerifyCodeOK->Text = L"";   

		// set all check control to checked
		this->m_chkLeftIndex->Checked = true;
		this->m_chkLeftMiddle->Checked = true;
		this->m_chkLeftPinkie->Checked = true;;
		this->m_chkLeftRing->Checked = true;
		this->m_chkLeftThumb->Checked = true;
		this->m_chkRightIndex->Checked = true;
		this->m_chkRightMiddle->Checked = true;
		this->m_chkRightPinkie->Checked = true;
		this->m_chkRightRing->Checked = true;
		this->m_chkRightThumb->Checked = true;


		// then set the correct state based on fingerprint template value
		if ( String::IsNullOrEmpty(m_FPTemplateStringArray[0] ) )
			 this->m_chkLeftThumb->Checked = false;

		if ( String::IsNullOrEmpty(m_FPTemplateStringArray[1]) )
			 this->m_chkLeftIndex->Checked = false;

		if ( String::IsNullOrEmpty(m_FPTemplateStringArray[2]) )
			  this->m_chkLeftMiddle->Checked = false;

		if ( String::IsNullOrEmpty(m_FPTemplateStringArray[3]) )
			 this->m_chkLeftRing->Checked = false;

		if ( String::IsNullOrEmpty(m_FPTemplateStringArray[4]) )
			 this->m_chkLeftPinkie->Checked = false;

		if ( String::IsNullOrEmpty(m_FPTemplateStringArray[5]) )
			 this->m_chkRightThumb->Checked = false;

		if ( String::IsNullOrEmpty(m_FPTemplateStringArray[6]) )
			 this->m_chkRightIndex->Checked = false;

		if ( String::IsNullOrEmpty(m_FPTemplateStringArray[7]) )
			 this->m_chkRightMiddle->Checked = false;

		if ( String::IsNullOrEmpty(m_FPTemplateStringArray[8]) )
			 this->m_chkRightRing->Checked = false;

		if ( String::IsNullOrEmpty(m_FPTemplateStringArray[9]) )
			 this->m_chkRightPinkie->Checked = false;

	}
	catch (Exception ^e)
    {
      FP_LOGMESSAGE(e->ToString());
    }

}


System::Void frmRegisterTemplate::frmRegisterTemplate_Load(System::Object^  sender, System::EventArgs^  e)
{

}

System::Void frmRegisterTemplate::m_axFPRegisterTemplateX_Done(System::Object^  sender, AxDPSDKOPSLib::_IFPRegisterTemplateXEvents_DoneEvent^  e)
{

    FP_LOGMESSAGE("frmRegisterTemplate::m_axFPRegisterTemplateX_Done():event Register Template Done ", LOG_DEBUG);

    // get the template
    DpSdkEngLib::FPTemplate^ newTemplate = (DpSdkEngLib::FPTemplate^)e->pTemplate;

    // convert newTemplate to string and put in array
    m_FPTemplateStringArray[m_currentFinger->GetInt()] = FPTemplateToHexString(newTemplate);

    FP_LOGMESSAGE("Security mode : " + SecureModeToString(newTemplate->SecureMode) );
    FP_LOGMESSAGE("Template ID   : " + newTemplate->InstanceID);
    FP_LOGMESSAGE("Version       : " + newTemplate->Version);
    FP_LOGMESSAGE("Vendor        : " + newTemplate->VendorID);

    FP_LOGMESSAGE(String::Format("Data Types    : {0}",(int)newTemplate->TypeID ));
    FP_LOGMESSAGE(String::Format("Template Types: {0}",(int)newTemplate->TemplType ));

    m_fingerCheckBoxArray[m_currentFinger->GetInt()]->Enabled = false; 
    this->cmdSaveData->Enabled = true; 
}
//-----------------------------------------------------------------------------------------------------------------------------------
System::Void frmRegisterTemplate::cmdSaveData_Click(System::Object^  sender, System::EventArgs^  e)
{
   MessageBoxButtons buttons = MessageBoxButtons::YesNo;
   System::Windows::Forms::DialogResult result;
   // Displays the MessageBox.
   result = MessageBox::Show( this, "Are you sure you want to save the data", "Attention", buttons );
   if ( result == ::DialogResult::Yes )
   {
      if ( !m_updatingUser ) 
         FP_LOGMESSAGE("frmRegisterTemplate::cmdSaveData_Click() :Saving Template Data", LOG_INFO);
      else
         FP_LOGMESSAGE("frmRegisterTemplate::cmdSaveData_Click() :Updating Template Data", LOG_INFO);
    
      this->statusBar_0->Text = L"  Ready ";

      // prepare a stopwatch to measure the process
      System::Diagnostics::Stopwatch^ stopWatch = gcnew Stopwatch();
      stopWatch->Reset();
      stopWatch->Start();

      this->namaKaryawan = this->txtNamaKaryawan->Text;
      FP_LOGMESSAGE(namaKaryawan, LOG_DEBUG);
   
      this->employeeCode = this->txtKodeKaryawan->Text;
      FP_LOGMESSAGE(employeeCode, LOG_DEBUG);
   
      this->verificationCode = this->txtVerificationCode->Text;
      FP_LOGMESSAGE(verificationCode, LOG_DEBUG);
   
      this->operatorName = Environment::UserName;
      FP_LOGMESSAGE(operatorName, LOG_DEBUG);
   
      this->currentTime = GetTimeStamp(L"F");
      FP_LOGMESSAGE(currentTime, LOG_DEBUG);
   
      this->device_sn = fingerprintApp::GetDevice()->SerialNumber;
      FP_LOGMESSAGE(device_sn, LOG_DEBUG);
   
      if ( !m_updatingUser ) // we are creating new user
      {
         fpUser^ currentUser = gcnew fpUser();
         currentUser->CreateNew( namaKaryawan,
                           employeeCode,
                           verificationCode,
                           this->m_txtPassword->Text,
                           m_FPTemplateStringArray,
                           this->m_txtStartWorkhour->Text,
                           this->m_txtEndWorkHour->Text,
                           this->m_txtInGreeting->Text,
                           this->m_txtOutGreeting->Text,
                           this->m_overtime
                        );
   
       
         if( currentUser->Register() )
         {
            /// We need to stop the stopwatch and retrieve the result
            stopWatch->Stop();
            TimeSpan ts = stopWatch->Elapsed;
            String ^statusBarText = String::Format( "{0:00}:{1:00}:{2:00}.{3:00}", ts.Hours, ts.Minutes, ts.Seconds, ts.Milliseconds / 10 );
            this->statusBar_0->Text = String::Concat("data sidik jari tersimpan dalam waktu ", statusBarText);

           
            // Create user absen table to in database
            currentUser->CreateAbsenTable();    
            UpdateForm();

            m_axFPRegisterTemplateX->SetDevicePriority(DPSDKOPSLib::AIDevPriorities::Dp_StdPriority, this->Handle.ToInt32());
            m_axFPRegisterTemplateX->CreateOp();
         }
      }
      else // we are updating user
      {
            //userToEdit->SetVerifyCode(verificationCode);
            userToEdit->SetInGreeting(this->m_txtInGreeting->Text);
            userToEdit->SetOutGreeting(this->m_txtOutGreeting->Text);
            userToEdit->SetFingersTemplate(m_FPTemplateStringArray);
            if ( userToEdit->Update() )
               MessageBox::Show( "Data updated successfully" );
            else
               FP_LOGMESSAGE("Data couldn't updated", LOG_ERROR);
      
            // disable this form
            this->cmdSaveData->Enabled = false;
            this->m_cmdCancel->Text = "Close";
    
      }
   }
   else
      return;
 
}
System::Void frmRegisterTemplate::InitFPRegisterTemplateX()
{
    FP_LOGMESSAGE( "Loading FPRegisterTemplateX" );
	try
	{
		this->SuspendLayout();

		if( m_axFPRegisterTemplateX != nullptr )
		delete m_axFPRegisterTemplateX;

		m_axFPRegisterTemplateX = nullptr;


		m_axFPRegisterTemplateX = (gcnew AxDPSDKOPSLib::AxFPRegisterTemplateX());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_axFPRegisterTemplateX))->BeginInit();

		m_axFPRegisterTemplateX->Enabled = true;
		m_axFPRegisterTemplateX->Location = System::Drawing::Point(3, 5);
		m_axFPRegisterTemplateX->MaximumSize = System::Drawing::Size(500, 276);
		m_axFPRegisterTemplateX->MinimumSize = System::Drawing::Size(500, 276);
		m_axFPRegisterTemplateX->Name = L"m_axFPRegisterTemplateX";
		//this->m_axFPRegisterTemplateX->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^  >(resources->GetObject(L"m_axFPRegisterTemplateX.OcxState")));
		m_axFPRegisterTemplateX->Size = System::Drawing::Size(504, 281);
		m_axFPRegisterTemplateX->TabIndex = 0;
		m_axFPRegisterTemplateX->Done += gcnew AxDPSDKOPSLib::_IFPRegisterTemplateXEvents_DoneEventHandler(this, &frmRegisterTemplate::m_axFPRegisterTemplateX_Done);
		m_tabPageFingerRegistration->Controls->Add(this->m_axFPRegisterTemplateX);
		//this->Controls->Add(this->m_axFPRegisterTemplateX);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_axFPRegisterTemplateX))->EndInit();

		this->PerformLayout();
	}
    catch (Exception ^e)
    {
      FP_LOGMESSAGE(e->ToString());
    }
}

System::Void frmRegisterTemplate::RunFPRegisterTemplateX()
{
   
    DPSDKOPSLib::AIErrors myErrorCode;
    
    myErrorCode = m_axFPRegisterTemplateX->SetDevicePriority(DPSDKOPSLib::AIDevPriorities::Dp_StdPriority, this->Handle.ToInt32());
    FP_LOGMESSAGE("m_axFPRegisterTemplateX->SetDevicePriority() ");

    String ^errmsg = AIErrorsToString( (DpSdkEngLib::AIErrors)myErrorCode ) ;
    FP_LOGMESSAGE("Device Error Message : " + errmsg );

    myErrorCode = m_axFPRegisterTemplateX->CreateOp();
    FP_LOGMESSAGE("m_axFPRegisterTemplateX->CreateOp()             ");
    errmsg = AIErrorsToString( (DpSdkEngLib::AIErrors)myErrorCode ) ;
    FP_LOGMESSAGE("Device Error Message : " + errmsg );

    myErrorCode = m_axFPRegisterTemplateX->Run();
    FP_LOGMESSAGE("m_axFPRegisterTemplateX->Run()                     ");

    errmsg = AIErrorsToString( (DpSdkEngLib::AIErrors)myErrorCode ) ;
    FP_LOGMESSAGE("Device Error Message : " + errmsg );

}
System::Void frmRegisterTemplate::UpdateForm()
{
      this->cmdSaveData->Enabled = false;
      ResetForm();
}
System::Void frmRegisterTemplate::ResetForm()
{
   this->m_lblGuide->Text=L"";

   this->txtKodeKaryawan->Clear();
   this->txtNamaKaryawan->Clear();
   this->txtVerificationCode->Clear();
   this->m_lblVerifyCodeOK->Text = String::Empty;
   
   this->m_txtEndWorkHour->Clear();
   this->m_txtStartWorkhour->Clear();
   this->m_txtInGreeting->Clear();
   this->m_txtOutGreeting->Clear();
   this->m_txtPassword->Clear();

   this->m_chkUseGlobalGreeting->Checked = true;
   this->m_chkUseGlobalWorkhour->Checked = true;

   this->m_lblVerifyCodeOK->Text = L"";
}
System::Void frmRegisterTemplate::DoRegisterUser(/*FingerPrint::*/fpFingerEnum fingerToUSe)
{
   this->cmdSaveData->Enabled = true; 

   if(m_currentFinger != nullptr )
      delete m_currentFinger;
   m_currentFinger = nullptr;

   m_currentFinger = gcnew fpFinger(fingerToUSe);
   m_lblGuide->Text = String::Concat("Silahkan letakkan jari ",m_currentFinger->GetString()," pada sensor");
   RunFPRegisterTemplateX();

}

// Left Thumb
System::Void frmRegisterTemplate::OnChkLeftThumbCheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
   if( this->m_chkLeftThumb->Checked )
      DoRegisterUser(FP_LEFT_THUMB);
}

// Left Index
System::Void frmRegisterTemplate::OnChkLeftIndexCheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
   if ( this->m_chkLeftIndex->Checked )
      DoRegisterUser(FP_LEFT_INDEX);         
}

// Left Middle
System::Void frmRegisterTemplate::OnChkLeftMiddleCheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
   if ( this->m_chkLeftMiddle->Checked )
      DoRegisterUser(FP_LEFT_MIDDLE);
}

// Left Ring
System::Void frmRegisterTemplate::OnChkLeftRingCheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
   if ( this->m_chkLeftRing->Checked )
      DoRegisterUser(FP_LEFT_RING);
}

// Left Pinkie
System::Void frmRegisterTemplate::OnChkLeftPinkieCheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
   if ( this->m_chkLeftPinkie->Checked )
      DoRegisterUser(FP_LEFT_PINKIE);
}

// Right Thumb
System::Void frmRegisterTemplate::OnChkRightThumbCheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
   if ( this->m_chkRightThumb->Checked )
      DoRegisterUser(FP_RIGHT_THUMB);
}

// Right Index
System::Void frmRegisterTemplate::OnChkRightIndexCheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
   if ( this->m_chkRightIndex->Checked )
      DoRegisterUser(FP_RIGHT_INDEX);
}

// Right Middle
System::Void frmRegisterTemplate::OnChkRightMiddleCheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
   if ( this->m_chkRightMiddle->Checked )
      DoRegisterUser(FP_RIGHT_MIDDLE);
}

// Right Ring
System::Void frmRegisterTemplate::OnChkRightRingCheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
   if ( this->m_chkRightRing->Checked )
      DoRegisterUser(FP_RIGHT_RING);
}

// Right Pinkie
System::Void frmRegisterTemplate::OnChkRightPinkieCheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
   if ( this->m_chkRightPinkie->Checked )
      DoRegisterUser(FP_RIGHT_PINKIE);
}


System::Void frmRegisterTemplate::OnchkUseGlobalGreetingCheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
   if( !this->m_chkUseGlobalGreeting->Checked )
   {     
      this->m_txtInGreeting->Enabled = true;
      this->m_txtOutGreeting->Enabled = true;
   }
   else
   {     
      this->m_txtInGreeting->Enabled = false;
      this->m_txtOutGreeting->Enabled = false;
   }
}
System::Void frmRegisterTemplate::OnchkUseGlobalWorkhourCheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
   if ( !this->m_chkUseGlobalWorkhour->Checked )
   {
      this->m_txtEndWorkHour->Enabled = true;
      this->m_txtStartWorkhour->Enabled = true;
   }
   else
   {
      this->m_txtEndWorkHour->Enabled = false;
      this->m_txtStartWorkhour->Enabled = false;
   }
}

System::Void frmRegisterTemplate::OnCmdResetClick(System::Object^  sender, System::EventArgs^  e)
{
   ResetForm();
}


System::Void frmRegisterTemplate::OnTabPageSelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{


}

System::Void frmRegisterTemplate::OnCmdCheckCodeClick(System::Object^  sender, System::EventArgs^  e)
{
   CheckVerifyCode();
}
System::Void frmRegisterTemplate::OntxtVerificationCodeKeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
    // Only act if Enter pressed
    if ( e->KeyChar == (char)13 )
    {
         CheckVerifyCode();
         e->Handled = true;
    }
    else
       return;
}
System::Void frmRegisterTemplate::CheckVerifyCode()
{
   if ( this->txtVerificationCode->Text == String::Empty )
      return;

   String^ sql;
   sql += "SELECT verification_code FROM fp_template WHERE verification_code = '";
   sql += this->txtVerificationCode->Text;
   sql += "'";

   if ( !IsNumber( this->txtVerificationCode->Text)  )
   {
           MessageBox::Show( "\n" + "Kode Verifikasi angka",
                             "Informasi",
                             MessageBoxButtons::OK,
                             MessageBoxIcon::Information );

      this->txtVerificationCode->Text = String::Empty;
      this->txtVerificationCode->Select();
      this->m_lblVerifyCodeOK->Text = L"";        
   
   }else
   if ( this->txtVerificationCode->Text->Length < 4 )
   {
           MessageBox::Show( "\n" + "Kode Verifikasi harus 4 angka",
                             "Informasi",
                             MessageBoxButtons::OK,
                             MessageBoxIcon::Information );

      this->txtVerificationCode->Text = String::Empty;
      this->txtVerificationCode->Select();
      this->m_lblVerifyCodeOK->Text = L"";
   } 
   else
   if ( fingerprintApp::GetConnection()->ExecuteVoid(sql) )
   {  
      MessageBox::Show( "Verification Code exists.\n  Please use another code  ",
                                   "WARNING",
                                   MessageBoxButtons::OK,
                                   MessageBoxIcon::Stop );
        
      this->txtVerificationCode->Text = String::Empty;
      this->txtVerificationCode->Select();
      this->m_lblVerifyCodeOK->Text = L"";
   }
   else
      this->m_lblVerifyCodeOK->Text = L"OK";
}

System::Void frmRegisterTemplate::OnTxtNamaKaryawanLeave(System::Object^  sender, System::EventArgs^  e)
{
   
   if ( this->txtNamaKaryawan->Text->Equals(String::Empty) )
   {   
      MessageBox::Show( "You have to type user name.\n    ",
                                   "WARNING",
                                   MessageBoxButtons::OK,
                                   MessageBoxIcon::Stop );
      this->txtNamaKaryawan->Select();
   }
   else
      txtKodeKaryawan->Enabled = true;

   
   
}
System::Void frmRegisterTemplate::OnTxtKodeKaryawanLeave(System::Object^  sender, System::EventArgs^  e)
{
   
   if ( this->txtKodeKaryawan->Text->Equals(String::Empty) )
   {
      MessageBox::Show( "You have to type user code .\n    ",
                                   "WARNING",
                                   MessageBoxButtons::OK,
                                   MessageBoxIcon::Stop );

      this->txtKodeKaryawan->Select();
   }
   else
      txtKodeKaryawan->Enabled = true;
   
}
System::Void frmRegisterTemplate::OnTxtVerificationCodeLeave(System::Object^  sender, System::EventArgs^  e)
{

   CheckVerifyCode();

}

System::Void frmRegisterTemplate::OnOvertimeSelected(System::Object^  sender, System::EventArgs^  e)
{
   int selectedIndex = m_cbOvertime->SelectedIndex;
   Object^ selectedItem = m_cbOvertime->SelectedItem;
   m_overtime = selectedItem->ToString();
   if ( m_overtime == nullptr )
      m_overtime = String::Empty;
   //m_selectedID = m_userIDArray[selectedIndex];
   
   FP_LOGMESSAGE(String::Concat("Overtime: " ,m_overtime ));
}


void frmRegisterTemplate::DisableSomeControls()
{
	this->m_tabPageGeneral->Enabled = false;
	this->m_tabPageOption->Enabled = false;
	this->m_tabPageFingerRegistration->Enabled = false;
	this->cmdSaveData->Enabled = false;
}

System::Void frmRegisterTemplate::OnBtnEditCode(System::Object^  sender, System::EventArgs^  e)
{
   this->txtVerificationCode->Enabled = true;
}