#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace FingerPrint {

	/// <summary>
	/// Summary for fpMessageBox
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class fpMessageBox : public System::Windows::Forms::Form
	{
	public:
		fpMessageBox(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
      
      fpMessageBox(System::String^ txtToShow,System::String^ timeToShow);


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~fpMessageBox()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  m_lblMessage;
	protected: 

	private: System::Windows::Forms::Label^  m_lblTime;


	private: System::Windows::Forms::Button^  m_cmdOK;
   private: System::Windows::Forms::RichTextBox^  richTextBox1;


	protected: 

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
         this->m_lblMessage = (gcnew System::Windows::Forms::Label());
         this->m_lblTime = (gcnew System::Windows::Forms::Label());
         this->m_cmdOK = (gcnew System::Windows::Forms::Button());
         this->SuspendLayout();
         // 
         // m_lblMessage
         // 
         this->m_lblMessage->BackColor = System::Drawing::Color::Lime;
         this->m_lblMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_lblMessage->ForeColor = System::Drawing::Color::SteelBlue;
         this->m_lblMessage->Location = System::Drawing::Point(0, -1);
         this->m_lblMessage->Margin = System::Windows::Forms::Padding(0);
         this->m_lblMessage->Name = L"m_lblMessage";
         this->m_lblMessage->Size = System::Drawing::Size(430, 201);
         this->m_lblMessage->TabIndex = 5;
         this->m_lblMessage->Text = L"Selamat, User. Absen Telah tercatat. Selamat Bekerja";
         this->m_lblMessage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
         // 
         // m_lblTime
         // 
         this->m_lblTime->BackColor = System::Drawing::Color::Teal;
         this->m_lblTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_lblTime->Location = System::Drawing::Point(0, 200);
         this->m_lblTime->Margin = System::Windows::Forms::Padding(0);
         this->m_lblTime->Name = L"m_lblTime";
         this->m_lblTime->Size = System::Drawing::Size(430, 50);
         this->m_lblTime->TabIndex = 6;
         this->m_lblTime->Text = L"08:00:00";
         this->m_lblTime->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
         // 
         // m_cmdOK
         // 
         this->m_cmdOK->DialogResult = System::Windows::Forms::DialogResult::OK;
         this->m_cmdOK->Location = System::Drawing::Point(184, 254);
         this->m_cmdOK->Name = L"m_cmdOK";
         this->m_cmdOK->Size = System::Drawing::Size(44, 23);
         this->m_cmdOK->TabIndex = 1;
         this->m_cmdOK->Text = L"OK";
         this->m_cmdOK->UseVisualStyleBackColor = true;
         this->m_cmdOK->Click += gcnew System::EventHandler(this, &fpMessageBox::m_cmdOK_Click);
         // 
         // fpMessageBox
         // 
         this->AcceptButton = this->m_cmdOK;
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->AutoSize = true;
         this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
         this->ClientSize = System::Drawing::Size(424, 278);
         this->ControlBox = false;
         this->Controls->Add(this->m_cmdOK);
         this->Controls->Add(this->m_lblTime);
         this->Controls->Add(this->m_lblMessage);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
         this->MaximizeBox = false;
         this->MinimizeBox = false;
         this->Name = L"fpMessageBox";
         this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Tag = L"     ";
         this->Text = L"Finger Verified...";
         this->TopMost = true;
         this->ResumeLayout(false);

      }
#pragma endregion
	private: System::Void m_cmdOK_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

public: 
	System::Void SetMessage(System::String^ txtToShow) 
	{
		this->m_lblMessage->Text = txtToShow;
	}
	System::Void SetTime(System::String^ timeToShow) 
	{
		this->m_lblTime->Text = timeToShow;
	}

};
}
