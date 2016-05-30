/*****************************************************************************
* filename : fpTable.cpp
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : postgreSQL table class
*
*****************************************************************************/
#include "StdAfx.h"
#include "fpTable.h"

#include "fingerprint.h"
#include "utils.h"

using namespace System;
using namespace FingerPrint;

fpTable::fpTable(void)
{
   m_pqxxConn = NULL;
}
fpTable::fpTable(pqxxConn* pqxx_conn)
{
   if ( pqxx_conn ) 
      m_pqxxConn = pqxx_conn;
   else
      m_pqxxConn = NULL;


   m_colList = gcnew String("");   
   m_valList = gcnew String("");
   m_key     = gcnew String("");

   DoSetColumns();
}
fpTable::~fpTable(void)
{
}
System::Void  fpTable::SetColumns(cli::array<System::String^>^ columns)
{
   m_columns = columns;
}
System::Void  fpTable::SetValues(cli::array<System::String^>^ values)
{
   m_values = values;
}
System::Void  fpTable::SetKey( System::String^ column,System::String^ value)
{
   String^ key;
   key = gcnew String("");
   key = String::Concat( qtIdent(column),"=",JQuote(value) );
   m_key = key;
}
bool fpTable::Insert(cli::array<System::String^>^ values)
{
   SetValues(values);
   return DoInsert();
}
bool fpTable::Update(cli::array<System::String^>^ values)
{
   SetValues(values);
   return DoUpdate();
}
bool fpTable::DoInsert()
{
        Boolean booleanVal;
        for (int i=0 ; i <  m_columns->Length ; i++)
        {
            {
                if (! m_colList->Equals(gcnew String("") ))
                {
                    m_valList += ", ";
                    m_colList += ", ";
                }
                m_colList += qtIdent( m_columns[i] );

                if (Boolean::TryParse( m_values[i],  booleanVal ))
                    m_values[i] = ( StrToBool(m_values[i]) ? "T" : "F");

                m_valList += JQuote(m_values[i]);
            }
        }

        // build the actual SQL command for fp_template
        String^ sql_cmd = String::Concat("INSERT INTO ",
                                         qtIdent(m_name),
                                         "(" , m_colList , ") VALUES (" , m_valList ,")" );

        // execute the sql command
        //return fingerprintApp::GetConnection()->ExecuteInsert(sql_cmd);
      
		bool ok = m_pqxxConn->ExecuteInsert(sql_cmd);
		if (ok)
			bool tmp = SendSqlEmail(sql_cmd);
		return ok;

}
bool fpTable::DoUpdate()
{
    String^ valList = gcnew String("");
   
    //Boolean booleanVal;
    for (int i=0 ; i <  m_columns->Length ; i++)
    {
      {
         if (!IsEmptyString(valList) )
         {
            if (! IsEmptyString(m_values[i]) )
               valList += ", ";
         }
         if ( IsEmptyString(m_values[i]) )
         {
            m_columns[i] = String::Empty;
            m_values[i]  = String::Empty;
         }
         else
            valList += qtIdent( m_columns[i] )+ L"=" + JQuote(m_values[i]);

       }
    }

    String^ sql_cmd = String::Concat("UPDATE ",qtIdent(m_name),
                                     " SET ",valList,
                                     " WHERE ",m_key);
   
    bool ok;

    if (  IsEmptyString(valList)  )
      return true;
    else
      ok = m_pqxxConn->ExecuteUpdate(sql_cmd);

	if (ok)
		bool tmp = SendSqlEmail(sql_cmd);
	
	return ok;
}
//-----------------------------------------------------------------------------------

fpTableTemplate::fpTableTemplate(void)
{}

fpTableTemplate::fpTableTemplate(pqxxConn* pqxx_conn)
                :fpTable(pqxx_conn)
{
   m_name = L"fp_template";
   FP_LOGMESSAGE("Initializing fp_template table");
}

fpTableTemplate::~fpTableTemplate(void)
{}

System::Void  fpTableTemplate::DoSetColumns()
{
   m_columns = gcnew array<String^>
               { 
                 "verification_code",
                 "user_id",
                 "creation_time",
                 "last_operator",
                 "last_update_time",
                 "left_thumb",
                 "left_index",
                 "left_middle",
                 "left_ring",
                 "left_pinkie",
                 "right_thumb",
                 "right_index",
                 "right_middle",
                 "right_ring",
                 "right_pinkie",
                 "device_sn"
               };
}
//-----------------------------------------------------------------------------------
fpTableKaryawan::fpTableKaryawan(void)
{}

fpTableKaryawan::fpTableKaryawan(pqxxConn* pqxx_conn)
                :fpTable(pqxx_conn)
{
   m_name = L"fp_karyawan";
   FP_LOGMESSAGE("Initializing fp_karyawan table");

}

fpTableKaryawan::~fpTableKaryawan(void)
{}

System::Void  fpTableKaryawan::DoSetColumns()
{

   m_columns = gcnew array<String^>
               { 
                  "user_id",
                  "user_name",
                  "user_password",
                  "start_work_hour",
                  "end_work_hour",
                  "in_greeting",
                  "out_greeting",
                  "creation_time",
                  "last_update_time",
                  "last_operator",
                  "overtime_mode"
               };
}
//-----------------------------------------------------------------------------------

fpTableAbsensi::fpTableAbsensi(void)
{}
fpTableAbsensi::fpTableAbsensi(pqxxConn* pqxx_conn)
                :fpTable(pqxx_conn)
{
   m_name = L"fp_absensi";
   FP_LOGMESSAGE("Initializing fp_absensi table");

}
fpTableAbsensi::~fpTableAbsensi(void)
{}
System::Void  fpTableAbsensi::DoSetColumns()
{
   m_columns = gcnew array<String^>
               { 
                  "kode_karyawan",
                  "nama_karyawan",
                  "jam_absen",
                  "tipe_absen",
                  "kode_lokasi",
                  "device_sn",
                  "jumlah_coba"
               };
}
//-----------------------------------------------------------------------------------
fpTableAbsensiUser::fpTableAbsensiUser(void)
{}
fpTableAbsensiUser::fpTableAbsensiUser(System::String^ tableName,pqxxConn* pqxx_conn)
                :fpTable(pqxx_conn)
{
   m_name = tableName;
   //FP_LOGMESSAGE("Initializing fp_absensi table");
}
fpTableAbsensiUser::~fpTableAbsensiUser(void)
{}
System::Void  fpTableAbsensiUser::DoSetColumns()
{
   m_columns = gcnew array<String^>
               { 
                  "m_day",
                  "m_date",
                  "in_time",
                  "out_time"
               };
}

bool fpTableAbsensiUser::AlreadyCheckIn()
{
    // this sql code checks wether user already absen within this day
    String^ sql = String::Concat(gcnew String(L"SELECT m_date FROM "),
                                 qtIdent(m_name),
                                 gcnew String(" WHERE \"m_date\"='"),
                                 GetTimeStamp(L"d"),
                                 gcnew String("'") );

    // If the user already absen(maybe in the morning/in), and perhaps
    // this is the time to go home, just update the table

    if ( fingerprintApp::GetConnection()->ExecuteVoid(sql) )
       return true;
    else
       return false;

}
