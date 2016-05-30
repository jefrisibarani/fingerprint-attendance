/******************************************************************************
* filename : libpqxxConn.cpp
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : Contains libpqxx connection wrapper class
*
******************************************************************************/

#include "stdafx.h"
#include "db/libpqxxConn.h"
#include "fingerprint.h"
#include "utils.h"

using namespace FingerPrint;

pqxxConn::pqxxConn()
{
   conn = 0L;
}
pqxxConn::pqxxConn(const string host,
                   const string database,
                   const string username,
                   const string password,
                   int port)
{
    m_host = host;
    m_database = database;
    m_username = username;
    m_password = password;
    m_port = port;
    conn = 0L;
}

bool pqxxConn::Connect()
{
    if ( DoConnect() )
       return true;
    else
       return false;

}
bool pqxxConn::Connect( const string host,
                  const string database,
                  const string username,
                  const string password,
                  int port)
{
    m_connstr = "";
    m_connstr_encrypted = "";

    m_host = host;
    m_database = database;
    m_username = username;
    m_password = password;
    m_port = port;
      
    if ( DoConnect() )
       return true;
    else
       return false;
}
bool pqxxConn::DoConnect()
{
    // Creating Connection String...
    // add host name to connection string
    if (m_host.length() > 0 )
    {
        m_connstr += "host=";
        m_connstr += m_host;
    }
    // append database name to connection string
    if (m_database.length() > 0 )
    {
        m_connstr += " dbname=";
        m_connstr += m_database;
    }
    // append user name to connection string
    if (m_username.length() > 0 )
    {
        m_connstr += " user=";
        m_connstr += m_username;
         
    }
    // append password to connection string
    if (m_password.length() > 0 )
    {
        m_connstr += " password=";
        m_connstr_encrypted = m_connstr;

        m_connstr += m_password;
        
        String^ encryptedPasswd = ConvertToBase64String(gcnew System::String(m_password.c_str()) );
        m_connstr_encrypted += ToBasicString(encryptedPasswd);
    }
    // append server port to connection string
    if (m_port > 0)
    {
         string server_port = ToBasicString(m_port.ToString());
         m_connstr += " port=";
         m_connstr_encrypted += " port=";
         m_connstr += server_port;
         m_connstr_encrypted += server_port;
    }
    fingerprintApp::logManager.Log(gcnew System::String(m_connstr_encrypted.c_str()));
	
    // now, create the connection object
    try
    {
        conn = new connection( m_connstr);
        // activate connection now, so we can check for error(s)
        conn->activate();
        if ( conn->is_open() )
        {
            int backendPid = conn->backendpid();
            String^ log;
            log += "Connected to ";
            log += gcnew String(conn->dbname()) ;
            log += " on " + gcnew String(conn->hostname()) + " ";
            log += "with backend pid  " + backendPid.ToString();
            fingerprintApp::logManager.Log( log );
            return true;
        }
        else
            return false;
           
    }
    catch( const exception &e )
    {
       fingerprintApp::logManager.Log( gcnew String(e.what()), LOG_ERROR);
       return false;  
    }
    catch (...)
    {
        fingerprintApp::logManager.Log(" DATABASE UNKNOWN ERROR", LOG_ERROR );
        return false;
    }

}

string pqxxConn::GetConnStr()
{
    return m_connstr;
}

bool pqxxConn::IsOpen()
{
	if (!conn)
      return false;
   return conn->is_open();
}
void pqxxConn::Close()
{
   if (conn)
        conn->disconnect();
   conn = 0;
   fingerprintApp::logManager.Log( "Closing  database connection" ,LOG_INFO); 
}
bool pqxxConn::ExecuteUpdate(System::String^ sql)
{
	return PutDataToDB(sql);
}
bool pqxxConn::ExecuteInsert(System::String^ sql)
{
	return PutDataToDB(sql);
}
bool pqxxConn::PutDataToDB(System::String^ sql)
{
   String ^sqlCmd = sql;

   try
      {
         connection &conn =  *(this->conn);
         work J(conn, "saving to backend");

         fingerprintApp::logManager.Log(sqlCmd,LOG_SQL);

		   J.exec( ToBasicString(sqlCmd));
         J.commit();
     }
    catch (const sql_error &e)
    {
        fingerprintApp::logManager.Log( gcnew String(e.what()), LOG_ERROR  );
        fingerprintApp::logManager.Log( gcnew String(e.query().c_str() ) , LOG_SQL);
        return false;
    }
    catch (...)
    {
        fingerprintApp::logManager.Log("Unknown error occured", LOG_ERROR);
        return false;
    }
    return true;
}
bool pqxxConn::ExecuteVoid(System::String^ sql)
{
   bool rc;
   try
   {
        connection &conn =  *(this->conn);
        work T(conn, "find value in table");
        result R( T.exec( ToBasicString(sql) ));

        FP_LOGMESSAGE(sql,LOG_SQL);

        if (R.empty())
        {
            FP_LOGMESSAGE("No Such Value", LOG_SQL);
            rc = false;
        }
        else
           rc = true;

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
   return rc;
}

System::String^ pqxxConn::ExecuteScalar(System::String^ sql)
{
   System::String^ rc;
   rc = String::Empty;

   try
   {
        connection &conn =  *(this->conn);
        work T(conn, "get value from table");
        result R( T.exec( ToBasicString(sql) ));

        FP_LOGMESSAGE(sql,LOG_SQL);

        if (R.empty())
        {
            FP_LOGMESSAGE("No Such Value", LOG_SQL);
        }
        else
           rc = gcnew System::String(R[0][0].c_str() );

   }
   catch (const sql_error &e)
   {
        FP_LOGMESSAGE( gcnew String(e.what()), LOG_ERROR  );
        FP_LOGMESSAGE( gcnew String(e.query().c_str() ) , LOG_SQL);
        return rc;
   }
   catch (...)
   {
        FP_LOGMESSAGE("Unknown error occured, Operation cancelled", LOG_ERROR);
        return rc;
   }
   return rc;

}

bool pqxxConn::ExecuteSQL(System::String^ sql)
{
   return PutDataToDB(sql);
}

pqxxConn::~pqxxConn()
{
    Close();
}



