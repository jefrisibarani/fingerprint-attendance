/*****************************************************************************
* filename : frmRegisterTemplate.h
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : fingerprint template registration form
*
*****************************************************************************/
#pragma once
#include "fpUser.h"
#include "fpFinger.h"



//namespace FingerPrint {

	/// <summary>
	/// Summary for frmAbsen
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class frmRegisterTemplate : public System::Windows::Forms::Form
	{
	public:
		frmRegisterTemplate(void);
      System::Void InitializeMembers(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmRegisterTemplate()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  lblJudul;

	private: System::Windows::Forms::Button^  cmdSaveData;
	protected: 
	private: AxDPSDKOPSLib::AxFPRegisterTemplateX^  m_axFPRegisterTemplateX;
   private: DpSdkEngLib::FPTemplate^ myTemplate;     // JS: pointer to generated template
   private: DpSdkEngLib::FPDevice^ myDevice;         // JS: pointer to the selected device
   private: DpSdkEngLib::FPDevices^ myDevicesList;   // JS: device manager object
	   
   
   /**
     This three item closely  related each other.
     They share the same finger structure, based on fpFingerEnum enumeration declared
     in fpFinger.h.
     
     ex.
     m_FPTemplateStringArray[m_currentFinger->GetInt()]  is equal to get fingerprint template
     at specified posistion in m_currentFinger.
     while m_currentFinger->GetString() will tell us what finger it.
            
   */
   /// Current finger to be scanned.
   private: FingerPrint::fpFinger^ m_currentFinger;
   /// Fingerprint template array.
   private: cli::array<System::String^>^ m_FPTemplateStringArray;
   /// Array of fingerprint selection operation checkbox.
   private: cli::array<System::Windows::Forms::CheckBox^>^ m_fingerCheckBoxArray;
   
   private: System::String^ m_overtime;
   private: FingerPrint::fpUser ^userToEdit;
   private: bool m_updatingUser;
   private: System::String ^employeeCode;
   private: System::String ^verificationCode;
   private: System::String ^namaKaryawan;
   private: System::String ^device_sn;
   private: System::String ^currentTime;
   private: System::String ^operatorName;

   private: System::Windows::Forms::StatusStrip^  statusBar;
   private: System::Windows::Forms::ToolStripStatusLabel^  statusBar_0;

   private: System::Windows::Forms::Label^  m_lblGuide;
   private: System::Windows::Forms::TabPage^  m_tabPageFingerRegistration;
   private: System::Windows::Forms::GroupBox^  m_grpBoxRightHand;
   private: System::Windows::Forms::CheckBox^  m_chkRightPinkie;
   private: System::Windows::Forms::CheckBox^  m_chkRightRing;
   private: System::Windows::Forms::CheckBox^  m_chkRightMiddle;
   private: System::Windows::Forms::CheckBox^  m_chkRightIndex;
   private: System::Windows::Forms::CheckBox^  m_chkRightThumb;
   private: System::Windows::Forms::GroupBox^  m_grpBoxLeftHand;
   private: System::Windows::Forms::CheckBox^  m_chkLeftPinkie;
   private: System::Windows::Forms::CheckBox^  m_chkLeftRing;
   private: System::Windows::Forms::CheckBox^  m_chkLeftMiddle;
   private: System::Windows::Forms::CheckBox^  m_chkLeftIndex;
   private: System::Windows::Forms::CheckBox^  m_chkLeftThumb;
   private: System::Windows::Forms::TabPage^  m_tabPageOption;
   private: System::Windows::Forms::TabPage^  m_tabPageGeneral;
   private: System::Windows::Forms::Button^  m_cmdReset;
   private: System::Windows::Forms::Label^  label2;
   private: System::Windows::Forms::TextBox^  m_txtOutGreeting;
   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::TextBox^  m_txtInGreeting;
   private: System::Windows::Forms::Label^  lblNamaKaryawan;
   private: System::Windows::Forms::Label^  lblKodeKaryawan;
   private: System::Windows::Forms::TextBox^  txtNamaKaryawan;
   private: System::Windows::Forms::TextBox^  txtKodeKaryawan;
   private: System::Windows::Forms::TextBox^  txtVerificationCode;
   private: System::Windows::Forms::Label^  lblVerificationCode;
   private: System::Windows::Forms::TabControl^  m_tabPage;
   private: System::Windows::Forms::Button^  m_cmdCancel;
   private: System::Windows::Forms::Button^  m_cmdNewUser;
   private: System::Windows::Forms::Label^  label4;
   private: System::Windows::Forms::TextBox^  m_txtEndWorkHour;

   private: System::Windows::Forms::Label^  label5;
   private: System::Windows::Forms::TextBox^  m_txtStartWorkhour;

   private: System::Windows::Forms::TextBox^  m_txtPassword;
   private: System::Windows::Forms::Label^  label3;
   private: System::Windows::Forms::CheckBox^  m_chkUseGlobalGreeting;
   private: System::Windows::Forms::CheckBox^  m_chkUseGlobalWorkhour;
private: System::Windows::Forms::Button^  m_cmdCheckCode;
private: System::Windows::Forms::Label^  m_lblVerifyCodeOK;


   private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::ComboBox^  m_cbOvertime;
private: System::Windows::Forms::Button^  m_btnEditCode;




            /// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
         this->lblJudul = (gcnew System::Windows::Forms::Label());
         this->cmdSaveData = (gcnew System::Windows::Forms::Button());
         this->statusBar = (gcnew System::Windows::Forms::StatusStrip());
         this->statusBar_0 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
         this->m_lblGuide = (gcnew System::Windows::Forms::Label());
         this->m_tabPageFingerRegistration = (gcnew System::Windows::Forms::TabPage());
         this->m_grpBoxRightHand = (gcnew System::Windows::Forms::GroupBox());
         this->m_chkRightPinkie = (gcnew System::Windows::Forms::CheckBox());
         this->m_chkRightRing = (gcnew System::Windows::Forms::CheckBox());
         this->m_chkRightMiddle = (gcnew System::Windows::Forms::CheckBox());
         this->m_chkRightIndex = (gcnew System::Windows::Forms::CheckBox());
         this->m_chkRightThumb = (gcnew System::Windows::Forms::CheckBox());
         this->m_grpBoxLeftHand = (gcnew System::Windows::Forms::GroupBox());
         this->m_chkLeftPinkie = (gcnew System::Windows::Forms::CheckBox());
         this->m_chkLeftRing = (gcnew System::Windows::Forms::CheckBox());
         this->m_chkLeftMiddle = (gcnew System::Windows::Forms::CheckBox());
         this->m_chkLeftIndex = (gcnew System::Windows::Forms::CheckBox());
         this->m_chkLeftThumb = (gcnew System::Windows::Forms::CheckBox());
         this->m_tabPageOption = (gcnew System::Windows::Forms::TabPage());
         this->m_cbOvertime = (gcnew System::Windows::Forms::ComboBox());
         this->label6 = (gcnew System::Windows::Forms::Label());
         this->m_chkUseGlobalWorkhour = (gcnew System::Windows::Forms::CheckBox());
         this->label4 = (gcnew System::Windows::Forms::Label());
         this->m_txtEndWorkHour = (gcnew System::Windows::Forms::TextBox());
         this->label5 = (gcnew System::Windows::Forms::Label());
         this->m_txtStartWorkhour = (gcnew System::Windows::Forms::TextBox());
         this->m_txtPassword = (gcnew System::Windows::Forms::TextBox());
         this->label3 = (gcnew System::Windows::Forms::Label());
         this->m_tabPageGeneral = (gcnew System::Windows::Forms::TabPage());
         this->m_btnEditCode = (gcnew System::Windows::Forms::Button());
         this->m_lblVerifyCodeOK = (gcnew System::Windows::Forms::Label());
         this->m_cmdCheckCode = (gcnew System::Windows::Forms::Button());
         this->m_chkUseGlobalGreeting = (gcnew System::Windows::Forms::CheckBox());
         this->m_cmdReset = (gcnew System::Windows::Forms::Button());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->m_txtOutGreeting = (gcnew System::Windows::Forms::TextBox());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->m_txtInGreeting = (gcnew System::Windows::Forms::TextBox());
         this->lblNamaKaryawan = (gcnew System::Windows::Forms::Label());
         this->lblKodeKaryawan = (gcnew System::Windows::Forms::Label());
         this->txtNamaKaryawan = (gcnew System::Windows::Forms::TextBox());
         this->txtKodeKaryawan = (gcnew System::Windows::Forms::TextBox());
         this->txtVerificationCode = (gcnew System::Windows::Forms::TextBox());
         this->lblVerificationCode = (gcnew System::Windows::Forms::Label());
         this->m_tabPage = (gcnew System::Windows::Forms::TabControl());
         this->m_cmdCancel = (gcnew System::Windows::Forms::Button());
         this->m_cmdNewUser = (gcnew System::Windows::Forms::Button());
         this->statusBar->SuspendLayout();
         this->m_tabPageFingerRegistration->SuspendLayout();
         this->m_grpBoxRightHand->SuspendLayout();
         this->m_grpBoxLeftHand->SuspendLayout();
         this->m_tabPageOption->SuspendLayout();
         this->m_tabPageGeneral->SuspendLayout();
         this->m_tabPage->SuspendLayout();
         this->SuspendLayout();
         // 
         // lblJudul
         // 
         this->lblJudul->BackColor = System::Drawing::SystemColors::ControlDark;
         this->lblJudul->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->lblJudul->ForeColor = System::Drawing::SystemColors::Info;
         this->lblJudul->Location = System::Drawing::Point(0, 0);
         this->lblJudul->Margin = System::Windows::Forms::Padding(0);
         this->lblJudul->Name = L"lblJudul";
         this->lblJudul->Size = System::Drawing::Size(612, 22);
         this->lblJudul->TabIndex = 200;
         this->lblJudul->Text = L"Pendaftaran User";
         this->lblJudul->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
         // 
         // cmdSaveData
         // 
         this->cmdSaveData->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
         this->cmdSaveData->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
         this->cmdSaveData->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->cmdSaveData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->cmdSaveData->Location = System::Drawing::Point(356, 417);
         this->cmdSaveData->Name = L"cmdSaveData";
         this->cmdSaveData->Size = System::Drawing::Size(129, 31);
         this->cmdSaveData->TabIndex = 8;
         this->cmdSaveData->Text = L"Simpan Data";
         this->cmdSaveData->UseVisualStyleBackColor = true;
         this->cmdSaveData->Click += gcnew System::EventHandler(this, &frmRegisterTemplate::cmdSaveData_Click);
         // 
         // statusBar
         // 
         this->statusBar->GripMargin = System::Windows::Forms::Padding(0);
         this->statusBar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->statusBar_0});
         this->statusBar->Location = System::Drawing::Point(0, 457);
         this->statusBar->Name = L"statusBar";
         this->statusBar->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
         this->statusBar->Size = System::Drawing::Size(606, 22);
         this->statusBar->SizingGrip = false;
         this->statusBar->Stretch = false;
         this->statusBar->TabIndex = 8;
         // 
         // statusBar_0
         // 
         this->statusBar_0->BorderSides = System::Windows::Forms::ToolStripStatusLabelBorderSides::Top;
         this->statusBar_0->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->statusBar_0->ForeColor = System::Drawing::Color::Red;
         this->statusBar_0->Margin = System::Windows::Forms::Padding(0);
         this->statusBar_0->Name = L"statusBar_0";
         this->statusBar_0->Size = System::Drawing::Size(591, 22);
         this->statusBar_0->Spring = true;
         this->statusBar_0->Text = L"Ready...";
         // 
         // m_lblGuide
         // 
         this->m_lblGuide->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)));
         this->m_lblGuide->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_lblGuide->ForeColor = System::Drawing::SystemColors::Desktop;
         this->m_lblGuide->Location = System::Drawing::Point(0, 22);
         this->m_lblGuide->Margin = System::Windows::Forms::Padding(0);
         this->m_lblGuide->Name = L"m_lblGuide";
         this->m_lblGuide->Size = System::Drawing::Size(612, 71);
         this->m_lblGuide->TabIndex = 203;
         this->m_lblGuide->Text = L"Guide";
         this->m_lblGuide->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
         // 
         // m_tabPageFingerRegistration
         // 
         this->m_tabPageFingerRegistration->Controls->Add(this->m_grpBoxRightHand);
         this->m_tabPageFingerRegistration->Controls->Add(this->m_grpBoxLeftHand);
         this->m_tabPageFingerRegistration->Location = System::Drawing::Point(4, 25);
         this->m_tabPageFingerRegistration->Name = L"m_tabPageFingerRegistration";
         this->m_tabPageFingerRegistration->Padding = System::Windows::Forms::Padding(3);
         this->m_tabPageFingerRegistration->Size = System::Drawing::Size(604, 286);
         this->m_tabPageFingerRegistration->TabIndex = 4;
         this->m_tabPageFingerRegistration->Text = L"Fingerprint Registration";
         this->m_tabPageFingerRegistration->UseVisualStyleBackColor = true;
         // 
         // m_grpBoxRightHand
         // 
         this->m_grpBoxRightHand->Controls->Add(this->m_chkRightPinkie);
         this->m_grpBoxRightHand->Controls->Add(this->m_chkRightRing);
         this->m_grpBoxRightHand->Controls->Add(this->m_chkRightMiddle);
         this->m_grpBoxRightHand->Controls->Add(this->m_chkRightIndex);
         this->m_grpBoxRightHand->Controls->Add(this->m_chkRightThumb);
         this->m_grpBoxRightHand->Location = System::Drawing::Point(512, 149);
         this->m_grpBoxRightHand->Name = L"m_grpBoxRightHand";
         this->m_grpBoxRightHand->Size = System::Drawing::Size(83, 135);
         this->m_grpBoxRightHand->TabIndex = 5;
         this->m_grpBoxRightHand->TabStop = false;
         this->m_grpBoxRightHand->Text = L"Right Hand";
         // 
         // m_chkRightPinkie
         // 
         this->m_chkRightPinkie->AutoSize = true;
         this->m_chkRightPinkie->Location = System::Drawing::Point(6, 107);
         this->m_chkRightPinkie->Name = L"m_chkRightPinkie";
         this->m_chkRightPinkie->Size = System::Drawing::Size(55, 17);
         this->m_chkRightPinkie->TabIndex = 4;
         this->m_chkRightPinkie->Text = L"Pinkie";
         this->m_chkRightPinkie->UseVisualStyleBackColor = true;
         this->m_chkRightPinkie->CheckedChanged += gcnew System::EventHandler(this, &frmRegisterTemplate::OnChkRightPinkieCheckedChanged);
         // 
         // m_chkRightRing
         // 
         this->m_chkRightRing->AutoSize = true;
         this->m_chkRightRing->Location = System::Drawing::Point(6, 84);
         this->m_chkRightRing->Name = L"m_chkRightRing";
         this->m_chkRightRing->Size = System::Drawing::Size(48, 17);
         this->m_chkRightRing->TabIndex = 3;
         this->m_chkRightRing->Text = L"Ring";
         this->m_chkRightRing->UseVisualStyleBackColor = true;
         this->m_chkRightRing->CheckedChanged += gcnew System::EventHandler(this, &frmRegisterTemplate::OnChkRightRingCheckedChanged);
         // 
         // m_chkRightMiddle
         // 
         this->m_chkRightMiddle->AutoSize = true;
         this->m_chkRightMiddle->Location = System::Drawing::Point(6, 62);
         this->m_chkRightMiddle->Name = L"m_chkRightMiddle";
         this->m_chkRightMiddle->Size = System::Drawing::Size(57, 17);
         this->m_chkRightMiddle->TabIndex = 2;
         this->m_chkRightMiddle->Text = L"Middle";
         this->m_chkRightMiddle->UseVisualStyleBackColor = true;
         this->m_chkRightMiddle->CheckedChanged += gcnew System::EventHandler(this, &frmRegisterTemplate::OnChkRightMiddleCheckedChanged);
         // 
         // m_chkRightIndex
         // 
         this->m_chkRightIndex->AutoSize = true;
         this->m_chkRightIndex->Location = System::Drawing::Point(6, 42);
         this->m_chkRightIndex->Name = L"m_chkRightIndex";
         this->m_chkRightIndex->Size = System::Drawing::Size(52, 17);
         this->m_chkRightIndex->TabIndex = 1;
         this->m_chkRightIndex->Text = L"Index";
         this->m_chkRightIndex->UseVisualStyleBackColor = true;
         this->m_chkRightIndex->CheckedChanged += gcnew System::EventHandler(this, &frmRegisterTemplate::OnChkRightIndexCheckedChanged);
         // 
         // m_chkRightThumb
         // 
         this->m_chkRightThumb->AutoSize = true;
         this->m_chkRightThumb->Location = System::Drawing::Point(6, 19);
         this->m_chkRightThumb->Name = L"m_chkRightThumb";
         this->m_chkRightThumb->Size = System::Drawing::Size(59, 17);
         this->m_chkRightThumb->TabIndex = 0;
         this->m_chkRightThumb->Text = L"Thumb";
         this->m_chkRightThumb->UseVisualStyleBackColor = true;
         this->m_chkRightThumb->CheckedChanged += gcnew System::EventHandler(this, &frmRegisterTemplate::OnChkRightThumbCheckedChanged);
         // 
         // m_grpBoxLeftHand
         // 
         this->m_grpBoxLeftHand->Controls->Add(this->m_chkLeftPinkie);
         this->m_grpBoxLeftHand->Controls->Add(this->m_chkLeftRing);
         this->m_grpBoxLeftHand->Controls->Add(this->m_chkLeftMiddle);
         this->m_grpBoxLeftHand->Controls->Add(this->m_chkLeftIndex);
         this->m_grpBoxLeftHand->Controls->Add(this->m_chkLeftThumb);
         this->m_grpBoxLeftHand->Location = System::Drawing::Point(512, 3);
         this->m_grpBoxLeftHand->Name = L"m_grpBoxLeftHand";
         this->m_grpBoxLeftHand->Size = System::Drawing::Size(83, 130);
         this->m_grpBoxLeftHand->TabIndex = 1;
         this->m_grpBoxLeftHand->TabStop = false;
         this->m_grpBoxLeftHand->Text = L"Left Hand";
         // 
         // m_chkLeftPinkie
         // 
         this->m_chkLeftPinkie->AutoSize = true;
         this->m_chkLeftPinkie->Location = System::Drawing::Point(6, 107);
         this->m_chkLeftPinkie->Name = L"m_chkLeftPinkie";
         this->m_chkLeftPinkie->Size = System::Drawing::Size(55, 17);
         this->m_chkLeftPinkie->TabIndex = 4;
         this->m_chkLeftPinkie->Text = L"Pinkie";
         this->m_chkLeftPinkie->UseVisualStyleBackColor = true;
         this->m_chkLeftPinkie->CheckedChanged += gcnew System::EventHandler(this, &frmRegisterTemplate::OnChkLeftPinkieCheckedChanged);
         // 
         // m_chkLeftRing
         // 
         this->m_chkLeftRing->AutoSize = true;
         this->m_chkLeftRing->Location = System::Drawing::Point(6, 84);
         this->m_chkLeftRing->Name = L"m_chkLeftRing";
         this->m_chkLeftRing->Size = System::Drawing::Size(48, 17);
         this->m_chkLeftRing->TabIndex = 3;
         this->m_chkLeftRing->Text = L"Ring";
         this->m_chkLeftRing->UseVisualStyleBackColor = true;
         this->m_chkLeftRing->CheckedChanged += gcnew System::EventHandler(this, &frmRegisterTemplate::OnChkLeftRingCheckedChanged);
         // 
         // m_chkLeftMiddle
         // 
         this->m_chkLeftMiddle->AutoSize = true;
         this->m_chkLeftMiddle->Location = System::Drawing::Point(6, 62);
         this->m_chkLeftMiddle->Name = L"m_chkLeftMiddle";
         this->m_chkLeftMiddle->Size = System::Drawing::Size(57, 17);
         this->m_chkLeftMiddle->TabIndex = 2;
         this->m_chkLeftMiddle->Text = L"Middle";
         this->m_chkLeftMiddle->UseVisualStyleBackColor = true;
         this->m_chkLeftMiddle->CheckedChanged += gcnew System::EventHandler(this, &frmRegisterTemplate::OnChkLeftMiddleCheckedChanged);
         // 
         // m_chkLeftIndex
         // 
         this->m_chkLeftIndex->AutoSize = true;
         this->m_chkLeftIndex->Location = System::Drawing::Point(6, 42);
         this->m_chkLeftIndex->Name = L"m_chkLeftIndex";
         this->m_chkLeftIndex->Size = System::Drawing::Size(52, 17);
         this->m_chkLeftIndex->TabIndex = 1;
         this->m_chkLeftIndex->Text = L"Index";
         this->m_chkLeftIndex->UseVisualStyleBackColor = true;
         this->m_chkLeftIndex->CheckedChanged += gcnew System::EventHandler(this, &frmRegisterTemplate::OnChkLeftIndexCheckedChanged);
         // 
         // m_chkLeftThumb
         // 
         this->m_chkLeftThumb->AutoSize = true;
         this->m_chkLeftThumb->Location = System::Drawing::Point(6, 19);
         this->m_chkLeftThumb->Name = L"m_chkLeftThumb";
         this->m_chkLeftThumb->Size = System::Drawing::Size(59, 17);
         this->m_chkLeftThumb->TabIndex = 0;
         this->m_chkLeftThumb->Text = L"Thumb";
         this->m_chkLeftThumb->UseVisualStyleBackColor = true;
         this->m_chkLeftThumb->CheckedChanged += gcnew System::EventHandler(this, &frmRegisterTemplate::OnChkLeftThumbCheckedChanged);
         // 
         // m_tabPageOption
         // 
         this->m_tabPageOption->Controls->Add(this->m_cbOvertime);
         this->m_tabPageOption->Controls->Add(this->label6);
         this->m_tabPageOption->Controls->Add(this->m_chkUseGlobalWorkhour);
         this->m_tabPageOption->Controls->Add(this->label4);
         this->m_tabPageOption->Controls->Add(this->m_txtEndWorkHour);
         this->m_tabPageOption->Controls->Add(this->label5);
         this->m_tabPageOption->Controls->Add(this->m_txtStartWorkhour);
         this->m_tabPageOption->Controls->Add(this->m_txtPassword);
         this->m_tabPageOption->Controls->Add(this->label3);
         this->m_tabPageOption->Location = System::Drawing::Point(4, 25);
         this->m_tabPageOption->Name = L"m_tabPageOption";
         this->m_tabPageOption->Padding = System::Windows::Forms::Padding(3);
         this->m_tabPageOption->Size = System::Drawing::Size(604, 286);
         this->m_tabPageOption->TabIndex = 1;
         this->m_tabPageOption->Text = L"Options";
         this->m_tabPageOption->UseVisualStyleBackColor = true;
         // 
         // m_cbOvertime
         // 
         this->m_cbOvertime->FormattingEnabled = true;
         this->m_cbOvertime->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NO_OVERTIME", L"BEFORE_8", L"AFTER_8"});
         this->m_cbOvertime->Location = System::Drawing::Point(149, 59);
         this->m_cbOvertime->MaxDropDownItems = 3;
         this->m_cbOvertime->MaxLength = 11;
         this->m_cbOvertime->Name = L"m_cbOvertime";
         this->m_cbOvertime->Size = System::Drawing::Size(168, 21);
         this->m_cbOvertime->TabIndex = 33;
         this->m_cbOvertime->SelectedIndexChanged += gcnew System::EventHandler(this, &frmRegisterTemplate::OnOvertimeSelected);
         // 
         // label6
         // 
         this->label6->AutoSize = true;
         this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->label6->Location = System::Drawing::Point(8, 59);
         this->label6->Name = L"label6";
         this->label6->Size = System::Drawing::Size(100, 16);
         this->label6->TabIndex = 32;
         this->label6->Text = L"Overtime Mode";
         this->label6->Click += gcnew System::EventHandler(this, &frmRegisterTemplate::label6_Click);
         // 
         // m_chkUseGlobalWorkhour
         // 
         this->m_chkUseGlobalWorkhour->AutoSize = true;
         this->m_chkUseGlobalWorkhour->Checked = true;
         this->m_chkUseGlobalWorkhour->CheckState = System::Windows::Forms::CheckState::Checked;
         this->m_chkUseGlobalWorkhour->Location = System::Drawing::Point(11, 150);
         this->m_chkUseGlobalWorkhour->Name = L"m_chkUseGlobalWorkhour";
         this->m_chkUseGlobalWorkhour->Size = System::Drawing::Size(146, 17);
         this->m_chkUseGlobalWorkhour->TabIndex = 30;
         this->m_chkUseGlobalWorkhour->Text = L"Gunakan jam kerja global";
         this->m_chkUseGlobalWorkhour->UseVisualStyleBackColor = true;
         this->m_chkUseGlobalWorkhour->CheckedChanged += gcnew System::EventHandler(this, &frmRegisterTemplate::OnchkUseGlobalWorkhourCheckedChanged);
         // 
         // label4
         // 
         this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->label4->Location = System::Drawing::Point(8, 210);
         this->label4->Name = L"label4";
         this->label4->Size = System::Drawing::Size(135, 21);
         this->label4->TabIndex = 28;
         this->label4->Text = L"End Working Hour";
         // 
         // m_txtEndWorkHour
         // 
         this->m_txtEndWorkHour->BackColor = System::Drawing::Color::LemonChiffon;
         this->m_txtEndWorkHour->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->m_txtEndWorkHour->Enabled = false;
         this->m_txtEndWorkHour->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_txtEndWorkHour->Location = System::Drawing::Point(149, 205);
         this->m_txtEndWorkHour->MaxLength = 5;
         this->m_txtEndWorkHour->Name = L"m_txtEndWorkHour";
         this->m_txtEndWorkHour->Size = System::Drawing::Size(123, 26);
         this->m_txtEndWorkHour->TabIndex = 29;
         // 
         // label5
         // 
         this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->label5->Location = System::Drawing::Point(8, 178);
         this->label5->Name = L"label5";
         this->label5->Size = System::Drawing::Size(135, 21);
         this->label5->TabIndex = 26;
         this->label5->Text = L"Start Working Hour";
         // 
         // m_txtStartWorkhour
         // 
         this->m_txtStartWorkhour->BackColor = System::Drawing::Color::LemonChiffon;
         this->m_txtStartWorkhour->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->m_txtStartWorkhour->Enabled = false;
         this->m_txtStartWorkhour->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_txtStartWorkhour->Location = System::Drawing::Point(149, 173);
         this->m_txtStartWorkhour->MaxLength = 5;
         this->m_txtStartWorkhour->Name = L"m_txtStartWorkhour";
         this->m_txtStartWorkhour->Size = System::Drawing::Size(123, 26);
         this->m_txtStartWorkhour->TabIndex = 27;
         // 
         // m_txtPassword
         // 
         this->m_txtPassword->BackColor = System::Drawing::Color::LemonChiffon;
         this->m_txtPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->m_txtPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_txtPassword->Location = System::Drawing::Point(149, 11);
         this->m_txtPassword->MaxLength = 10;
         this->m_txtPassword->Name = L"m_txtPassword";
         this->m_txtPassword->Size = System::Drawing::Size(83, 26);
         this->m_txtPassword->TabIndex = 24;
         this->m_txtPassword->UseSystemPasswordChar = true;
         // 
         // label3
         // 
         this->label3->AutoSize = true;
         this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->label3->Location = System::Drawing::Point(8, 14);
         this->label3->Name = L"label3";
         this->label3->Size = System::Drawing::Size(68, 16);
         this->label3->TabIndex = 25;
         this->label3->Text = L"Password";
         // 
         // m_tabPageGeneral
         // 
         this->m_tabPageGeneral->Controls->Add(this->m_btnEditCode);
         this->m_tabPageGeneral->Controls->Add(this->m_lblVerifyCodeOK);
         this->m_tabPageGeneral->Controls->Add(this->m_cmdCheckCode);
         this->m_tabPageGeneral->Controls->Add(this->m_chkUseGlobalGreeting);
         this->m_tabPageGeneral->Controls->Add(this->m_cmdReset);
         this->m_tabPageGeneral->Controls->Add(this->label2);
         this->m_tabPageGeneral->Controls->Add(this->m_txtOutGreeting);
         this->m_tabPageGeneral->Controls->Add(this->label1);
         this->m_tabPageGeneral->Controls->Add(this->m_txtInGreeting);
         this->m_tabPageGeneral->Controls->Add(this->lblNamaKaryawan);
         this->m_tabPageGeneral->Controls->Add(this->lblKodeKaryawan);
         this->m_tabPageGeneral->Controls->Add(this->txtNamaKaryawan);
         this->m_tabPageGeneral->Controls->Add(this->txtKodeKaryawan);
         this->m_tabPageGeneral->Controls->Add(this->txtVerificationCode);
         this->m_tabPageGeneral->Controls->Add(this->lblVerificationCode);
         this->m_tabPageGeneral->Location = System::Drawing::Point(4, 25);
         this->m_tabPageGeneral->Name = L"m_tabPageGeneral";
         this->m_tabPageGeneral->Padding = System::Windows::Forms::Padding(3);
         this->m_tabPageGeneral->Size = System::Drawing::Size(604, 286);
         this->m_tabPageGeneral->TabIndex = 0;
         this->m_tabPageGeneral->Text = L"General";
         this->m_tabPageGeneral->UseVisualStyleBackColor = true;
         // 
         // m_btnEditCode
         // 
         this->m_btnEditCode->Enabled = false;
         this->m_btnEditCode->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->m_btnEditCode->Location = System::Drawing::Point(207, 78);
         this->m_btnEditCode->Name = L"m_btnEditCode";
         this->m_btnEditCode->Size = System::Drawing::Size(52, 23);
         this->m_btnEditCode->TabIndex = 25;
         this->m_btnEditCode->Text = L"Edit";
         this->m_btnEditCode->UseVisualStyleBackColor = true;
         this->m_btnEditCode->Click += gcnew System::EventHandler(this, &frmRegisterTemplate::OnBtnEditCode);
         // 
         // m_lblVerifyCodeOK
         // 
         this->m_lblVerifyCodeOK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
         this->m_lblVerifyCodeOK->ForeColor = System::Drawing::Color::ForestGreen;
         this->m_lblVerifyCodeOK->Location = System::Drawing::Point(333, 79);
         this->m_lblVerifyCodeOK->Name = L"m_lblVerifyCodeOK";
         this->m_lblVerifyCodeOK->Size = System::Drawing::Size(52, 21);
         this->m_lblVerifyCodeOK->TabIndex = 24;
         // 
         // m_cmdCheckCode
         // 
         this->m_cmdCheckCode->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->m_cmdCheckCode->Location = System::Drawing::Point(265, 78);
         this->m_cmdCheckCode->Name = L"m_cmdCheckCode";
         this->m_cmdCheckCode->Size = System::Drawing::Size(52, 23);
         this->m_cmdCheckCode->TabIndex = 4;
         this->m_cmdCheckCode->Text = L"Check!";
         this->m_cmdCheckCode->UseVisualStyleBackColor = true;
         this->m_cmdCheckCode->Click += gcnew System::EventHandler(this, &frmRegisterTemplate::OnCmdCheckCodeClick);
         // 
         // m_chkUseGlobalGreeting
         // 
         this->m_chkUseGlobalGreeting->AutoSize = true;
         this->m_chkUseGlobalGreeting->Checked = true;
         this->m_chkUseGlobalGreeting->CheckState = System::Windows::Forms::CheckState::Checked;
         this->m_chkUseGlobalGreeting->Location = System::Drawing::Point(15, 144);
         this->m_chkUseGlobalGreeting->Name = L"m_chkUseGlobalGreeting";
         this->m_chkUseGlobalGreeting->Size = System::Drawing::Size(142, 17);
         this->m_chkUseGlobalGreeting->TabIndex = 5;
         this->m_chkUseGlobalGreeting->Text = L"Gunakan greeting global";
         this->m_chkUseGlobalGreeting->UseVisualStyleBackColor = true;
         this->m_chkUseGlobalGreeting->CheckedChanged += gcnew System::EventHandler(this, &frmRegisterTemplate::OnchkUseGlobalGreetingCheckedChanged);
         // 
         // m_cmdReset
         // 
         this->m_cmdReset->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->m_cmdReset->Location = System::Drawing::Point(9, 251);
         this->m_cmdReset->Name = L"m_cmdReset";
         this->m_cmdReset->Size = System::Drawing::Size(75, 29);
         this->m_cmdReset->TabIndex = 11;
         this->m_cmdReset->Text = L"Reset";
         this->m_cmdReset->UseVisualStyleBackColor = true;
         this->m_cmdReset->Click += gcnew System::EventHandler(this, &frmRegisterTemplate::OnCmdResetClick);
         // 
         // label2
         // 
         this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->label2->Location = System::Drawing::Point(8, 209);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(90, 21);
         this->label2->TabIndex = 19;
         this->label2->Text = L"Out Greeting";
         // 
         // m_txtOutGreeting
         // 
         this->m_txtOutGreeting->BackColor = System::Drawing::Color::LemonChiffon;
         this->m_txtOutGreeting->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->m_txtOutGreeting->Enabled = false;
         this->m_txtOutGreeting->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_txtOutGreeting->Location = System::Drawing::Point(121, 204);
         this->m_txtOutGreeting->MaxLength = 255;
         this->m_txtOutGreeting->Name = L"m_txtOutGreeting";
         this->m_txtOutGreeting->Size = System::Drawing::Size(473, 26);
         this->m_txtOutGreeting->TabIndex = 7;
         // 
         // label1
         // 
         this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->label1->Location = System::Drawing::Point(8, 177);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(90, 21);
         this->label1->TabIndex = 17;
         this->label1->Text = L"In Greeting";
         // 
         // m_txtInGreeting
         // 
         this->m_txtInGreeting->BackColor = System::Drawing::Color::LemonChiffon;
         this->m_txtInGreeting->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->m_txtInGreeting->Enabled = false;
         this->m_txtInGreeting->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_txtInGreeting->Location = System::Drawing::Point(121, 172);
         this->m_txtInGreeting->MaxLength = 255;
         this->m_txtInGreeting->Name = L"m_txtInGreeting";
         this->m_txtInGreeting->Size = System::Drawing::Size(473, 26);
         this->m_txtInGreeting->TabIndex = 6;
         // 
         // lblNamaKaryawan
         // 
         this->lblNamaKaryawan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->lblNamaKaryawan->Location = System::Drawing::Point(6, 17);
         this->lblNamaKaryawan->Name = L"lblNamaKaryawan";
         this->lblNamaKaryawan->Size = System::Drawing::Size(107, 26);
         this->lblNamaKaryawan->TabIndex = 1;
         this->lblNamaKaryawan->Text = L"Nama Karyawan";
         // 
         // lblKodeKaryawan
         // 
         this->lblKodeKaryawan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->lblKodeKaryawan->Location = System::Drawing::Point(6, 46);
         this->lblKodeKaryawan->Name = L"lblKodeKaryawan";
         this->lblKodeKaryawan->Size = System::Drawing::Size(107, 26);
         this->lblKodeKaryawan->TabIndex = 2;
         this->lblKodeKaryawan->Text = L"Kode Karyawan";
         // 
         // txtNamaKaryawan
         // 
         this->txtNamaKaryawan->BackColor = System::Drawing::Color::LemonChiffon;
         this->txtNamaKaryawan->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->txtNamaKaryawan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->txtNamaKaryawan->Location = System::Drawing::Point(119, 12);
         this->txtNamaKaryawan->MaxLength = 30;
         this->txtNamaKaryawan->Name = L"txtNamaKaryawan";
         this->txtNamaKaryawan->Size = System::Drawing::Size(198, 26);
         this->txtNamaKaryawan->TabIndex = 1;
         this->txtNamaKaryawan->Leave += gcnew System::EventHandler(this, &frmRegisterTemplate::OnTxtNamaKaryawanLeave);
         // 
         // txtKodeKaryawan
         // 
         this->txtKodeKaryawan->BackColor = System::Drawing::Color::LemonChiffon;
         this->txtKodeKaryawan->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->txtKodeKaryawan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->txtKodeKaryawan->Location = System::Drawing::Point(119, 44);
         this->txtKodeKaryawan->MaxLength = 15;
         this->txtKodeKaryawan->Name = L"txtKodeKaryawan";
         this->txtKodeKaryawan->Size = System::Drawing::Size(122, 26);
         this->txtKodeKaryawan->TabIndex = 2;
         this->txtKodeKaryawan->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
         this->txtKodeKaryawan->Leave += gcnew System::EventHandler(this, &frmRegisterTemplate::OnTxtKodeKaryawanLeave);
         // 
         // txtVerificationCode
         // 
         this->txtVerificationCode->BackColor = System::Drawing::Color::LemonChiffon;
         this->txtVerificationCode->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->txtVerificationCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, 
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
         this->txtVerificationCode->Location = System::Drawing::Point(119, 76);
         this->txtVerificationCode->MaxLength = 4;
         this->txtVerificationCode->Name = L"txtVerificationCode";
         this->txtVerificationCode->Size = System::Drawing::Size(83, 26);
         this->txtVerificationCode->TabIndex = 3;
         this->txtVerificationCode->DoubleClick += gcnew System::EventHandler(this, &frmRegisterTemplate::OnVerifyCodeDoubleClick);
         this->txtVerificationCode->Leave += gcnew System::EventHandler(this, &frmRegisterTemplate::OnTxtVerificationCodeLeave);
         this->txtVerificationCode->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &frmRegisterTemplate::OntxtVerificationCodeKeyPress);
         // 
         // lblVerificationCode
         // 
         this->lblVerificationCode->AutoSize = true;
         this->lblVerificationCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, 
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
         this->lblVerificationCode->Location = System::Drawing::Point(6, 78);
         this->lblVerificationCode->Name = L"lblVerificationCode";
         this->lblVerificationCode->Size = System::Drawing::Size(98, 16);
         this->lblVerificationCode->TabIndex = 16;
         this->lblVerificationCode->Text = L"Kode Verifikasi";
         // 
         // m_tabPage
         // 
         this->m_tabPage->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
         this->m_tabPage->Controls->Add(this->m_tabPageGeneral);
         this->m_tabPage->Controls->Add(this->m_tabPageFingerRegistration);
         this->m_tabPage->Controls->Add(this->m_tabPageOption);
         this->m_tabPage->Location = System::Drawing::Point(0, 96);
         this->m_tabPage->Name = L"m_tabPage";
         this->m_tabPage->SelectedIndex = 0;
         this->m_tabPage->Size = System::Drawing::Size(612, 315);
         this->m_tabPage->TabIndex = 204;
         this->m_tabPage->SelectedIndexChanged += gcnew System::EventHandler(this, &frmRegisterTemplate::OnTabPageSelectedIndexChanged);
         // 
         // m_cmdCancel
         // 
         this->m_cmdCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
         this->m_cmdCancel->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
         this->m_cmdCancel->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
         this->m_cmdCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->m_cmdCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_cmdCancel->Location = System::Drawing::Point(491, 417);
         this->m_cmdCancel->Name = L"m_cmdCancel";
         this->m_cmdCancel->Size = System::Drawing::Size(105, 31);
         this->m_cmdCancel->TabIndex = 9;
         this->m_cmdCancel->Text = L"Cancel";
         this->m_cmdCancel->UseVisualStyleBackColor = true;
         this->m_cmdCancel->Click += gcnew System::EventHandler(this, &frmRegisterTemplate::OnCmdCancel);
         // 
         // m_cmdNewUser
         // 
         this->m_cmdNewUser->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
         this->m_cmdNewUser->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
         this->m_cmdNewUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->m_cmdNewUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_cmdNewUser->Location = System::Drawing::Point(13, 417);
         this->m_cmdNewUser->Name = L"m_cmdNewUser";
         this->m_cmdNewUser->Size = System::Drawing::Size(88, 31);
         this->m_cmdNewUser->TabIndex = 10;
         this->m_cmdNewUser->Text = L"New User";
         this->m_cmdNewUser->UseVisualStyleBackColor = true;
         this->m_cmdNewUser->Click += gcnew System::EventHandler(this, &frmRegisterTemplate::OnCmdNewUSer);
         // 
         // frmRegisterTemplate
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)));
         this->ClientSize = System::Drawing::Size(606, 479);
         this->Controls->Add(this->m_cmdNewUser);
         this->Controls->Add(this->m_cmdCancel);
         this->Controls->Add(this->m_tabPage);
         this->Controls->Add(this->m_lblGuide);
         this->Controls->Add(this->statusBar);
         this->Controls->Add(this->cmdSaveData);
         this->Controls->Add(this->lblJudul);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
         this->MaximizeBox = false;
         this->Name = L"frmRegisterTemplate";
         this->ShowIcon = false;
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"User Enrollment...";
         this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &frmRegisterTemplate::frmRegisterTemplate_KeyPress);
         this->Load += gcnew System::EventHandler(this, &frmRegisterTemplate::frmRegisterTemplate_Load);
         this->statusBar->ResumeLayout(false);
         this->statusBar->PerformLayout();
         this->m_tabPageFingerRegistration->ResumeLayout(false);
         this->m_grpBoxRightHand->ResumeLayout(false);
         this->m_grpBoxRightHand->PerformLayout();
         this->m_grpBoxLeftHand->ResumeLayout(false);
         this->m_grpBoxLeftHand->PerformLayout();
         this->m_tabPageOption->ResumeLayout(false);
         this->m_tabPageOption->PerformLayout();
         this->m_tabPageGeneral->ResumeLayout(false);
         this->m_tabPageGeneral->PerformLayout();
         this->m_tabPage->ResumeLayout(false);
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion


private: System::Void frmRegisterTemplate_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void cmdSaveData_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void frmRegisterTemplate_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
private: System::Void m_axFPRegisterTemplateX_Done(System::Object^  sender, AxDPSDKOPSLib::_IFPRegisterTemplateXEvents_DoneEvent^  e);

private: System::Void DoRegisterUser(FingerPrint::fpFingerEnum fingerToUSe);
private: System::Void InitFPRegisterTemplateX();
private: System::Void RunFPRegisterTemplateX();

private: System::Void UpdateForm();
private: System::Void ResetForm();
private: System::Void SaveDummyFingerPrintTemplate(){}
private: System::Void SaveFingerPrintTemplate(){}
private: System::Void CheckVerifyCode();


private: System::Void OnChkLeftThumbCheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnChkLeftIndexCheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnChkLeftMiddleCheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnChkLeftRingCheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnChkLeftPinkieCheckedChanged(System::Object^  sender, System::EventArgs^  e);

private: System::Void OnChkRightThumbCheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnChkRightIndexCheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnChkRightMiddleCheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnChkRightRingCheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnChkRightPinkieCheckedChanged(System::Object^  sender, System::EventArgs^  e);

private: System::Void OnchkUseGlobalGreetingCheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnchkUseGlobalWorkhourCheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnCmdResetClick(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnTabPageSelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnCmdNewUSer(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnCmdCancel(System::Object^  sender, System::EventArgs^  e) 
         {
            this->Close();
         }
private: System::Void OnCmdCheckCodeClick(System::Object^  sender, System::EventArgs^  e);
private: System::Void OntxtVerificationCodeKeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
private: System::Void OnTxtNamaKaryawanLeave(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnTxtKodeKaryawanLeave(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnTxtVerificationCodeLeave(System::Object^  sender, System::EventArgs^  e);


public: void InitControlsFromDB(System::String^ userID);
public: void DisableSomeControls();

private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
         }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {}

private: System::Void OnOvertimeSelected(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnVerifyCodeDoubleClick(System::Object^  sender, System::EventArgs^  e) 
         {
         }
private: System::Void OnBtnEditCode(System::Object^  sender, System::EventArgs^  e);
};
//}


