#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace FingerPrint {

   enum timeConversionMode
   {
      READ_FROM_BINARY = 0,
      TIME_TO_BINARY
   };



	/// <summary>
	/// Summary for frmAdminTools
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class frmAdminTools : public System::Windows::Forms::Form
	{
	public:
		frmAdminTools(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmAdminTools()
		{
			if (components)
			{
				delete components;
			}
		}
   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::TextBox^  m_txtconversionsource;
   protected: 

   private: System::Windows::Forms::Button^  m_btnDotimeConversion;

   private: System::Windows::Forms::Label^  label2;
   private: System::Windows::Forms::Label^  m_lblTimeConversionResult;
   private: System::Windows::Forms::GroupBox^  m_grpTimeConversion;

   private: System::Windows::Forms::Label^  label3;
   private: System::Windows::Forms::ComboBox^  m_cbConversionMode;
   private: System::Windows::Forms::TabControl^  m_nbMain;
   private: System::Windows::Forms::TabPage^  m_nbUsersPage;
   private: System::Windows::Forms::TabPage^  m_nbToolsPage;

   private: timeConversionMode m_convertMode;
   
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
         this->m_txtconversionsource = (gcnew System::Windows::Forms::TextBox());
         this->m_btnDotimeConversion = (gcnew System::Windows::Forms::Button());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->m_lblTimeConversionResult = (gcnew System::Windows::Forms::Label());
         this->m_grpTimeConversion = (gcnew System::Windows::Forms::GroupBox());
         this->label3 = (gcnew System::Windows::Forms::Label());
         this->m_cbConversionMode = (gcnew System::Windows::Forms::ComboBox());
         this->m_nbMain = (gcnew System::Windows::Forms::TabControl());
         this->m_nbUsersPage = (gcnew System::Windows::Forms::TabPage());
         this->m_nbToolsPage = (gcnew System::Windows::Forms::TabPage());
         this->m_grpTimeConversion->SuspendLayout();
         this->m_nbMain->SuspendLayout();
         this->m_nbToolsPage->SuspendLayout();
         this->SuspendLayout();
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Location = System::Drawing::Point(8, 60);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(41, 13);
         this->label1->TabIndex = 0;
         this->label1->Text = L"Source";
         // 
         // m_txtconversionsource
         // 
         this->m_txtconversionsource->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->m_txtconversionsource->Location = System::Drawing::Point(63, 58);
         this->m_txtconversionsource->Name = L"m_txtconversionsource";
         this->m_txtconversionsource->Size = System::Drawing::Size(302, 20);
         this->m_txtconversionsource->TabIndex = 1;
         // 
         // m_btnDotimeConversion
         // 
         this->m_btnDotimeConversion->Location = System::Drawing::Point(284, 29);
         this->m_btnDotimeConversion->Name = L"m_btnDotimeConversion";
         this->m_btnDotimeConversion->Size = System::Drawing::Size(80, 23);
         this->m_btnDotimeConversion->TabIndex = 2;
         this->m_btnDotimeConversion->Text = L"Convert";
         this->m_btnDotimeConversion->UseVisualStyleBackColor = true;
         this->m_btnDotimeConversion->Click += gcnew System::EventHandler(this, &frmAdminTools::OnDoConversion);
         // 
         // label2
         // 
         this->label2->AutoSize = true;
         this->label2->Location = System::Drawing::Point(8, 91);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(37, 13);
         this->label2->TabIndex = 3;
         this->label2->Text = L"Result";
         // 
         // m_lblTimeConversionResult
         // 
         this->m_lblTimeConversionResult->BackColor = System::Drawing::SystemColors::Info;
         this->m_lblTimeConversionResult->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
         this->m_lblTimeConversionResult->Location = System::Drawing::Point(62, 81);
         this->m_lblTimeConversionResult->Name = L"m_lblTimeConversionResult";
         this->m_lblTimeConversionResult->Size = System::Drawing::Size(302, 23);
         this->m_lblTimeConversionResult->TabIndex = 4;
         // 
         // m_grpTimeConversion
         // 
         this->m_grpTimeConversion->Controls->Add(this->label3);
         this->m_grpTimeConversion->Controls->Add(this->m_cbConversionMode);
         this->m_grpTimeConversion->Controls->Add(this->m_lblTimeConversionResult);
         this->m_grpTimeConversion->Controls->Add(this->label1);
         this->m_grpTimeConversion->Controls->Add(this->label2);
         this->m_grpTimeConversion->Controls->Add(this->m_txtconversionsource);
         this->m_grpTimeConversion->Controls->Add(this->m_btnDotimeConversion);
         this->m_grpTimeConversion->Location = System::Drawing::Point(10, 145);
         this->m_grpTimeConversion->Name = L"m_grpTimeConversion";
         this->m_grpTimeConversion->Size = System::Drawing::Size(429, 119);
         this->m_grpTimeConversion->TabIndex = 5;
         this->m_grpTimeConversion->TabStop = false;
         this->m_grpTimeConversion->Text = L"Time Conversion";
         // 
         // label3
         // 
         this->label3->AutoSize = true;
         this->label3->Location = System::Drawing::Point(8, 34);
         this->label3->Name = L"label3";
         this->label3->Size = System::Drawing::Size(34, 13);
         this->label3->TabIndex = 6;
         this->label3->Text = L"Mode";
         // 
         // m_cbConversionMode
         // 
         this->m_cbConversionMode->FormattingEnabled = true;
         this->m_cbConversionMode->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"READ_FROM_BINARY", L"TIME_TO_BINARY"});
         this->m_cbConversionMode->Location = System::Drawing::Point(63, 31);
         this->m_cbConversionMode->Name = L"m_cbConversionMode";
         this->m_cbConversionMode->Size = System::Drawing::Size(215, 21);
         this->m_cbConversionMode->TabIndex = 5;
         this->m_cbConversionMode->SelectedIndexChanged += gcnew System::EventHandler(this, &frmAdminTools::OnCbConversionChanged);
         // 
         // m_nbMain
         // 
         this->m_nbMain->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
         this->m_nbMain->Controls->Add(this->m_nbUsersPage);
         this->m_nbMain->Controls->Add(this->m_nbToolsPage);
         this->m_nbMain->Location = System::Drawing::Point(3, 2);
         this->m_nbMain->Name = L"m_nbMain";
         this->m_nbMain->SelectedIndex = 0;
         this->m_nbMain->Size = System::Drawing::Size(453, 299);
         this->m_nbMain->TabIndex = 6;
         // 
         // m_nbUsersPage
         // 
         this->m_nbUsersPage->Location = System::Drawing::Point(4, 25);
         this->m_nbUsersPage->Name = L"m_nbUsersPage";
         this->m_nbUsersPage->Padding = System::Windows::Forms::Padding(3);
         this->m_nbUsersPage->Size = System::Drawing::Size(445, 270);
         this->m_nbUsersPage->TabIndex = 0;
         this->m_nbUsersPage->Text = L"User and passwors";
         this->m_nbUsersPage->UseVisualStyleBackColor = true;
         // 
         // m_nbToolsPage
         // 
         this->m_nbToolsPage->Controls->Add(this->m_grpTimeConversion);
         this->m_nbToolsPage->Location = System::Drawing::Point(4, 25);
         this->m_nbToolsPage->Name = L"m_nbToolsPage";
         this->m_nbToolsPage->Padding = System::Windows::Forms::Padding(3);
         this->m_nbToolsPage->Size = System::Drawing::Size(445, 270);
         this->m_nbToolsPage->TabIndex = 1;
         this->m_nbToolsPage->Text = L"Tools";
         this->m_nbToolsPage->UseVisualStyleBackColor = true;
         // 
         // frmAdminTools
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(446, 300);
         this->Controls->Add(this->m_nbMain);
         this->Name = L"frmAdminTools";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"Administration and Tools";
         this->m_grpTimeConversion->ResumeLayout(false);
         this->m_grpTimeConversion->PerformLayout();
         this->m_nbMain->ResumeLayout(false);
         this->m_nbToolsPage->ResumeLayout(false);
         this->ResumeLayout(false);

      }
#pragma endregion
   private: System::Void OnDoConversion(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnCbConversionChanged(System::Object^  sender, System::EventArgs^  e);
};
}
