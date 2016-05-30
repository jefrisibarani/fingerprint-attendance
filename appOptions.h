/*****************************************************************************
* filename : appOptions.h
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : Contains application Options form intreface
*
*****************************************************************************/
#pragma once

/** appOptions class.
 * This class provide user interface for setting application options
 * the class gets and saves its values from and to appSettings class,
 * which is static
 */
	public ref class appOptions : public System::Windows::Forms::Form
	{
	public:
      /** Constructor. */
      appOptions(void);

	protected:
      /** Cleanup components. */
		~appOptions()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ nbOptions;
	private: System::Windows::Forms::TabPage^    nbGeneralOptions;
	private: System::Windows::Forms::TabPage^    nbDatabaseOptions;
	private: System::Windows::Forms::TabPage^    nbMiscellaneousOptions;
	public: System::Windows::Forms::TextBox^     txtDatabase;
	public: System::Windows::Forms::TextBox^     txtPort;
	public: System::Windows::Forms::TextBox^     txtServer;
	public: System::Windows::Forms::TextBox^     txtPassword;
	public: System::Windows::Forms::TextBox^     txtUserName;
	private: System::Windows::Forms::Label^      lblDataBase;
	private: System::Windows::Forms::Label^      lblPort;
	private: System::Windows::Forms::Label^      lblServer;
	private: System::Windows::Forms::Label^      lblPassword;
	private: System::Windows::Forms::Label^      lblUserName;
	private: System::Windows::Forms::Button^     cmdApply;
	private: System::Windows::Forms::Button^     cmdOK;

   private: String^ logFile;                 ///< Log File Name.
   private: String^ logFileTarget;           ///< Complete log file path.
   private: bool enableLogToDatabase;

   private: System::Windows::Forms::GroupBox^  grpBoxDBConn;
   private: System::Windows::Forms::GroupBox^  grpBoxLogging;
   private: System::Windows::Forms::TextBox^  txtLogFile;
   private: System::Windows::Forms::ComboBox^  cbLoggingLevel;
   private: System::Windows::Forms::CheckBox^  chkLogToDatabase;

   private: System::Windows::Forms::Label^  lblLogFile;
   private: System::Windows::Forms::Label^  txtLogLevel;
   private: System::Windows::Forms::GroupBox^  grpBoxSite;
   private: System::Windows::Forms::TextBox^  txtLocation;

   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::GroupBox^  grpGreeting;
   private: System::Windows::Forms::Label^  label3;
   private: System::Windows::Forms::Label^  label2;
   private: System::Windows::Forms::TextBox^  txtOutGreeting;

   private: System::Windows::Forms::TextBox^  txtInGreeting;
   private: System::Windows::Forms::CheckBox^  chkAutoConnect;
   private: System::Windows::Forms::CheckBox^  chkAutoDisconnect;
   private: System::Windows::Forms::TabPage^  nbEventsOptions;
   private: System::Windows::Forms::GroupBox^  gprSounds;
   private: System::Windows::Forms::Button^  btnTestOkaySound;

   private: System::Windows::Forms::Button^  btnTestFailedSound;

   private: System::Windows::Forms::ComboBox^  cbOkaySounds;

   private: System::Windows::Forms::ComboBox^  cbFailedSounds;

   private: System::Windows::Forms::Label^  label5;
   private: System::Windows::Forms::Label^  label4;
   private: System::Windows::Forms::ComboBox^  cbErrorSounds;

   private: System::Windows::Forms::ComboBox^  cbWarnSounds;
   private: System::Windows::Forms::Label^  label7;
   private: System::Windows::Forms::Label^  label6;
   private: System::Windows::Forms::Button^  btnTestErrorSound;

   private: System::Windows::Forms::Button^  btnTestWarnSound;
   private: System::Windows::Forms::Button^  btn_BreakEndSound;

   private: System::Windows::Forms::Button^  btn_BreakStartSound;
   private: System::Windows::Forms::ComboBox^  cbEndBreak;


   private: System::Windows::Forms::ComboBox^  cbStartBreak;

   private: System::Windows::Forms::Label^  label10;
   private: System::Windows::Forms::Label^  label11;
   private: System::Windows::Forms::Button^  btn_workEndSound;

   private: System::Windows::Forms::Button^  btnWorkStartSound;
   private: System::Windows::Forms::ComboBox^  cbEndWork;


   private: System::Windows::Forms::ComboBox^  cbStartWork;

   private: System::Windows::Forms::Label^  label8;
   private: System::Windows::Forms::Label^  label9;



            //long minLoggingLevel;

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
         this->nbOptions = (gcnew System::Windows::Forms::TabControl());
         this->nbGeneralOptions = (gcnew System::Windows::Forms::TabPage());
         this->grpBoxSite = (gcnew System::Windows::Forms::GroupBox());
         this->txtLocation = (gcnew System::Windows::Forms::TextBox());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->nbDatabaseOptions = (gcnew System::Windows::Forms::TabPage());
         this->chkAutoDisconnect = (gcnew System::Windows::Forms::CheckBox());
         this->chkAutoConnect = (gcnew System::Windows::Forms::CheckBox());
         this->grpBoxDBConn = (gcnew System::Windows::Forms::GroupBox());
         this->lblPassword = (gcnew System::Windows::Forms::Label());
         this->txtDatabase = (gcnew System::Windows::Forms::TextBox());
         this->lblUserName = (gcnew System::Windows::Forms::Label());
         this->txtPort = (gcnew System::Windows::Forms::TextBox());
         this->lblServer = (gcnew System::Windows::Forms::Label());
         this->txtServer = (gcnew System::Windows::Forms::TextBox());
         this->lblPort = (gcnew System::Windows::Forms::Label());
         this->txtPassword = (gcnew System::Windows::Forms::TextBox());
         this->lblDataBase = (gcnew System::Windows::Forms::Label());
         this->txtUserName = (gcnew System::Windows::Forms::TextBox());
         this->nbMiscellaneousOptions = (gcnew System::Windows::Forms::TabPage());
         this->grpGreeting = (gcnew System::Windows::Forms::GroupBox());
         this->txtOutGreeting = (gcnew System::Windows::Forms::TextBox());
         this->txtInGreeting = (gcnew System::Windows::Forms::TextBox());
         this->label3 = (gcnew System::Windows::Forms::Label());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->grpBoxLogging = (gcnew System::Windows::Forms::GroupBox());
         this->txtLogFile = (gcnew System::Windows::Forms::TextBox());
         this->cbLoggingLevel = (gcnew System::Windows::Forms::ComboBox());
         this->chkLogToDatabase = (gcnew System::Windows::Forms::CheckBox());
         this->lblLogFile = (gcnew System::Windows::Forms::Label());
         this->txtLogLevel = (gcnew System::Windows::Forms::Label());
         this->nbEventsOptions = (gcnew System::Windows::Forms::TabPage());
         this->gprSounds = (gcnew System::Windows::Forms::GroupBox());
         this->btn_BreakEndSound = (gcnew System::Windows::Forms::Button());
         this->btn_BreakStartSound = (gcnew System::Windows::Forms::Button());
         this->cbEndBreak = (gcnew System::Windows::Forms::ComboBox());
         this->cbStartBreak = (gcnew System::Windows::Forms::ComboBox());
         this->label10 = (gcnew System::Windows::Forms::Label());
         this->label11 = (gcnew System::Windows::Forms::Label());
         this->btn_workEndSound = (gcnew System::Windows::Forms::Button());
         this->btnWorkStartSound = (gcnew System::Windows::Forms::Button());
         this->cbEndWork = (gcnew System::Windows::Forms::ComboBox());
         this->cbStartWork = (gcnew System::Windows::Forms::ComboBox());
         this->label8 = (gcnew System::Windows::Forms::Label());
         this->label9 = (gcnew System::Windows::Forms::Label());
         this->label7 = (gcnew System::Windows::Forms::Label());
         this->label6 = (gcnew System::Windows::Forms::Label());
         this->btnTestErrorSound = (gcnew System::Windows::Forms::Button());
         this->btnTestWarnSound = (gcnew System::Windows::Forms::Button());
         this->cbErrorSounds = (gcnew System::Windows::Forms::ComboBox());
         this->cbWarnSounds = (gcnew System::Windows::Forms::ComboBox());
         this->btnTestOkaySound = (gcnew System::Windows::Forms::Button());
         this->btnTestFailedSound = (gcnew System::Windows::Forms::Button());
         this->cbOkaySounds = (gcnew System::Windows::Forms::ComboBox());
         this->cbFailedSounds = (gcnew System::Windows::Forms::ComboBox());
         this->label5 = (gcnew System::Windows::Forms::Label());
         this->label4 = (gcnew System::Windows::Forms::Label());
         this->cmdApply = (gcnew System::Windows::Forms::Button());
         this->cmdOK = (gcnew System::Windows::Forms::Button());
         this->nbOptions->SuspendLayout();
         this->nbGeneralOptions->SuspendLayout();
         this->grpBoxSite->SuspendLayout();
         this->nbDatabaseOptions->SuspendLayout();
         this->grpBoxDBConn->SuspendLayout();
         this->nbMiscellaneousOptions->SuspendLayout();
         this->grpGreeting->SuspendLayout();
         this->grpBoxLogging->SuspendLayout();
         this->nbEventsOptions->SuspendLayout();
         this->gprSounds->SuspendLayout();
         this->SuspendLayout();
         // 
         // nbOptions
         // 
         this->nbOptions->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
         this->nbOptions->Controls->Add(this->nbGeneralOptions);
         this->nbOptions->Controls->Add(this->nbDatabaseOptions);
         this->nbOptions->Controls->Add(this->nbMiscellaneousOptions);
         this->nbOptions->Controls->Add(this->nbEventsOptions);
         this->nbOptions->HotTrack = true;
         this->nbOptions->ImeMode = System::Windows::Forms::ImeMode::NoControl;
         this->nbOptions->ItemSize = System::Drawing::Size(49, 24);
         this->nbOptions->Location = System::Drawing::Point(4, 2);
         this->nbOptions->Margin = System::Windows::Forms::Padding(0);
         this->nbOptions->Name = L"nbOptions";
         this->nbOptions->SelectedIndex = 0;
         this->nbOptions->Size = System::Drawing::Size(416, 305);
         this->nbOptions->SizeMode = System::Windows::Forms::TabSizeMode::FillToRight;
         this->nbOptions->TabIndex = 0;
         // 
         // nbGeneralOptions
         // 
         this->nbGeneralOptions->Controls->Add(this->grpBoxSite);
         this->nbGeneralOptions->Location = System::Drawing::Point(4, 28);
         this->nbGeneralOptions->Name = L"nbGeneralOptions";
         this->nbGeneralOptions->Padding = System::Windows::Forms::Padding(3);
         this->nbGeneralOptions->Size = System::Drawing::Size(408, 273);
         this->nbGeneralOptions->TabIndex = 0;
         this->nbGeneralOptions->Text = L"General";
         // 
         // grpBoxSite
         // 
         this->grpBoxSite->Controls->Add(this->txtLocation);
         this->grpBoxSite->Controls->Add(this->label1);
         this->grpBoxSite->Location = System::Drawing::Point(23, 17);
         this->grpBoxSite->Name = L"grpBoxSite";
         this->grpBoxSite->Size = System::Drawing::Size(352, 72);
         this->grpBoxSite->TabIndex = 10;
         this->grpBoxSite->TabStop = false;
         this->grpBoxSite->Text = L"Site Information";
         // 
         // txtLocation
         // 
         this->txtLocation->BackColor = System::Drawing::Color::LemonChiffon;
         this->txtLocation->Location = System::Drawing::Point(77, 30);
         this->txtLocation->MaxLength = 255;
         this->txtLocation->Name = L"txtLocation";
         this->txtLocation->Size = System::Drawing::Size(259, 20);
         this->txtLocation->TabIndex = 1;
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Location = System::Drawing::Point(6, 37);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(48, 13);
         this->label1->TabIndex = 0;
         this->label1->Text = L"Location";
         // 
         // nbDatabaseOptions
         // 
         this->nbDatabaseOptions->Controls->Add(this->chkAutoDisconnect);
         this->nbDatabaseOptions->Controls->Add(this->chkAutoConnect);
         this->nbDatabaseOptions->Controls->Add(this->grpBoxDBConn);
         this->nbDatabaseOptions->Location = System::Drawing::Point(4, 28);
         this->nbDatabaseOptions->Name = L"nbDatabaseOptions";
         this->nbDatabaseOptions->Padding = System::Windows::Forms::Padding(3);
         this->nbDatabaseOptions->Size = System::Drawing::Size(408, 273);
         this->nbDatabaseOptions->TabIndex = 1;
         this->nbDatabaseOptions->Text = L"Database ";
         // 
         // chkAutoDisconnect
         // 
         this->chkAutoDisconnect->AutoSize = true;
         this->chkAutoDisconnect->Checked = true;
         this->chkAutoDisconnect->CheckState = System::Windows::Forms::CheckState::Checked;
         this->chkAutoDisconnect->Location = System::Drawing::Point(22, 248);
         this->chkAutoDisconnect->Name = L"chkAutoDisconnect";
         this->chkAutoDisconnect->Size = System::Drawing::Size(187, 17);
         this->chkAutoDisconnect->TabIndex = 22;
         this->chkAutoDisconnect->Text = L"Disconnect at program termination";
         this->chkAutoDisconnect->UseVisualStyleBackColor = true;
         // 
         // chkAutoConnect
         // 
         this->chkAutoConnect->AutoSize = true;
         this->chkAutoConnect->Checked = true;
         this->chkAutoConnect->CheckState = System::Windows::Forms::CheckState::Checked;
         this->chkAutoConnect->Location = System::Drawing::Point(22, 225);
         this->chkAutoConnect->Name = L"chkAutoConnect";
         this->chkAutoConnect->Size = System::Drawing::Size(277, 17);
         this->chkAutoConnect->TabIndex = 21;
         this->chkAutoConnect->Text = L"Automatically connect to database at program startup";
         this->chkAutoConnect->UseVisualStyleBackColor = true;
         // 
         // grpBoxDBConn
         // 
         this->grpBoxDBConn->Controls->Add(this->lblPassword);
         this->grpBoxDBConn->Controls->Add(this->txtDatabase);
         this->grpBoxDBConn->Controls->Add(this->lblUserName);
         this->grpBoxDBConn->Controls->Add(this->txtPort);
         this->grpBoxDBConn->Controls->Add(this->lblServer);
         this->grpBoxDBConn->Controls->Add(this->txtServer);
         this->grpBoxDBConn->Controls->Add(this->lblPort);
         this->grpBoxDBConn->Controls->Add(this->txtPassword);
         this->grpBoxDBConn->Controls->Add(this->lblDataBase);
         this->grpBoxDBConn->Controls->Add(this->txtUserName);
         this->grpBoxDBConn->Location = System::Drawing::Point(22, 17);
         this->grpBoxDBConn->Name = L"grpBoxDBConn";
         this->grpBoxDBConn->Size = System::Drawing::Size(339, 185);
         this->grpBoxDBConn->TabIndex = 20;
         this->grpBoxDBConn->TabStop = false;
         this->grpBoxDBConn->Text = L"Database connection string";
         // 
         // lblPassword
         // 
         this->lblPassword->Location = System::Drawing::Point(20, 60);
         this->lblPassword->Name = L"lblPassword";
         this->lblPassword->Size = System::Drawing::Size(89, 20);
         this->lblPassword->TabIndex = 11;
         this->lblPassword->Text = L"Password";
         this->lblPassword->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
         // 
         // txtDatabase
         // 
         this->txtDatabase->BackColor = System::Drawing::Color::LightGoldenrodYellow;
         this->txtDatabase->Location = System::Drawing::Point(127, 151);
         this->txtDatabase->MaxLength = 20;
         this->txtDatabase->Name = L"txtDatabase";
         this->txtDatabase->Size = System::Drawing::Size(157, 20);
         this->txtDatabase->TabIndex = 19;
         this->txtDatabase->Text = L"fp_absensi";
         this->txtDatabase->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
         // 
         // lblUserName
         // 
         this->lblUserName->Location = System::Drawing::Point(20, 28);
         this->lblUserName->Name = L"lblUserName";
         this->lblUserName->Size = System::Drawing::Size(89, 20);
         this->lblUserName->TabIndex = 10;
         this->lblUserName->Text = L"User Name";
         this->lblUserName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
         // 
         // txtPort
         // 
         this->txtPort->BackColor = System::Drawing::Color::LightGoldenrodYellow;
         this->txtPort->Location = System::Drawing::Point(128, 120);
         this->txtPort->MaxLength = 4;
         this->txtPort->Name = L"txtPort";
         this->txtPort->Size = System::Drawing::Size(157, 20);
         this->txtPort->TabIndex = 18;
         this->txtPort->Text = L"5432";
         this->txtPort->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
         this->txtPort->TextChanged += gcnew System::EventHandler(this, &appOptions::txtPort_TextChanged);
         // 
         // lblServer
         // 
         this->lblServer->Location = System::Drawing::Point(20, 89);
         this->lblServer->Name = L"lblServer";
         this->lblServer->Size = System::Drawing::Size(89, 20);
         this->lblServer->TabIndex = 12;
         this->lblServer->Text = L"Server";
         this->lblServer->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
         // 
         // txtServer
         // 
         this->txtServer->BackColor = System::Drawing::Color::LightGoldenrodYellow;
         this->txtServer->Location = System::Drawing::Point(127, 89);
         this->txtServer->MaxLength = 20;
         this->txtServer->Name = L"txtServer";
         this->txtServer->Size = System::Drawing::Size(157, 20);
         this->txtServer->TabIndex = 17;
         this->txtServer->Text = L"localhost";
         this->txtServer->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
         this->txtServer->TextChanged += gcnew System::EventHandler(this, &appOptions::txtServer_TextChanged);
         // 
         // lblPort
         // 
         this->lblPort->Location = System::Drawing::Point(20, 120);
         this->lblPort->Name = L"lblPort";
         this->lblPort->Size = System::Drawing::Size(89, 20);
         this->lblPort->TabIndex = 13;
         this->lblPort->Text = L"Port";
         this->lblPort->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
         // 
         // txtPassword
         // 
         this->txtPassword->BackColor = System::Drawing::Color::LightGoldenrodYellow;
         this->txtPassword->Location = System::Drawing::Point(128, 60);
         this->txtPassword->MaxLength = 20;
         this->txtPassword->Name = L"txtPassword";
         this->txtPassword->PasswordChar = '$';
         this->txtPassword->Size = System::Drawing::Size(157, 20);
         this->txtPassword->TabIndex = 16;
         this->txtPassword->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
         this->txtPassword->UseSystemPasswordChar = true;
         this->txtPassword->TextChanged += gcnew System::EventHandler(this, &appOptions::txtPassword_TextChanged);
         // 
         // lblDataBase
         // 
         this->lblDataBase->Location = System::Drawing::Point(20, 151);
         this->lblDataBase->Name = L"lblDataBase";
         this->lblDataBase->Size = System::Drawing::Size(89, 20);
         this->lblDataBase->TabIndex = 14;
         this->lblDataBase->Text = L"Database";
         this->lblDataBase->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
         // 
         // txtUserName
         // 
         this->txtUserName->BackColor = System::Drawing::Color::LightGoldenrodYellow;
         this->txtUserName->Location = System::Drawing::Point(128, 28);
         this->txtUserName->MaxLength = 20;
         this->txtUserName->Name = L"txtUserName";
         this->txtUserName->Size = System::Drawing::Size(157, 20);
         this->txtUserName->TabIndex = 15;
         this->txtUserName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
         this->txtUserName->TextChanged += gcnew System::EventHandler(this, &appOptions::txtUserName_TextChanged);
         // 
         // nbMiscellaneousOptions
         // 
         this->nbMiscellaneousOptions->Controls->Add(this->grpGreeting);
         this->nbMiscellaneousOptions->Controls->Add(this->grpBoxLogging);
         this->nbMiscellaneousOptions->Location = System::Drawing::Point(4, 28);
         this->nbMiscellaneousOptions->Name = L"nbMiscellaneousOptions";
         this->nbMiscellaneousOptions->Padding = System::Windows::Forms::Padding(3);
         this->nbMiscellaneousOptions->Size = System::Drawing::Size(408, 273);
         this->nbMiscellaneousOptions->TabIndex = 2;
         this->nbMiscellaneousOptions->Text = L"Miscellaneous";
         // 
         // grpGreeting
         // 
         this->grpGreeting->Controls->Add(this->txtOutGreeting);
         this->grpGreeting->Controls->Add(this->txtInGreeting);
         this->grpGreeting->Controls->Add(this->label3);
         this->grpGreeting->Controls->Add(this->label2);
         this->grpGreeting->Location = System::Drawing::Point(6, 179);
         this->grpGreeting->Name = L"grpGreeting";
         this->grpGreeting->Size = System::Drawing::Size(395, 100);
         this->grpGreeting->TabIndex = 8;
         this->grpGreeting->TabStop = false;
         this->grpGreeting->Text = L"Greetings";
         // 
         // txtOutGreeting
         // 
         this->txtOutGreeting->Location = System::Drawing::Point(55, 59);
         this->txtOutGreeting->MaxLength = 1024;
         this->txtOutGreeting->Name = L"txtOutGreeting";
         this->txtOutGreeting->Size = System::Drawing::Size(334, 20);
         this->txtOutGreeting->TabIndex = 3;
         // 
         // txtInGreeting
         // 
         this->txtInGreeting->Location = System::Drawing::Point(56, 28);
         this->txtInGreeting->MaxLength = 1024;
         this->txtInGreeting->Name = L"txtInGreeting";
         this->txtInGreeting->Size = System::Drawing::Size(333, 20);
         this->txtInGreeting->TabIndex = 2;
         // 
         // label3
         // 
         this->label3->AutoSize = true;
         this->label3->Location = System::Drawing::Point(8, 62);
         this->label3->Name = L"label3";
         this->label3->Size = System::Drawing::Size(24, 13);
         this->label3->TabIndex = 1;
         this->label3->Text = L"Out";
         // 
         // label2
         // 
         this->label2->AutoSize = true;
         this->label2->Location = System::Drawing::Point(8, 31);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(16, 13);
         this->label2->TabIndex = 0;
         this->label2->Text = L"In";
         // 
         // grpBoxLogging
         // 
         this->grpBoxLogging->Controls->Add(this->txtLogFile);
         this->grpBoxLogging->Controls->Add(this->cbLoggingLevel);
         this->grpBoxLogging->Controls->Add(this->chkLogToDatabase);
         this->grpBoxLogging->Controls->Add(this->lblLogFile);
         this->grpBoxLogging->Controls->Add(this->txtLogLevel);
         this->grpBoxLogging->Location = System::Drawing::Point(7, 6);
         this->grpBoxLogging->Name = L"grpBoxLogging";
         this->grpBoxLogging->Size = System::Drawing::Size(394, 147);
         this->grpBoxLogging->TabIndex = 7;
         this->grpBoxLogging->TabStop = false;
         this->grpBoxLogging->Text = L"Logging ";
         // 
         // txtLogFile
         // 
         this->txtLogFile->BackColor = System::Drawing::Color::LemonChiffon;
         this->txtLogFile->Location = System::Drawing::Point(16, 88);
         this->txtLogFile->Name = L"txtLogFile";
         this->txtLogFile->Size = System::Drawing::Size(372, 20);
         this->txtLogFile->TabIndex = 2;
         this->txtLogFile->DoubleClick += gcnew System::EventHandler(this, &appOptions::txtLogFile_DoubleClick);
         // 
         // cbLoggingLevel
         // 
         this->cbLoggingLevel->BackColor = System::Drawing::Color::LemonChiffon;
         this->cbLoggingLevel->FormattingEnabled = true;
         this->cbLoggingLevel->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"LOG_ERROR", L"LOG_WARNING", L"LOG_SQL", 
            L"LOG_INFO", L"LOG_DEBUG"});
         this->cbLoggingLevel->Location = System::Drawing::Point(108, 114);
         this->cbLoggingLevel->Name = L"cbLoggingLevel";
         this->cbLoggingLevel->Size = System::Drawing::Size(165, 21);
         this->cbLoggingLevel->TabIndex = 5;
         // 
         // chkLogToDatabase
         // 
         this->chkLogToDatabase->AutoSize = true;
         this->chkLogToDatabase->Location = System::Drawing::Point(16, 36);
         this->chkLogToDatabase->Name = L"chkLogToDatabase";
         this->chkLogToDatabase->Size = System::Drawing::Size(155, 17);
         this->chkLogToDatabase->TabIndex = 0;
         this->chkLogToDatabase->Text = L"Enable logging to database";
         this->chkLogToDatabase->UseVisualStyleBackColor = false;
         this->chkLogToDatabase->CheckedChanged += gcnew System::EventHandler(this, &appOptions::OnEnableLogToDatabase);
         // 
         // lblLogFile
         // 
         this->lblLogFile->AutoSize = true;
         this->lblLogFile->Location = System::Drawing::Point(13, 72);
         this->lblLogFile->Name = L"lblLogFile";
         this->lblLogFile->Size = System::Drawing::Size(44, 13);
         this->lblLogFile->TabIndex = 3;
         this->lblLogFile->Text = L"Log File";
         // 
         // txtLogLevel
         // 
         this->txtLogLevel->Location = System::Drawing::Point(13, 120);
         this->txtLogLevel->Name = L"txtLogLevel";
         this->txtLogLevel->Size = System::Drawing::Size(89, 15);
         this->txtLogLevel->TabIndex = 4;
         this->txtLogLevel->Text = L"Logging Level";
         // 
         // nbEventsOptions
         // 
         this->nbEventsOptions->Controls->Add(this->gprSounds);
         this->nbEventsOptions->Location = System::Drawing::Point(4, 28);
         this->nbEventsOptions->Name = L"nbEventsOptions";
         this->nbEventsOptions->Padding = System::Windows::Forms::Padding(3);
         this->nbEventsOptions->Size = System::Drawing::Size(408, 273);
         this->nbEventsOptions->TabIndex = 3;
         this->nbEventsOptions->Text = L"Events";
         this->nbEventsOptions->UseVisualStyleBackColor = true;
         // 
         // gprSounds
         // 
         this->gprSounds->Controls->Add(this->btn_BreakEndSound);
         this->gprSounds->Controls->Add(this->btn_BreakStartSound);
         this->gprSounds->Controls->Add(this->cbEndBreak);
         this->gprSounds->Controls->Add(this->cbStartBreak);
         this->gprSounds->Controls->Add(this->label10);
         this->gprSounds->Controls->Add(this->label11);
         this->gprSounds->Controls->Add(this->btn_workEndSound);
         this->gprSounds->Controls->Add(this->btnWorkStartSound);
         this->gprSounds->Controls->Add(this->cbEndWork);
         this->gprSounds->Controls->Add(this->cbStartWork);
         this->gprSounds->Controls->Add(this->label8);
         this->gprSounds->Controls->Add(this->label9);
         this->gprSounds->Controls->Add(this->label7);
         this->gprSounds->Controls->Add(this->label6);
         this->gprSounds->Controls->Add(this->btnTestErrorSound);
         this->gprSounds->Controls->Add(this->btnTestWarnSound);
         this->gprSounds->Controls->Add(this->cbErrorSounds);
         this->gprSounds->Controls->Add(this->cbWarnSounds);
         this->gprSounds->Controls->Add(this->btnTestOkaySound);
         this->gprSounds->Controls->Add(this->btnTestFailedSound);
         this->gprSounds->Controls->Add(this->cbOkaySounds);
         this->gprSounds->Controls->Add(this->cbFailedSounds);
         this->gprSounds->Controls->Add(this->label5);
         this->gprSounds->Controls->Add(this->label4);
         this->gprSounds->Location = System::Drawing::Point(6, 17);
         this->gprSounds->Name = L"gprSounds";
         this->gprSounds->Size = System::Drawing::Size(395, 250);
         this->gprSounds->TabIndex = 0;
         this->gprSounds->TabStop = false;
         this->gprSounds->Text = L"Sounds";
         // 
         // btn_BreakEndSound
         // 
         this->btn_BreakEndSound->Location = System::Drawing::Point(347, 103);
         this->btn_BreakEndSound->Name = L"btn_BreakEndSound";
         this->btn_BreakEndSound->Size = System::Drawing::Size(42, 21);
         this->btn_BreakEndSound->TabIndex = 23;
         this->btn_BreakEndSound->Text = L"Test";
         this->btn_BreakEndSound->UseVisualStyleBackColor = true;
         this->btn_BreakEndSound->Click += gcnew System::EventHandler(this, &appOptions::OnBtnEndBreak);
         // 
         // btn_BreakStartSound
         // 
         this->btn_BreakStartSound->Location = System::Drawing::Point(347, 76);
         this->btn_BreakStartSound->Name = L"btn_BreakStartSound";
         this->btn_BreakStartSound->Size = System::Drawing::Size(42, 21);
         this->btn_BreakStartSound->TabIndex = 22;
         this->btn_BreakStartSound->Text = L"Test";
         this->btn_BreakStartSound->UseVisualStyleBackColor = true;
         this->btn_BreakStartSound->Click += gcnew System::EventHandler(this, &appOptions::OnBtnBreakStart);
         // 
         // cbEndBreak
         // 
         this->cbEndBreak->DropDownWidth = 400;
         this->cbEndBreak->FormattingEnabled = true;
         this->cbEndBreak->Location = System::Drawing::Point(94, 103);
         this->cbEndBreak->MaxDropDownItems = 20;
         this->cbEndBreak->Name = L"cbEndBreak";
         this->cbEndBreak->Size = System::Drawing::Size(247, 21);
         this->cbEndBreak->TabIndex = 21;
         this->cbEndBreak->SelectedIndexChanged += gcnew System::EventHandler(this, &appOptions::OnCbEndBreakChanged);
         // 
         // cbStartBreak
         // 
         this->cbStartBreak->DropDownWidth = 400;
         this->cbStartBreak->FormattingEnabled = true;
         this->cbStartBreak->Location = System::Drawing::Point(94, 76);
         this->cbStartBreak->MaxDropDownItems = 20;
         this->cbStartBreak->Name = L"cbStartBreak";
         this->cbStartBreak->Size = System::Drawing::Size(247, 21);
         this->cbStartBreak->TabIndex = 20;
         this->cbStartBreak->SelectedIndexChanged += gcnew System::EventHandler(this, &appOptions::OnCbBreakStartChanged);
         // 
         // label10
         // 
         this->label10->AutoSize = true;
         this->label10->Location = System::Drawing::Point(13, 106);
         this->label10->Name = L"label10";
         this->label10->Size = System::Drawing::Size(57, 13);
         this->label10->TabIndex = 19;
         this->label10->Text = L"Break End";
         // 
         // label11
         // 
         this->label11->AutoSize = true;
         this->label11->Location = System::Drawing::Point(13, 82);
         this->label11->Name = L"label11";
         this->label11->Size = System::Drawing::Size(60, 13);
         this->label11->TabIndex = 18;
         this->label11->Text = L"Break Start";
         // 
         // btn_workEndSound
         // 
         this->btn_workEndSound->Location = System::Drawing::Point(347, 51);
         this->btn_workEndSound->Name = L"btn_workEndSound";
         this->btn_workEndSound->Size = System::Drawing::Size(42, 21);
         this->btn_workEndSound->TabIndex = 17;
         this->btn_workEndSound->Text = L"Test";
         this->btn_workEndSound->UseVisualStyleBackColor = true;
         this->btn_workEndSound->Click += gcnew System::EventHandler(this, &appOptions::OnBtnEndWork);
         // 
         // btnWorkStartSound
         // 
         this->btnWorkStartSound->Location = System::Drawing::Point(347, 24);
         this->btnWorkStartSound->Name = L"btnWorkStartSound";
         this->btnWorkStartSound->Size = System::Drawing::Size(42, 21);
         this->btnWorkStartSound->TabIndex = 16;
         this->btnWorkStartSound->Text = L"Test";
         this->btnWorkStartSound->UseVisualStyleBackColor = true;
         this->btnWorkStartSound->Click += gcnew System::EventHandler(this, &appOptions::OnBtnStartWork);
         // 
         // cbEndWork
         // 
         this->cbEndWork->DropDownWidth = 400;
         this->cbEndWork->FormattingEnabled = true;
         this->cbEndWork->Location = System::Drawing::Point(94, 51);
         this->cbEndWork->MaxDropDownItems = 20;
         this->cbEndWork->Name = L"cbEndWork";
         this->cbEndWork->Size = System::Drawing::Size(247, 21);
         this->cbEndWork->TabIndex = 15;
         this->cbEndWork->SelectedIndexChanged += gcnew System::EventHandler(this, &appOptions::OnCbWorkEndChanged);
         // 
         // cbStartWork
         // 
         this->cbStartWork->DropDownWidth = 400;
         this->cbStartWork->FormattingEnabled = true;
         this->cbStartWork->Location = System::Drawing::Point(94, 24);
         this->cbStartWork->MaxDropDownItems = 20;
         this->cbStartWork->Name = L"cbStartWork";
         this->cbStartWork->Size = System::Drawing::Size(247, 21);
         this->cbStartWork->TabIndex = 14;
         this->cbStartWork->SelectedIndexChanged += gcnew System::EventHandler(this, &appOptions::OnCbStartWorkChanged);
         // 
         // label8
         // 
         this->label8->AutoSize = true;
         this->label8->Location = System::Drawing::Point(13, 54);
         this->label8->Name = L"label8";
         this->label8->Size = System::Drawing::Size(55, 13);
         this->label8->TabIndex = 13;
         this->label8->Text = L"Work End";
         // 
         // label9
         // 
         this->label9->AutoSize = true;
         this->label9->Location = System::Drawing::Point(13, 30);
         this->label9->Name = L"label9";
         this->label9->Size = System::Drawing::Size(58, 13);
         this->label9->TabIndex = 12;
         this->label9->Text = L"Work Start";
         // 
         // label7
         // 
         this->label7->AutoSize = true;
         this->label7->Location = System::Drawing::Point(13, 214);
         this->label7->Name = L"label7";
         this->label7->Size = System::Drawing::Size(29, 13);
         this->label7->TabIndex = 11;
         this->label7->Text = L"Error";
         // 
         // label6
         // 
         this->label6->AutoSize = true;
         this->label6->Location = System::Drawing::Point(13, 188);
         this->label6->Name = L"label6";
         this->label6->Size = System::Drawing::Size(47, 13);
         this->label6->TabIndex = 10;
         this->label6->Text = L"Warning";
         // 
         // btnTestErrorSound
         // 
         this->btnTestErrorSound->Location = System::Drawing::Point(347, 210);
         this->btnTestErrorSound->Name = L"btnTestErrorSound";
         this->btnTestErrorSound->Size = System::Drawing::Size(42, 21);
         this->btnTestErrorSound->TabIndex = 9;
         this->btnTestErrorSound->Text = L"Test";
         this->btnTestErrorSound->UseVisualStyleBackColor = true;
         this->btnTestErrorSound->Click += gcnew System::EventHandler(this, &appOptions::OnTestErrorSound);
         // 
         // btnTestWarnSound
         // 
         this->btnTestWarnSound->Location = System::Drawing::Point(347, 184);
         this->btnTestWarnSound->Name = L"btnTestWarnSound";
         this->btnTestWarnSound->Size = System::Drawing::Size(42, 21);
         this->btnTestWarnSound->TabIndex = 8;
         this->btnTestWarnSound->Text = L"Test";
         this->btnTestWarnSound->UseVisualStyleBackColor = true;
         this->btnTestWarnSound->Click += gcnew System::EventHandler(this, &appOptions::OnTestWarnSound);
         // 
         // cbErrorSounds
         // 
         this->cbErrorSounds->DropDownWidth = 400;
         this->cbErrorSounds->FormattingEnabled = true;
         this->cbErrorSounds->Location = System::Drawing::Point(94, 211);
         this->cbErrorSounds->MaxDropDownItems = 20;
         this->cbErrorSounds->Name = L"cbErrorSounds";
         this->cbErrorSounds->Size = System::Drawing::Size(247, 21);
         this->cbErrorSounds->TabIndex = 7;
         this->cbErrorSounds->SelectedIndexChanged += gcnew System::EventHandler(this, &appOptions::OnCbErrorChanged);
         // 
         // cbWarnSounds
         // 
         this->cbWarnSounds->DropDownWidth = 400;
         this->cbWarnSounds->FormattingEnabled = true;
         this->cbWarnSounds->Location = System::Drawing::Point(94, 184);
         this->cbWarnSounds->MaxDropDownItems = 20;
         this->cbWarnSounds->Name = L"cbWarnSounds";
         this->cbWarnSounds->Size = System::Drawing::Size(247, 21);
         this->cbWarnSounds->TabIndex = 6;
         this->cbWarnSounds->SelectedIndexChanged += gcnew System::EventHandler(this, &appOptions::OnCbWarnCanged);
         // 
         // btnTestOkaySound
         // 
         this->btnTestOkaySound->Location = System::Drawing::Point(347, 157);
         this->btnTestOkaySound->Name = L"btnTestOkaySound";
         this->btnTestOkaySound->Size = System::Drawing::Size(42, 21);
         this->btnTestOkaySound->TabIndex = 5;
         this->btnTestOkaySound->Text = L"Test";
         this->btnTestOkaySound->UseVisualStyleBackColor = true;
         this->btnTestOkaySound->Click += gcnew System::EventHandler(this, &appOptions::OnTestOkaySound);
         // 
         // btnTestFailedSound
         // 
         this->btnTestFailedSound->Location = System::Drawing::Point(347, 130);
         this->btnTestFailedSound->Name = L"btnTestFailedSound";
         this->btnTestFailedSound->Size = System::Drawing::Size(42, 21);
         this->btnTestFailedSound->TabIndex = 4;
         this->btnTestFailedSound->Text = L"Test";
         this->btnTestFailedSound->UseVisualStyleBackColor = true;
         this->btnTestFailedSound->Click += gcnew System::EventHandler(this, &appOptions::OnTestFailedSound);
         // 
         // cbOkaySounds
         // 
         this->cbOkaySounds->DropDownWidth = 400;
         this->cbOkaySounds->FormattingEnabled = true;
         this->cbOkaySounds->Location = System::Drawing::Point(94, 157);
         this->cbOkaySounds->MaxDropDownItems = 20;
         this->cbOkaySounds->Name = L"cbOkaySounds";
         this->cbOkaySounds->Size = System::Drawing::Size(247, 21);
         this->cbOkaySounds->TabIndex = 3;
         this->cbOkaySounds->SelectedIndexChanged += gcnew System::EventHandler(this, &appOptions::OnCbOkayChanged);
         // 
         // cbFailedSounds
         // 
         this->cbFailedSounds->DropDownWidth = 400;
         this->cbFailedSounds->FormattingEnabled = true;
         this->cbFailedSounds->Location = System::Drawing::Point(94, 130);
         this->cbFailedSounds->MaxDropDownItems = 20;
         this->cbFailedSounds->Name = L"cbFailedSounds";
         this->cbFailedSounds->Size = System::Drawing::Size(247, 21);
         this->cbFailedSounds->TabIndex = 2;
         this->cbFailedSounds->SelectedIndexChanged += gcnew System::EventHandler(this, &appOptions::OnCbFailedChanged);
         // 
         // label5
         // 
         this->label5->AutoSize = true;
         this->label5->Location = System::Drawing::Point(13, 160);
         this->label5->Name = L"label5";
         this->label5->Size = System::Drawing::Size(62, 13);
         this->label5->TabIndex = 1;
         this->label5->Text = L"Absensi OK";
         // 
         // label4
         // 
         this->label4->AutoSize = true;
         this->label4->Location = System::Drawing::Point(13, 136);
         this->label4->Name = L"label4";
         this->label4->Size = System::Drawing::Size(75, 13);
         this->label4->TabIndex = 0;
         this->label4->Text = L"Absensi Gagal";
         // 
         // cmdApply
         // 
         this->cmdApply->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
         this->cmdApply->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
         this->cmdApply->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
         this->cmdApply->Location = System::Drawing::Point(264, 319);
         this->cmdApply->Name = L"cmdApply";
         this->cmdApply->Size = System::Drawing::Size(78, 23);
         this->cmdApply->TabIndex = 1;
         this->cmdApply->Text = L"Apply";
         this->cmdApply->UseVisualStyleBackColor = true;
         this->cmdApply->Click += gcnew System::EventHandler(this, &appOptions::cmdApply_Click);
         // 
         // cmdOK
         // 
         this->cmdOK->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
         this->cmdOK->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
         this->cmdOK->Location = System::Drawing::Point(344, 319);
         this->cmdOK->Name = L"cmdOK";
         this->cmdOK->Size = System::Drawing::Size(72, 23);
         this->cmdOK->TabIndex = 2;
         this->cmdOK->Text = L"OK";
         this->cmdOK->UseVisualStyleBackColor = true;
         this->cmdOK->Click += gcnew System::EventHandler(this, &appOptions::cmdOK_Click);
         // 
         // appOptions
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(421, 354);
         this->Controls->Add(this->cmdOK);
         this->Controls->Add(this->cmdApply);
         this->Controls->Add(this->nbOptions);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
         this->MaximizeBox = false;
         this->Name = L"appOptions";
         this->ShowIcon = false;
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"Options";
         this->Load += gcnew System::EventHandler(this, &appOptions::appOptions_Load);
         this->nbOptions->ResumeLayout(false);
         this->nbGeneralOptions->ResumeLayout(false);
         this->grpBoxSite->ResumeLayout(false);
         this->grpBoxSite->PerformLayout();
         this->nbDatabaseOptions->ResumeLayout(false);
         this->nbDatabaseOptions->PerformLayout();
         this->grpBoxDBConn->ResumeLayout(false);
         this->grpBoxDBConn->PerformLayout();
         this->nbMiscellaneousOptions->ResumeLayout(false);
         this->grpGreeting->ResumeLayout(false);
         this->grpGreeting->PerformLayout();
         this->grpBoxLogging->ResumeLayout(false);
         this->grpBoxLogging->PerformLayout();
         this->nbEventsOptions->ResumeLayout(false);
         this->gprSounds->ResumeLayout(false);
         this->gprSounds->PerformLayout();
         this->ResumeLayout(false);

      }
#pragma endregion


/** Save values in controls to appSettings class.*/
private: System::Void SaveControlsValue();
/** Load values from appSettings class.*/
private: System::Void LoadControlsValue();

/** Event Handlers. */
private: System::Void txtLogFile_DoubleClick(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void cbLoggingLevel_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void txtUserName_TextChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void txtPassword_TextChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void txtServer_TextChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void txtPort_TextChanged(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void cmdApply_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void cmdOK_Click(System::Object^  sender, System::EventArgs^  e);


private: System::Void appOptions_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnEnableLogToDatabase(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnTestFailedSound(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnTestOkaySound(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnTestWarnSound(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnTestErrorSound(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnCbFailedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnCbOkayChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnCbWarnCanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnCbErrorChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnBtnStartWork(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnBtnEndWork(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnBtnBreakStart(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnBtnEndBreak(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnCbStartWorkChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnCbWorkEndChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnCbBreakStartChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnCbEndBreakChanged(System::Object^  sender, System::EventArgs^  e);
};
