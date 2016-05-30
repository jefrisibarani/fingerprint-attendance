/*****************************************************************************
* filename : frmEditUser.h
* author   : Jefri Sibarani
* created  : Dec 18 2006
* summary  : fingerprint template registration form
*
*****************************************************************************/
#pragma once

//#include "fpFinger.h"

/*
#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace fingerprint {

	/// <summary>
	/// Summary for frmEditUser
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
*/
   public ref class frmEditUser : public System::Windows::Forms::Form
	{
	public:
		frmEditUser(void);
		//{
			//InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		//}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmEditUser()
		{
			if (components)
			{
				delete components;
			}
		}
   private: System::Windows::Forms::ComboBox^  m_cbSelectUser;
   protected: 
   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::Button^  m_btnDisplay;
   private: System::Windows::Forms::Button^  m_btnEdit;
   private: System::Windows::Forms::Button^  m_btnCancel;

	private:
   
      cli::array<System::String^>^                   m_userNameArray;
      cli::array<System::String^>^                   m_userIDArray;
      System::String^ m_selectedUser;
      System::String^ m_selectedID;
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
			this->m_cbSelectUser = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->m_btnDisplay = (gcnew System::Windows::Forms::Button());
			this->m_btnEdit = (gcnew System::Windows::Forms::Button());
			this->m_btnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// m_cbSelectUser
			// 
			this->m_cbSelectUser->FormattingEnabled = true;
			this->m_cbSelectUser->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Jefri", L"Anton", L"Budi", L"Kusuma"});
			this->m_cbSelectUser->Location = System::Drawing::Point(12, 36);
			this->m_cbSelectUser->Name = L"m_cbSelectUser";
			this->m_cbSelectUser->Size = System::Drawing::Size(247, 21);
			this->m_cbSelectUser->TabIndex = 0;
			this->m_cbSelectUser->SelectedIndexChanged += gcnew System::EventHandler(this, &frmEditUser::OnUserSelected);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Select users from list";
			// 
			// m_btnDisplay
			// 
			this->m_btnDisplay->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->m_btnDisplay->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->m_btnDisplay->Location = System::Drawing::Point(12, 101);
			this->m_btnDisplay->Name = L"m_btnDisplay";
			this->m_btnDisplay->Size = System::Drawing::Size(75, 23);
			this->m_btnDisplay->TabIndex = 2;
			this->m_btnDisplay->Text = L"&Display";
			this->m_btnDisplay->UseVisualStyleBackColor = true;
			this->m_btnDisplay->Click += gcnew System::EventHandler(this, &frmEditUser::OnDisplay);
			// 
			// m_btnEdit
			// 
			this->m_btnEdit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->m_btnEdit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->m_btnEdit->Location = System::Drawing::Point(104, 101);
			this->m_btnEdit->Name = L"m_btnEdit";
			this->m_btnEdit->Size = System::Drawing::Size(75, 23);
			this->m_btnEdit->TabIndex = 3;
			this->m_btnEdit->Text = L"&Edit";
			this->m_btnEdit->UseVisualStyleBackColor = true;
			this->m_btnEdit->Click += gcnew System::EventHandler(this, &frmEditUser::OnEdit);
			// 
			// m_btnCancel
			// 
			this->m_btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->m_btnCancel->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->m_btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->m_btnCancel->Location = System::Drawing::Point(190, 101);
			this->m_btnCancel->Name = L"m_btnCancel";
			this->m_btnCancel->Size = System::Drawing::Size(75, 23);
			this->m_btnCancel->TabIndex = 4;
			this->m_btnCancel->Text = L"&Cancel";
			this->m_btnCancel->UseVisualStyleBackColor = true;
			this->m_btnCancel->Click += gcnew System::EventHandler(this, &frmEditUser::OnCancel);
			// 
			// frmEditUser
			// 
			this->AcceptButton = this->m_btnDisplay;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(277, 136);
			this->Controls->Add(this->m_btnCancel);
			this->Controls->Add(this->m_btnEdit);
			this->Controls->Add(this->m_btnDisplay);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->m_cbSelectUser);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"frmEditUser";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Edit User Information";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
   private: System::Void OnCancel(System::Object^  sender, System::EventArgs^  e); 
   private: System::Void OnEdit(System::Object^  sender, System::EventArgs^  e); 
   
   private: System::Void frmEditUser::CreateFormEdit(bool readonly);
   private: bool GetUserList();

   private: System::Void OnUserSelected(System::Object^  sender, System::EventArgs^  e);
   private: System::Void OnDisplay(System::Object^  sender, System::EventArgs^  e);
};
//}
