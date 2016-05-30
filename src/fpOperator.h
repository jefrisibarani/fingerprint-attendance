#pragma once

#include "fpPrivileges.h"

namespace FingerPrint
{

ref class fpOperator
{
public:
   fpOperator(void);
   fpOperator(System::String^ login_name,System::String^ passwd);
   void Create();
   bool Init();
   bool Authenticate();
   bool CheckPasswdInDatabase();

   System::String^ GetName()                         { return m_name; }
   System::String^ GetPassword()                     { return m_passwd; }
   FingerPrint::fpPrivileges GetLevel()              { return m_privileges; }

   void SetName( System::String^ name)               { m_name = name; } 
   void SetPasswd( System::String^ passwd)           { m_passwd = passwd; }
   void Setlevel( FingerPrint::fpPrivileges level)   { m_privileges = level; }



private:

   System::String^ m_name;
   System::String^ m_passwd;
   FingerPrint::fpPrivileges m_privileges;

   System::String^  m_db_name;
   System::String^  m_db_privileges;
   System::String^  m_db_canLogin;
   System::String^  m_db_userID;
   System::String^  m_db_passwd;

};
}