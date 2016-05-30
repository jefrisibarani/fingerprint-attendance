/******************************************************************************
* filename : dlgNeedPassword.cpp
* author   : Jefri Sibarani
* created  : November 17 2006
* summary  : a modal dialog asking username and password
*
******************************************************************************/

#include "StdAfx.h"
#include "fingerprint.h"
#include "appOptions.h"
#include "dlgNeedPassword.h"

using namespace FingerPrint;

dlgNeedPassword::dlgNeedPassword(void)
{
     m_onlyNameAndPassword = true;
     FillDefaultFormValue(); 
}
dlgNeedPassword::dlgNeedPassword(bool onlyNameAndPassword)
{
     m_onlyNameAndPassword = onlyNameAndPassword;
     FillDefaultFormValue();
}
System::Void dlgNeedPassword::FillDefaultFormValue()
{
     InitializeComponent();
     
     if ( m_onlyNameAndPassword )
        this->m_nbPageDB->Enabled = false;
     else
     {     
        this->m_nbPageDB->Enabled = true;
        this->m_txtUserName->Text = SETTINGS_MANAGER().GetDBUserName();
        this->m_txtDatabase->Text = SETTINGS_MANAGER().GetDatabase();
        this->m_txtServer->Text = SETTINGS_MANAGER().GetServer();
        String^ port = Convert::ToString( SETTINGS_MANAGER().GetServerPort() );
        this->m_txtPort->Text = port;
     }
}

System::Void dlgNeedPassword::OnTxtUserNameLeave(System::Object^  sender, System::EventArgs^  e)
{

}
System::Void dlgNeedPassword::OnTxtPasswordLeave(System::Object^  sender, System::EventArgs^  e)
{

}
System::Void dlgNeedPassword::OnCmdLoginClick(System::Object^  sender, System::EventArgs^  e)
{

}
System::Void dlgNeedPassword::OnFormKeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{

}
System::Void dlgNeedPassword::OnFormKeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
    // Only act if Esc pressed
   //if ( e->KeyCode  == Keys::Escape  )
    //{
    ////   this->Close();
    //   e->Handled = true;
    //}
    //else
    //   return;
}
System::String^ dlgNeedPassword::Username()    
{ 
   return this->m_txtUserName->Text; 
}

System::String^ dlgNeedPassword::Password()    
{ 
   return this->m_txtPassword->Text; 
}

System::String^ dlgNeedPassword::Database()
{ 
   if ( !m_onlyNameAndPassword )
      return this->m_txtDatabase->Text;
   else 
      return String::Empty;
}

System::String^ dlgNeedPassword::Server()
{ 
   if ( !m_onlyNameAndPassword )
      return this->m_txtServer->Text;
   else 
      return String::Empty;
}

System::String^ dlgNeedPassword::Port()
{ 
   if ( !m_onlyNameAndPassword )
      return this->m_txtPort->Text;
   else 
      return String::Empty;
}