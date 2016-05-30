/******************************************************************************
* filename : frmVerify.h
* author   : Jefri Sibarani
* created  : November 17 2006
* summary  : Form Verify class
*
******************************************************************************/


#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "fpUser.h"

namespace FingerPrint {


   /// <summary>
	/// Summary for frmVerify
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class frmVerify : public System::Windows::Forms::Form
	{
	public:
		frmVerify(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmVerify()
		{
			if (components)
			{
				delete components;
			}
		}

   private: System::Windows::Forms::StatusStrip^  m_statusBar;
   private: System::Windows::Forms::ToolStripStatusLabel^  m_statusBarLabel0;

   private: System::Windows::Forms::Label^  m_lblGuide;
   private: System::Windows::Forms::TextBox^  m_txtKodeVerifikasi;

   private: AxDPSDKOPSLib::AxFPGetTemplateX^     m_axFPGetTemplateX;
   private: bool m_currentUserDone;
   private: int m_numberOfTry;
   private: fpUser^ m_currentUser;
   private: System::Windows::Forms::Label^  lblTimeDigit;







   //private: fpVerifyFinger^ m_fpVerifyFinger;

   protected: 

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
         this->m_statusBar = (gcnew System::Windows::Forms::StatusStrip());
         this->m_statusBarLabel0 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
         this->m_lblGuide = (gcnew System::Windows::Forms::Label());
         this->m_txtKodeVerifikasi = (gcnew System::Windows::Forms::TextBox());
         this->lblTimeDigit = (gcnew System::Windows::Forms::Label());
         this->m_statusBar->SuspendLayout();
         this->SuspendLayout();
         // 
         // m_statusBar
         // 
         this->m_statusBar->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_statusBar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->m_statusBarLabel0});
         this->m_statusBar->Location = System::Drawing::Point(0, 386);
         this->m_statusBar->Name = L"m_statusBar";
         this->m_statusBar->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
         this->m_statusBar->Size = System::Drawing::Size(374, 22);
         this->m_statusBar->SizingGrip = false;
         this->m_statusBar->TabIndex = 1;
         this->m_statusBar->Text = L"Ready";
         // 
         // m_statusBarLabel0
         // 
         this->m_statusBarLabel0->ForeColor = System::Drawing::Color::Red;
         this->m_statusBarLabel0->Name = L"m_statusBarLabel0";
         this->m_statusBarLabel0->Size = System::Drawing::Size(359, 17);
         this->m_statusBarLabel0->Spring = true;
         this->m_statusBarLabel0->Text = L"Ready";
         // 
         // m_lblGuide
         // 
         this->m_lblGuide->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
            static_cast<System::Int32>(static_cast<System::Byte>(224)));
         this->m_lblGuide->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_lblGuide->ForeColor = System::Drawing::Color::DimGray;
         this->m_lblGuide->Location = System::Drawing::Point(0, 24);
         this->m_lblGuide->Margin = System::Windows::Forms::Padding(0);
         this->m_lblGuide->Name = L"m_lblGuide";
         this->m_lblGuide->Size = System::Drawing::Size(380, 97);
         this->m_lblGuide->TabIndex = 10;
         this->m_lblGuide->Text = L"Silahkan ketik kode absen anda ( 4 angka )";
         this->m_lblGuide->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
         // 
         // m_txtKodeVerifikasi
         // 
         this->m_txtKodeVerifikasi->BackColor = System::Drawing::Color::DarkGray;
         this->m_txtKodeVerifikasi->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->m_txtKodeVerifikasi->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->m_txtKodeVerifikasi->ForeColor = System::Drawing::Color::Navy;
         this->m_txtKodeVerifikasi->Location = System::Drawing::Point(4, 124);
         this->m_txtKodeVerifikasi->MaxLength = 4;
         this->m_txtKodeVerifikasi->Name = L"m_txtKodeVerifikasi";
         this->m_txtKodeVerifikasi->Size = System::Drawing::Size(168, 80);
         this->m_txtKodeVerifikasi->TabIndex = 11;
         this->m_txtKodeVerifikasi->Text = L"0000";
         this->m_txtKodeVerifikasi->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
         this->m_txtKodeVerifikasi->UseSystemPasswordChar = true;
         this->m_txtKodeVerifikasi->WordWrap = false;
         this->m_txtKodeVerifikasi->Leave += gcnew System::EventHandler(this, &frmVerify::OnTxtKodeVerifikasiLeave);
         this->m_txtKodeVerifikasi->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &frmVerify::OnTxtKodeVerifikasiKeyPress);
         this->m_txtKodeVerifikasi->TextChanged += gcnew System::EventHandler(this, &frmVerify::OnTxtKodeVerifikasiChanged);
         // 
         // lblTimeDigit
         // 
         this->lblTimeDigit->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->lblTimeDigit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
         this->lblTimeDigit->ForeColor = System::Drawing::Color::MediumBlue;
         this->lblTimeDigit->Location = System::Drawing::Point(178, 124);
         this->lblTimeDigit->Name = L"lblTimeDigit";
         this->lblTimeDigit->Size = System::Drawing::Size(196, 80);
         this->lblTimeDigit->TabIndex = 14;
         this->lblTimeDigit->Text = L"00:00";
         this->lblTimeDigit->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
         // 
         // frmVerify
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->BackColor = System::Drawing::Color::Silver;
         this->ClientSize = System::Drawing::Size(374, 408);
         this->Controls->Add(this->lblTimeDigit);
         this->Controls->Add(this->m_txtKodeVerifikasi);
         this->Controls->Add(this->m_lblGuide);
         this->Controls->Add(this->m_statusBar);
         this->ForeColor = System::Drawing::SystemColors::ControlText;
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
         this->MaximizeBox = false;
         this->Name = L"frmVerify";
         this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"Finger Verification...";
         this->TopMost = true;
         this->Shown += gcnew System::EventHandler(this, &frmVerify::OnShown);
         this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmVerify::OnClosing);
         this->Load += gcnew System::EventHandler(this, &frmVerify::OnFrmVerifyLoad);
         this->m_statusBar->ResumeLayout(false);
         this->m_statusBar->PerformLayout();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion



public:

   StatusStrip^            GetStatusBar()          { return m_statusBar; }
   ToolStripStatusLabel^   GetStatusBarLabel0()    { return m_statusBarLabel0; }
   Label^                  GetLblGuide()           { return m_lblGuide; }
   TextBox^                GetTxtCode()            { return m_txtKodeVerifikasi; }
   AxDPSDKOPSLib::AxFPGetTemplateX^  
                           GetFPGetTemplateX()     { return m_axFPGetTemplateX; }
   
   void SetTimeLabel(String^ time_label);

private: fpUser^ GetCurrentUser();
private: System::Void Verify();
private: System::Void MakeLblGuideGreen();
private: System::Void MakeLblGuideRed();
private: System::Void MakeLblGuideNormal();
private: System::Void NormalizeForm();
private: System::Void ShowFpMessageBox(System::String^ msg,System::String^ time);



private: System::Void InitFPGetTemplateX();
private: System::Void OnAxFPGetTemplateX_Done(System::Object^  sender, AxDPSDKOPSLib::_IFPGetTemplateXEvents_DoneEvent^  e);
private: System::Void OnFrmVerifyLoad(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnTxtKodeVerifikasiChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnTxtKodeVerifikasiKeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
private: System::Void OnTxtKodeVerifikasiLeave(System::Object^  sender, System::EventArgs^  e);
private: System::Void SetStatusText(System::String^ status);
private: System::Void OnShown(System::Object^  sender, System::EventArgs^  e);
private: System::Void OnClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
};
}
