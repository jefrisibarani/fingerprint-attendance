#include "StdAfx.h"

#include "fingerprint.h"
#include "fpOperator.h"
#include "utils.h"

using namespace FingerPrint;
using namespace System;
fpOperator::fpOperator(void)
{
   Create();
}

fpOperator::fpOperator(String^ login_name,String^ passwd)
{
   Create();
   m_name = login_name;
   m_passwd = passwd;
}
void fpOperator::Create()
{
   m_name = String::Empty;
   m_passwd = String::Empty;
   m_privileges = ABSEN_ONLY;

   m_db_name = String::Empty;
   m_db_privileges = String::Empty;
   m_db_canLogin = String::Empty;
   m_db_userID = String::Empty;
   m_db_passwd = String::Empty;
}

bool fpOperator::Init()
{
   std::string sql;
  
  sql += "SELECT login_name, privileges_level,can_login,fp_karyawan.user_id,fp_karyawan.user_password ";
  sql += "FROM fp_operator INNER JOIN fp_karyawan ON ( fp_operator.user_id = fp_karyawan.user_id ) ";
  sql += "WHERE login_name = ";
  sql+= "'"+ ToBasicString(m_name) + "'";

    try
    {

        connection &conn = *(fingerprintApp::GetConnection()->conn);
        work T(conn, "loading fp_Operator");
        result R( T.exec( sql ));

        FP_LOGMESSAGE(gcnew String(sql.c_str()),LOG_SQL);

        if (R.empty())
        {
            FP_LOGMESSAGE("User name tidak terdaftar ", LOG_ERROR);
            return false;
        }
         // DO NOT CHANGE THE ORDER !!  
         m_db_name         = gcnew String( R[0][0].c_str() );
         m_db_privileges   = gcnew String( R[0][1].c_str() );
         m_db_canLogin     = gcnew String( R[0][2].c_str() );
         m_db_userID       = gcnew String( R[0][3].c_str() );
         m_db_passwd       = gcnew String( R[0][4].c_str() );

         
         if( m_db_privileges == "1" )
            m_privileges = ABSEN_ONLY;
         if( m_db_privileges == "2" )
            m_privileges = REGISTER_ONLY;
         if( m_db_privileges == "4" )
            m_privileges = EDIT_USER_ONLY;
         if( m_db_privileges == "8" )
            m_privileges = SUPERVISOR;       
         if( m_db_privileges == "15" )
            m_privileges = ADMINISTRATOR;

    }
    catch (const sql_error &e)
    {
        FP_LOGMESSAGE( gcnew String(e.what()), LOG_ERROR  );
        FP_LOGMESSAGE( gcnew String(e.query().c_str() ) , LOG_SQL);
        return false;
    }
    catch (...)
    {
        FP_LOGMESSAGE("Unknown error occured, Operation cancelled", LOG_ERROR);
        return false;
    }
    return true;

}

bool fpOperator::Authenticate()
{
   return CheckPasswdInDatabase();
}
bool fpOperator::CheckPasswdInDatabase()
{
   if ( m_passwd == m_db_passwd )
      return true;
   else
      return false;
}


