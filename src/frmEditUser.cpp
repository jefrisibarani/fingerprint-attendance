#include "StdAfx.h"

#include "fingerprint.h"
#include "frmEditUser.h"
#include "frmRegisterTemplate.h"
#include "utils.h"

using namespace FingerPrint;

frmEditUser::frmEditUser(void)
{
	InitializeComponent();

   if ( GetUserList() )
   {
      this->m_cbSelectUser->Items->Clear();
      this->m_cbSelectUser->Items->AddRange(m_userNameArray);
   }

}
System::Void frmEditUser::OnCancel(System::Object^  sender, System::EventArgs^  e) 
{
     this->Close();
}
System::Void frmEditUser::OnEdit(System::Object^  sender, System::EventArgs^  e) 
{
	CreateFormEdit(false);
}
System::Void frmEditUser::OnDisplay(System::Object^  sender, System::EventArgs^  e)
{
	bool read_only = true;
	CreateFormEdit(read_only);
}
System::Void frmEditUser::CreateFormEdit(bool readonly)
{
   // Get user verification code now
   System::String^ sql;
   sql += "SELECT verification_code from fp_template WHERE user_id = ";
   sql += JQuote(m_selectedID);
   sql += ";";

   String^ verifyCode = fingerprintApp::GetConnection()->ExecuteScalar(sql);

   frmRegisterTemplate^ editUserForm = gcnew frmRegisterTemplate();
   
   // init controls with values from database
   editUserForm->InitControlsFromDB(verifyCode);
  
   if (readonly)
	   editUserForm->DisableSomeControls();
   
   editUserForm->Show();
}

System::Void frmEditUser::OnUserSelected(System::Object^  sender, System::EventArgs^  e)
{

   int selectedIndex = m_cbSelectUser->SelectedIndex;
   Object^ selectedItem = m_cbSelectUser->SelectedItem;
   m_selectedUser = selectedItem->ToString();
   m_selectedID = m_userIDArray[selectedIndex];
   
   FP_LOGMESSAGE(String::Concat("User: " ,m_selectedUser ));
   FP_LOGMESSAGE(String::Concat("ID  :  " , m_selectedID ));
   
}
bool frmEditUser::GetUserList()
{

    string sql;
    sql+="SELECT user_id, user_name FROM fp_karyawan ORDER BY user_name;";

    try
    {

        connection &conn = *(fingerprintApp::GetConnection()->conn);
        work T(conn, "loading from sql");
        result R( T.exec( sql ));

        FP_LOGMESSAGE(gcnew String(sql.c_str()),LOG_SQL);

        if (R.empty())
        {
            FP_LOGMESSAGE("No user", LOG_ERROR);
            return false;
        }
        
         int nRows = (int)R.size();
         m_userNameArray = gcnew array<System::String^>(nRows);
         m_userIDArray = gcnew array<System::String^>(nRows);

         for (result::size_type row = 0; row != R.size(); ++row)
         {

            int r = int(row);
            m_userIDArray[row]   = gcnew System::String( R[r][0].c_str() );
            m_userNameArray[row]   = gcnew System::String( R[r][1].c_str() );
         }

    }
    catch (const sql_error &e)
    {
        FP_LOGMESSAGE( gcnew System::String(e.what()), LOG_ERROR  );
        FP_LOGMESSAGE( gcnew System::String(e.query().c_str() ) , LOG_SQL);
        return false;
    }
    catch (...)
    {
        FP_LOGMESSAGE("Unknown error occured, Operation cancelled", LOG_ERROR);
        return false;
    }

    return true;
}
