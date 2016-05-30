/******************************************************************************
* filename : dlgNeedPassword.h
* author   : Jefri Sibarani
* created  : November 17 2006
* summary  : a modal dialog asking username and password
*
******************************************************************************/


#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace FingerPrint {

	/// <summary>
	/// Summary for dlgNeedPassword
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class dlgNeedPassword : public System::Windows::Forms::Form
	{
	public:
		dlgNeedPassword(void);
		dlgNeedPassword(bool onlyNameAndPassword);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~dlgNeedPassword()
		{
			if (components)
			{
				delete components;
			}
		}
   private: System::Windows::Forms::Label^  label1;
   protected: 
   private: System::Windows::Forms::Label^  label2;
   private: System::Windows::Forms::TextBox^  m_txtUserName;
   private: System::Windows::Forms::TextBox^  m_txtPassword;
   private: System::Windows::Forms::Button^  cmdLogin;
   private: System::Windows::Forms::Label^  label3;
   private: System::Windows::Forms::Label^  m_lblCaption;
   private: System::Windows::Forms::TabControl^  m_nbmain;

   private: System::Windows::Forms::TabPage^  m_nbTabGeneral;
   private: System::Windows::Forms::TabPage^  m_nbPageDB;
   private: System::Windows::Forms::Label^  label6;
   private: System::Windows::Forms::TextBox^  m_txtPort;

   private: System::Windows::Forms::TextBox^  m_txtDatabase;

   private: System::Windows::Forms::Label^  label4;
   private: System::Windows::Forms::Label^  label5;
   private: System::Windows::Forms::TextBox^  m_txtServer;

   private:  bool m_onlyNameAndPassword;





	private:
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
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->m_txtUserName = (gcnew System::Windows::Forms::TextBox());
         this->m_txtPassword = (gcnew System::Windows::Forms::TextBox());
         this->cmdLogin = (gcnew System::Windows::Forms::Button());
         this->label3 = (gcnew System::Windows::Forms::Label());
         this->m_lblCaption = (gcnew System::Windows::Forms::Label());
         this->m_nbmain = (gcnew System::Windows::Forms::TabControl());
         this->m_nbTabGeneral = (gcnew System::Windows::Forms::TabPage());
         this->m_nbPageDB = (gcnew System::Windows::Forms::TabPage());
         this->label6 = (gcnew System::Windows::Forms::Label());
         this->m_txtPort = (gcnew System::Windows::Forms::TextBox());
         this->m_txtDatabase = (gcnew System::Windows::Forms::TextBox());
         this->label4 = (gcnew System::Windows::Forms::Label());
         this->label5 = (gcnew System::Windows::Forms::Label());
         this->m_txtServer = (gcnew System::Windows::Forms::TextBox());
         this->m_nbmain->SuspendLayout();
         this->m_nbTabGeneral->SuspendLayout();
         this->m_nbPageDB->SuspendLayout();
         this->SuspendLayout();
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->label1->Location = System::Drawing::Point(14, 22);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(69, 13);
         this->label1->TabIndex = 0;
         this->label1->Text = L"User Name";
         // 
         // label2
         // 
         this->label2->AutoSize = true;
         this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->label2->Location = System::Drawing::Point(14, 48);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(61, 13);
         this->label2->TabIndex = 1;
         this->label2->Text = L"Password";
         // 
         // m_txtUserName
         // 
         this->m_txtUserName->Location = System::Drawing::Point(96, 19);
         this->m_txtUserName->MaxLength = 20;
         this->m_txtUserName->Name = L"m_txtUserName";
         this->m_txtUserName->Size = System::Drawing::Size(163, 20);
         this->m_txtUserName->TabIndex = 1;
         this->m_txtUserName->Text = L"absen";
         this->m_txtUserName->Leave += gcnew System::EventHandler(this, &dlgNeedPassword::OnTxtUserNameLeave);
         // 
         // m_txtPassword
         // 
         this->m_txtPassword->Location = System::Drawing::Point(96, 45);
         this->m_txtPassword->MaxLength = 20;
         this->m_txtPassword->Name = L"m_txtPassword";
         this->m_txtPassword->Size = System::Drawing::Size(163, 20);
         this->m_txtPassword->TabIndex = 2;
         this->m_txtPassword->UseSystemPasswordChar = true;
         this->m_txtPassword->Leave += gcnew System::EventHandler(this, &dlgNeedPassword::OnTxtPasswordLeave);
         // 
         // cmdLogin
         // 
         this->cmdLogin->DialogResult = System::Windows::Forms::DialogResult::OK;
         this->cmdLogin->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
         this->cmdLogin->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
         this->cmdLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->cmdLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->cmdLogin->Location = System::Drawing::Point(295, 88);
         this->cmdLogin->Name = L"cmdLogin";
         this->cmdLogin->Size = System::Drawing::Size(84, 90);
         this->cmdLogin->TabIndex = 3;
         this->cmdLogin->Text = L"Login";
         this->cmdLogin->UseVisualStyleBackColor = true;
         this->cmdLogin->Click += gcnew System::EventHandler(this, &dlgNeedPassword::OnCmdLoginClick);
         // 
         // label3
         // 
         this->label3->AutoSize = true;
         this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->label3->Location = System::Drawing::Point(12, 9);
         this->label3->Name = L"label3";
         this->label3->Size = System::Drawing::Size(0, 13);
         this->label3->TabIndex = 4;
         // 
         // m_lblCaption
         // 
         this->m_lblCaption->BackColor = System::Drawing::Color::DimGray;
         this->m_lblCaption->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_lblCaption->ForeColor = System::Drawing::Color::Wheat;
         this->m_lblCaption->Location = System::Drawing::Point(4, 1);
         this->m_lblCaption->Name = L"m_lblCaption";
         this->m_lblCaption->Size = System::Drawing::Size(393, 61);
         this->m_lblCaption->TabIndex = 5;
         this->m_lblCaption->Text = L"Type your username and password to continue";
         this->m_lblCaption->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
         // 
         // m_nbmain
         // 
         this->m_nbmain->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
         this->m_nbmain->Controls->Add(this->m_nbTabGeneral);
         this->m_nbmain->Controls->Add(this->m_nbPageDB);
         this->m_nbmain->Location = System::Drawing::Point(4, 63);
         this->m_nbmain->Name = L"m_nbmain";
         this->m_nbmain->SelectedIndex = 0;
         this->m_nbmain->Size = System::Drawing::Size(289, 119);
         this->m_nbmain->TabIndex = 6;
         // 
         // m_nbTabGeneral
         // 
         this->m_nbTabGeneral->Controls->Add(this->m_txtUserName);
         this->m_nbTabGeneral->Controls->Add(this->label1);
         this->m_nbTabGeneral->Controls->Add(this->label2);
         this->m_nbTabGeneral->Controls->Add(this->m_txtPassword);
         this->m_nbTabGeneral->Location = System::Drawing::Point(4, 25);
         this->m_nbTabGeneral->Name = L"m_nbTabGeneral";
         this->m_nbTabGeneral->Padding = System::Windows::Forms::Padding(3);
         this->m_nbTabGeneral->Size = System::Drawing::Size(281, 90);
         this->m_nbTabGeneral->TabIndex = 0;
         this->m_nbTabGeneral->Text = L"General";
         this->m_nbTabGeneral->UseVisualStyleBackColor = true;
         // 
         // m_nbPageDB
         // 
         this->m_nbPageDB->Controls->Add(this->label6);
         this->m_nbPageDB->Controls->Add(this->m_txtPort);
         this->m_nbPageDB->Controls->Add(this->m_txtDatabase);
         this->m_nbPageDB->Controls->Add(this->label4);
         this->m_nbPageDB->Controls->Add(this->label5);
         this->m_nbPageDB->Controls->Add(this->m_txtServer);
         this->m_nbPageDB->Location = System::Drawing::Point(4, 25);
         this->m_nbPageDB->Name = L"m_nbPageDB";
         this->m_nbPageDB->Padding = System::Windows::Forms::Padding(3);
         this->m_nbPageDB->Size = System::Drawing::Size(281, 90);
         this->m_nbPageDB->TabIndex = 1;
         this->m_nbPageDB->Text = L"Database";
         this->m_nbPageDB->UseVisualStyleBackColor = true;
         // 
         // label6
         // 
         this->label6->AutoSize = true;
         this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->label6->Location = System::Drawing::Point(14, 64);
         this->label6->Name = L"label6";
         this->label6->Size = System::Drawing::Size(30, 13);
         this->label6->TabIndex = 7;
         this->label6->Text = L"Port";
         // 
         // m_txtPort
         // 
         this->m_txtPort->Location = System::Drawing::Point(96, 61);
         this->m_txtPort->MaxLength = 4;
         this->m_txtPort->Name = L"m_txtPort";
         this->m_txtPort->Size = System::Drawing::Size(163, 20);
         this->m_txtPort->TabIndex = 8;
         // 
         // m_txtDatabase
         // 
         this->m_txtDatabase->Location = System::Drawing::Point(96, 9);
         this->m_txtDatabase->MaxLength = 20;
         this->m_txtDatabase->Name = L"m_txtDatabase";
         this->m_txtDatabase->Size = System::Drawing::Size(163, 20);
         this->m_txtDatabase->TabIndex = 5;
         // 
         // label4
         // 
         this->label4->AutoSize = true;
         this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->label4->Location = System::Drawing::Point(14, 12);
         this->label4->Name = L"label4";
         this->label4->Size = System::Drawing::Size(61, 13);
         this->label4->TabIndex = 3;
         this->label4->Text = L"Database";
         // 
         // label5
         // 
         this->label5->AutoSize = true;
         this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->label5->Location = System::Drawing::Point(14, 38);
         this->label5->Name = L"label5";
         this->label5->Size = System::Drawing::Size(44, 13);
         this->label5->TabIndex = 4;
         this->label5->Text = L"Server";
         // 
         // m_txtServer
         // 
         this->m_txtServer->Location = System::Drawing::Point(96, 35);
         this->m_txtServer->MaxLength = 20;
         this->m_txtServer->Name = L"m_txtServer";
         this->m_txtServer->Size = System::Drawing::Size(163, 20);
         this->m_txtServer->TabIndex = 6;
         // 
         // dlgNeedPassword
         // 
         this->AcceptButton = this->cmdLogin;
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->BackColor = System::Drawing::SystemColors::Control;
         this->ClientSize = System::Drawing::Size(386, 180);
         this->Controls->Add(this->m_nbmain);
         this->Controls->Add(this->m_lblCaption);
         this->Controls->Add(this->label3);
         this->Controls->Add(this->cmdLogin);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
         this->MaximizeBox = false;
         this->MinimizeBox = false;
         this->Name = L"dlgNeedPassword";
         this->ShowIcon = false;
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &dlgNeedPassword::OnFormKeyPress);
         this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &dlgNeedPassword::OnFormKeyDown);
         this->m_nbmain->ResumeLayout(false);
         this->m_nbTabGeneral->ResumeLayout(false);
         this->m_nbTabGeneral->PerformLayout();
         this->m_nbPageDB->ResumeLayout(false);
         this->m_nbPageDB->PerformLayout();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion


public:
   System::String^ Username();
   System::String^ Password();
   System::String^ Database();
   System::String^ Server();
   System::String^ Port();
   
private: System::Void FillDefaultFormValue();
private: System::Void OnTxtUserNameLeave(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnTxtPasswordLeave(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnCmdLoginClick(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnFormKeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
private: System::Void OnFormKeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
};
}
