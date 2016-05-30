/******************************************************************************
* filename : libpqxxConn.h
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : a simple libpqxx connection class wrapper
*
******************************************************************************/

#pragma once
#include <pqxx/pqxx>

using namespace PGSTD;
using namespace pqxx;


class pqxxConn
{
public:
    pqxxConn(void);
    pqxxConn(const string host,
             const string database,
             const string username,
             const string password,
             int port);

    ~pqxxConn();

    /** Connect to database.
     * Use this if we use standard constructor, pqxxConn()
     */
    bool Connect( const string host,
                  const string database,
                  const string username,
                  const string password,
                  int port);
    
    /** Connect to database.
     * Use this if we use parameterized constructor, pqxxConn(value...)
     */
    bool Connect();


    bool DoConnect();
    pqxx::connection *conn;
    pqxx::lazyconnection *lazyConn;
    string GetConnStr();
    void Close();
	bool IsOpen();
    
	
   bool ExecuteSQL(System::String^ sql);
   
   /// execute SELECT to database, if no result returned , return false.
   bool ExecuteVoid(System::String^ sql);
	/// Inserts to table.
	/// Calls PutDataToDB()
	bool ExecuteInsert(System::String^ sql);
	/// Updates tables
	/// Calls PutDataToDB()
	bool ExecuteUpdate(System::String^ sql);
	/// Actually insert or update.
	bool PutDataToDB(System::String^ sql);

   System::String^  ExecuteScalar(System::String^ sql);

   
   bool IsConnected;
    
private:
    string m_connstr;
    string m_connstr_encrypted;
    string m_host;
    string m_database;
    string m_username;
    string m_password;
    int m_port;

};




