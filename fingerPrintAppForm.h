/*****************************************************************************
* filename : fingerPrintAppForm.h
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : Main application form (starup form )
*
*****************************************************************************/
#pragma once

#include "frmVerify.h"

namespace FingerPrint
{

   enum fpFormID
   {
      FORM_OPTIONS =  0,
      FORM_REGISTER_TEMPLATE,
      FORM_EDIT_USER,
      FORM_ADMIN_TOOLS,
      FORM_VERIFY
   };

	/// <summary>
	/// Summary for fingerPrintAppForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class fingerPrintAppForm : public System::Windows::Forms::Form
	{
	public:
		fingerPrintAppForm(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~fingerPrintAppForm()
		{
			if (components)
			{
				delete components;
			}
		}
   private: System::Windows::Forms::StatusStrip^  statusBar;
   private: System::Windows::Forms::ToolStripStatusLabel^  statusBar_0;
   private: System::Windows::Forms::Button^  cmdRegisterTemplate;
   private: System::Windows::Forms::Button^  cmdOptions;
   private: System::Windows::Forms::Button^  cmdInformations;
   private: System::Windows::Forms::Button^  cmdConnect;
   private: System::Windows::Forms::Button^  cmdInitDevice;
   private: System::Windows::Forms::Button^  cmdLoadFrmVerify;
   private: System::Windows::Forms::Label^  label1;
   private: System::ComponentModel::BackgroundWorker^  m_bgTimeWatcher;

   private: static FingerPrint::frmVerify^ verifyForm;

   static System::Windows::Forms::Timer^ myTimer;
   static System::Windows::Forms::Timer^ m_timerLogger;

   private: System::Windows::Forms::Button^  m_btnEditUser;
   private: System::Windows::Forms::Button^  cmdPrivileges;


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
         System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(fingerPrintAppForm::typeid));
         this->statusBar = (gcnew System::Windows::Forms::StatusStrip());
         this->statusBar_0 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
         this->cmdRegisterTemplate = (gcnew System::Windows::Forms::Button());
         this->cmdOptions = (gcnew System::Windows::Forms::Button());
         this->cmdInformations = (gcnew System::Windows::Forms::Button());
         this->cmdConnect = (gcnew System::Windows::Forms::Button());
         this->cmdInitDevice = (gcnew System::Windows::Forms::Button());
         this->cmdLoadFrmVerify = (gcnew System::Windows::Forms::Button());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->m_bgTimeWatcher = (gcnew System::ComponentModel::BackgroundWorker());
         this->m_btnEditUser = (gcnew System::Windows::Forms::Button());
         this->cmdPrivileges = (gcnew System::Windows::Forms::Button());
         this->statusBar->SuspendLayout();
         this->SuspendLayout();
         // 
         // statusBar
         // 
         this->statusBar->GripMargin = System::Windows::Forms::Padding(0);
         this->statusBar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->statusBar_0});
         this->statusBar->Location = System::Drawing::Point(0, 444);
         this->statusBar->Name = L"statusBar";
         this->statusBar->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
         this->statusBar->Size = System::Drawing::Size(323, 22);
         this->statusBar->SizingGrip = false;
         this->statusBar->Stretch = false;
         this->statusBar->TabIndex = 0;
         // 
         // statusBar_0
         // 
         this->statusBar_0->AutoSize = false;
         this->statusBar_0->BorderSides = System::Windows::Forms::ToolStripStatusLabelBorderSides::Top;
         this->statusBar_0->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
         this->statusBar_0->Margin = System::Windows::Forms::Padding(0);
         this->statusBar_0->Name = L"statusBar_0";
         this->statusBar_0->Overflow = System::Windows::Forms::ToolStripItemOverflow::Always;
         this->statusBar_0->Size = System::Drawing::Size(308, 22);
         this->statusBar_0->Spring = true;
         this->statusBar_0->Text = L"Ready";
         // 
         // cmdRegisterTemplate
         // 
         this->cmdRegisterTemplate->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
         this->cmdRegisterTemplate->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
         this->cmdRegisterTemplate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->cmdRegisterTemplate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, 
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
         this->cmdRegisterTemplate->ForeColor = System::Drawing::Color::DarkOliveGreen;
         this->cmdRegisterTemplate->Location = System::Drawing::Point(10, 339);
         this->cmdRegisterTemplate->Name = L"cmdRegisterTemplate";
         this->cmdRegisterTemplate->Size = System::Drawing::Size(301, 26);
         this->cmdRegisterTemplate->TabIndex = 2;
         this->cmdRegisterTemplate->Text = L"&Pendaftaran Sidik Jari";
         this->cmdRegisterTemplate->UseVisualStyleBackColor = true;
         this->cmdRegisterTemplate->Click += gcnew System::EventHandler(this, &fingerPrintAppForm::cmdRegisterTemplate_Click);
         // 
         // cmdOptions
         // 
         this->cmdOptions->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
         this->cmdOptions->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
         this->cmdOptions->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->cmdOptions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->cmdOptions->ForeColor = System::Drawing::Color::DarkOliveGreen;
         this->cmdOptions->Location = System::Drawing::Point(10, 408);
         this->cmdOptions->Name = L"cmdOptions";
         this->cmdOptions->Size = System::Drawing::Size(83, 31);
         this->cmdOptions->TabIndex = 4;
         this->cmdOptions->Text = L"&Options";
         this->cmdOptions->UseVisualStyleBackColor = true;
         this->cmdOptions->Click += gcnew System::EventHandler(this, &fingerPrintAppForm::cmdOptions_Click);
         // 
         // cmdInformations
         // 
         this->cmdInformations->Enabled = false;
         this->cmdInformations->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
         this->cmdInformations->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
         this->cmdInformations->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->cmdInformations->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->cmdInformations->ForeColor = System::Drawing::Color::DarkOliveGreen;
         this->cmdInformations->Location = System::Drawing::Point(227, 408);
         this->cmdInformations->Name = L"cmdInformations";
         this->cmdInformations->Size = System::Drawing::Size(84, 31);
         this->cmdInformations->TabIndex = 6;
         this->cmdInformations->Text = L"&Hardware Info";
         this->cmdInformations->UseVisualStyleBackColor = true;
         this->cmdInformations->Click += gcnew System::EventHandler(this, &fingerPrintAppForm::cmdInformations_Click);
         // 
         // cmdConnect
         // 
         this->cmdConnect->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
         this->cmdConnect->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
         this->cmdConnect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->cmdConnect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->cmdConnect->ForeColor = System::Drawing::Color::DarkOliveGreen;
         this->cmdConnect->Location = System::Drawing::Point(10, 372);
         this->cmdConnect->Name = L"cmdConnect";
         this->cmdConnect->Size = System::Drawing::Size(84, 30);
         this->cmdConnect->TabIndex = 3;
         this->cmdConnect->Text = L"&Connect";
         this->cmdConnect->UseVisualStyleBackColor = true;
         this->cmdConnect->Click += gcnew System::EventHandler(this, &fingerPrintAppForm::cmdConnect_Click);
         // 
         // cmdInitDevice
         // 
         this->cmdInitDevice->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
         this->cmdInitDevice->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
         this->cmdInitDevice->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->cmdInitDevice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->cmdInitDevice->ForeColor = System::Drawing::Color::DarkOliveGreen;
         this->cmdInitDevice->Location = System::Drawing::Point(227, 370);
         this->cmdInitDevice->Name = L"cmdInitDevice";
         this->cmdInitDevice->Size = System::Drawing::Size(84, 31);
         this->cmdInitDevice->TabIndex = 5;
         this->cmdInitDevice->Text = L"&Init Device";
         this->cmdInitDevice->UseVisualStyleBackColor = true;
         this->cmdInitDevice->Click += gcnew System::EventHandler(this, &fingerPrintAppForm::cmdInitDevice_Click);
         // 
         // cmdLoadFrmVerify
         // 
         this->cmdLoadFrmVerify->BackColor = System::Drawing::Color::Silver;
         this->cmdLoadFrmVerify->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
         this->cmdLoadFrmVerify->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
         this->cmdLoadFrmVerify->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->cmdLoadFrmVerify->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->cmdLoadFrmVerify->ForeColor = System::Drawing::Color::DarkOliveGreen;
         this->cmdLoadFrmVerify->Location = System::Drawing::Point(9, 60);
         this->cmdLoadFrmVerify->Name = L"cmdLoadFrmVerify";
         this->cmdLoadFrmVerify->Size = System::Drawing::Size(302, 192);
         this->cmdLoadFrmVerify->TabIndex = 1;
         this->cmdLoadFrmVerify->Text = L"A&BSEN";
         this->cmdLoadFrmVerify->UseVisualStyleBackColor = false;
         this->cmdLoadFrmVerify->Click += gcnew System::EventHandler(this, &fingerPrintAppForm::cmdLoadFrmVerify_Click);
         // 
         // label1
         // 
         this->label1->BackColor = System::Drawing::SystemColors::ControlDark;
         this->label1->Location = System::Drawing::Point(0, 0);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(323, 23);
         this->label1->TabIndex = 8;
         // 
         // m_btnEditUser
         // 
         this->m_btnEditUser->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
         this->m_btnEditUser->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
         this->m_btnEditUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->m_btnEditUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_btnEditUser->ForeColor = System::Drawing::Color::DarkOliveGreen;
         this->m_btnEditUser->Location = System::Drawing::Point(9, 307);
         this->m_btnEditUser->Name = L"m_btnEditUser";
         this->m_btnEditUser->Size = System::Drawing::Size(302, 26);
         this->m_btnEditUser->TabIndex = 9;
         this->m_btnEditUser->Text = L"&Edit User";
         this->m_btnEditUser->UseVisualStyleBackColor = true;
         this->m_btnEditUser->Click += gcnew System::EventHandler(this, &fingerPrintAppForm::OnEditUser);
         // 
         // cmdPrivileges
         // 
         this->cmdPrivileges->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
         this->cmdPrivileges->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
         this->cmdPrivileges->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->cmdPrivileges->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->cmdPrivileges->ForeColor = System::Drawing::Color::DarkOliveGreen;
         this->cmdPrivileges->Location = System::Drawing::Point(117, 408);
         this->cmdPrivileges->Name = L"cmdPrivileges";
         this->cmdPrivileges->Size = System::Drawing::Size(84, 30);
         this->cmdPrivileges->TabIndex = 10;
         this->cmdPrivileges->Text = L"&Admin";
         this->cmdPrivileges->UseVisualStyleBackColor = true;
         this->cmdPrivileges->Click += gcnew System::EventHandler(this, &fingerPrintAppForm::OnOpenAdmin);
         // 
         // fingerPrintAppForm
         // 
         this->AcceptButton = this->cmdLoadFrmVerify;
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)));
         this->ClientSize = System::Drawing::Size(323, 466);
         this->Controls->Add(this->cmdPrivileges);
         this->Controls->Add(this->m_btnEditUser);
         this->Controls->Add(this->label1);
         this->Controls->Add(this->cmdLoadFrmVerify);
         this->Controls->Add(this->cmdInitDevice);
         this->Controls->Add(this->cmdConnect);
         this->Controls->Add(this->cmdInformations);
         this->Controls->Add(this->cmdOptions);
         this->Controls->Add(this->cmdRegisterTemplate);
         this->Controls->Add(this->statusBar);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
         this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
         this->MaximizeBox = false;
         this->Name = L"fingerPrintAppForm";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"Absen";
         this->Load += gcnew System::EventHandler(this, &fingerPrintAppForm::fingerPrintAppForm_Load);
         this->statusBar->ResumeLayout(false);
         this->statusBar->PerformLayout();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion

private: System::Void cmdRegisterTemplate_Click(System::Object^  sender, System::EventArgs^  e); 
private: System::Void cmdOptions_Click(System::Object^  sender, System::EventArgs^  e); 
private: System::Void cmdInformations_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void cmdConnect_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void cmdInitDevice_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void fingerPrintAppForm_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void cmdLoadFrmVerify_Click(System::Object^  sender, System::EventArgs^  e);

public:  System::Void DisableControls();
public:  System::Void EnableControls();
public:  static void  StopAllTimer();
public:  static void WatchTimeChange();
public:  static void LogTimeToDatabase();

private: static void TimerEventProcessor( Object^ /*myObject*/, EventArgs^ /*myEventArgs*/ );
private: static void TimeLoggerProcessor( Object^ /*myObject*/, EventArgs^ /*myEventArgs*/ );
private: System::Void OnEditUser(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnOpenAdmin(System::Object^  sender, System::EventArgs^  e);

private: System::Void OpenNewForm(fpFormID form_id);

};
}