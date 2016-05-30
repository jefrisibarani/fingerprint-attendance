/*****************************************************************************
* filename : fpTable.h
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : postgreSQL table class
*
*****************************************************************************/

#pragma once

#include "db/libpqxxConn.h"

using namespace System;
/** fpTable  abstract base class for postgreSQL table.
 *	This manages a table. 
 *  You must derived from this class to create an instance.
 *  You have to override DoSetColumns(), to tell the class
 *  about its columns.
 */

ref class fpTable abstract
{
public:
   /** Default Contructor.
    */
   fpTable(void);
   /** Constructor.
    * Initialize with pqxxConn* and call DoSetColumns()
	* 
	example:
	To Create a table name Karyawan with columns
	kode_karyawan, nama_karyawan, last_update, last_user

	derived from this class and override DoSetColumns()
	There is fpTableKaryawan class to seee what it does
	
	System::Void  fpTableKaryawan::DoSetColumns()
	{
	m_columns = gcnew array<String^>
               { 
                  "kode_karyawan",
                  "nama_karyawan",
                  "last_update",
                  "last_user"
               };
	}
    */
   fpTable(pqxxConn* pqxx_conn);
   /* Default destructor.
    */
   virtual ~fpTable(void);

   /** Inserts a row to table.
    * This method insert a row defined in array of string, contains its columns value
	* @param values an array of string
	* @return true if success
	* @verbatim
	  suppose we have a table with 3 columns,
	  columns #1 :   id
	  columns #2 :   name
	  columns #3 :   address
	  
	  Then to insert a record contains
	  
	  id    =  001
	  name  =  foo_user
	  addres=  Jl. Anton
	  
	  bool retCode1;
	  cli::array<String^>^ 
         fpTableSampleValListArray = gcnew array<String^>
         {
              m_userID,
              m_name,
              m_address
         };	
       fpTableSample^ sampleTable = gcnew fpTableSample(fingerprintApp::GetConnection());
       retCode1 = sampleTable->Insert(fpTableSampleValListArray);

	  @endverbatim
    */
   bool Insert( cli::array<System::String^>^ values);
   bool Update(cli::array<System::String^>^ values);
   

   System::Void  MoveNext(){}
   System::Void  MovePrevious(){}
   System::Void  MoveLast(){}
   System::Void  MoveFirst(){}
   
   virtual System::Void  SetKey( System::String^ column,System::String^ value);
   virtual System::Void  SetColumns(cli::array<System::String^>^ columns);
   virtual System::Void  SetValues(cli::array<System::String^>^ values);


protected:

   /// Do the actual Insert.
   bool DoInsert();
   
   /// Do the actual Insert.
   bool DoUpdate();

   /// Set table columns.
   /// You have to override this method in derived class.
   virtual System::Void  DoSetColumns()abstract;
 
   /// connection class.
   pqxxConn* m_pqxxConn;
   System::String^ m_colList;
   System::String^ m_valList;
   System::String^ m_key;

   /// Table name.
   System::String^ m_name;
   /// Columns array.
   cli::array<System::String^>^ m_columns;
   /// Volumn value array.
   cli::array<System::String^>^ m_values;
};


//----------------------------------------------------------------------------------------------------
/** Class for fp_template table. */
ref class fpTableTemplate : public fpTable
{
public:
   fpTableTemplate(void);
   fpTableTemplate(pqxxConn* pqxx_conn);
   virtual ~fpTableTemplate(void);

   virtual System::Void  DoSetColumns()override;
};


//----------------------------------------------------------------------------------------------------
/** Class for fp_karyawan table. */
ref class fpTableKaryawan : public fpTable
{
public:
   fpTableKaryawan(void);
   fpTableKaryawan(pqxxConn* pqxx_conn);
   virtual ~fpTableKaryawan(void);

   virtual System::Void  DoSetColumns()override;
};


//----------------------------------------------------------------------------------------------------
/** Class for fp_absensi table. */
ref class fpTableAbsensi : public fpTable
{
public:
   fpTableAbsensi(void);
   fpTableAbsensi(pqxxConn* pqxx_conn);
   virtual ~fpTableAbsensi(void);

   virtual System::Void  DoSetColumns()override;
};


//----------------------------------------------------------------------------------------------------
/** Class for fp_absen_*  table. */
ref class fpTableAbsensiUser : public fpTable
{
public:
   fpTableAbsensiUser(void);
   fpTableAbsensiUser(System::String^ tableName,pqxxConn* pqxx_conn);
   virtual ~fpTableAbsensiUser(void);

   virtual System::Void  DoSetColumns()override;
   bool AlreadyCheckIn();
};