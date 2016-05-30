/******************************************************************************
* filename : fpUser.cpp
* author   : Jefri Sibarani
* created  : November 17 2006
* summary  : user class
*
******************************************************************************/

#include "StdAfx.h"
#include "fingerprint.h"
#include "fpUtils.h"
#include "utils.h"
#include "fpVerify.h"
#include "fpTable.h"
#include "fpUser.h"

using namespace FingerPrint;
fpUser::fpUser(void)
{
    m_name       = String::Empty;
    m_userID     = String::Empty;
    m_verifyCode = String::Empty;
    m_password   = String::Empty;
   
    m_left_thumb   = String::Empty;
    m_left_index   = String::Empty;
    m_left_middle  = String::Empty;
    m_left_ring    = String::Empty;
    m_left_pinkie  = String::Empty;
    m_right_thumb  = String::Empty;
    m_right_index  = String::Empty;
    m_right_middle = String::Empty;
    m_right_ring   = String::Empty;
    m_right_pinkie = String::Empty;
    
    m_fingerTemplateArrayString = gcnew array<String^>(10);

    
    m_startWorkingHour   = String::Empty;
    m_endWorkingHour     = String::Empty;
    
    m_inGreeting         = String::Empty;
    m_outGreeting        = String::Empty;
    m_creationTime       = String::Empty;
    m_overtimeMode       = String::Empty;

    
    m_updateTime         = String::Empty;
    m_appUser            = String::Empty;

    m_recordedTime  = String::Empty;
    m_scannedFPTemplate = gcnew DpSdkEngLib::FPTemplate();

    m_operationMode = OPR_UNKNOWN;
}

System::Void fpUser::CreateNew( System::String^ name,
                        System::String^ id,
                        System::String^ code,
                        System::String^ passwd,
                        cli::array<String^>^ fingers,
                        System::String^ sw,
                        System::String^ ew,
                        System::String^ inGreet,
                        System::String^ outGreet,
                        System::String^ ot
                      )
{
    m_operationMode = OPR_REGISTER_USER;

    SetName(name);
    SetUserID(id);
    SetVerifyCode(code);
    SetPassword(passwd);
    SetFingersTemplate(fingers);
    SetStartWorkHour(sw);
    SetEndWorkHour(ew);
    SetInGreeting(inGreet);
    SetOutGreeting(outGreet);
    SetOvertimeMode(ot);
}

System::Void fpUser::SetFingersTemplate(cli::array<String^>^ fingers)
{ 
   
   m_fingerTemplateArrayString = fingers; 

   // DO NOT CHANGE THE ORDER
   m_left_thumb   = m_fingerTemplateArrayString[0];
   m_left_index   = m_fingerTemplateArrayString[1];
   m_left_middle  = m_fingerTemplateArrayString[2];
   m_left_ring    = m_fingerTemplateArrayString[3];
   m_left_pinkie  = m_fingerTemplateArrayString[4];
   m_right_thumb  = m_fingerTemplateArrayString[5];
   m_right_index  = m_fingerTemplateArrayString[6];
   m_right_middle = m_fingerTemplateArrayString[7];
   m_right_ring   = m_fingerTemplateArrayString[8];
   m_right_pinkie = m_fingerTemplateArrayString[9];
}

System::String^ fpUser::InitFromDB(System::String^ userCode)
{
    FP_LOGMESSAGE(String::Concat("fpUser::InitFromDB(): Initializing user from database"));    
    
    
    m_verifyCode = userCode;
    string kodeVerifikasi = ToBasicString(m_verifyCode);

    String^ rc;
    rc = L"USER OK";

    string sql;

    sql+="SELECT ";
    sql+="left_thumb,";
    sql+="left_index,";
    sql+="left_middle,";
    sql+="left_ring,";
    sql+="left_pinkie,";
    sql+="right_thumb,";
    sql+="right_index,";
    sql+="right_middle,";
    sql+="right_ring,";
    sql+="right_pinkie,";
    sql+="fp_karyawan.user_name,";
    sql+="fp_karyawan.user_id,";
    sql+="fp_karyawan.start_work_hour,";
    sql+="fp_karyawan.end_work_hour,";
    sql+="fp_karyawan.in_greeting,";
    sql+="fp_karyawan.out_greeting, ";
    sql+="fp_karyawan.overtime_mode ";
    sql+="FROM fp_template ";
    sql+="INNER JOIN ";
    sql+="fp_karyawan ON ";
    sql+="(fp_template.user_id = fp_karyawan.user_id) ";
    sql+="WHERE verification_code =";
    sql+= "'"+ kodeVerifikasi + "'";

    try
    {

        connection &conn = *(fingerprintApp::GetConnection()->conn);
        work T(conn, "loading from sql");
        result R( T.exec( sql ));

        FP_LOGMESSAGE(gcnew String(sql.c_str()),LOG_SQL);

        if (R.empty())
        {
            FP_LOGMESSAGE("Kode verifikasi anda salah", LOG_ERROR);
            rc = L"USER NOT EXIST, Verification Code doesn't exist";
            return rc;
        }
         // DO NOT CHANGE THE ORDER !!  
         m_left_thumb   = gcnew String( R[0][0].c_str() );
         m_left_index   = gcnew String( R[0][1].c_str() );
         m_left_middle  = gcnew String( R[0][2].c_str() );
         m_left_ring    = gcnew String( R[0][3].c_str() );
         m_left_pinkie  = gcnew String( R[0][4].c_str() );
         m_right_thumb  = gcnew String( R[0][5].c_str() );
         m_right_index  = gcnew String( R[0][6].c_str() );
         m_right_middle = gcnew String( R[0][7].c_str() );
         m_right_ring   = gcnew String( R[0][8].c_str() );
         m_right_pinkie = gcnew String( R[0][9].c_str() );

         m_name             = gcnew String( R[0][10].c_str() );
         m_userID           = gcnew String( R[0][11].c_str() );
         m_startWorkingHour = gcnew String( R[0][12].c_str() );
         m_endWorkingHour   = gcnew String( R[0][13].c_str() );
         m_inGreeting       = gcnew String( R[0][14].c_str() );
         m_outGreeting      = gcnew String( R[0][15].c_str() );
         m_overtimeMode     = gcnew String( R[0][16].c_str() );


    }
    catch (const sql_error &e)
    {
        FP_LOGMESSAGE( gcnew String(e.what()), LOG_ERROR  );
        FP_LOGMESSAGE( gcnew String(e.query().c_str() ) , LOG_SQL);
        rc = gcnew String(e.what());
        return rc;
    }
    catch (...)
    {
        FP_LOGMESSAGE("Unknown error occured, Operation cancelled", LOG_ERROR);
        rc = gcnew String("Unknown error occured, Operation cancelled");
        return rc;
    }
    return rc;
}

cli::array<String^>^ fpUser::GetFPTemplateArrayString()
{
    m_fingerTemplateArrayString = gcnew array<String^>
    {
         m_left_thumb,
         m_left_index,
         m_left_middle,
         m_left_ring,
         m_left_pinkie,
         m_right_thumb,
         m_right_index,
         m_right_middle,
         m_right_ring,
         m_right_pinkie
    };

    return m_fingerTemplateArrayString;

}
System::String^ fpUser::GetRecordedTime()
{
    return m_recordedTime;
}
System::String^ fpUser::GetGreeting()
{
    String^ congrats;
    congrats = gcnew String("Selamat, "+ m_name +
                            ".\n" + "Absen telah tercatat \n"/*+
                                                       m_recordedTime + "\n"*/);

    if ( m_operationMode == OPR_SAVE_ATTENDANCE_IN )
    {
       if ( IsEmptyString(m_inGreeting) )
          return congrats + SETTINGS_MANAGER().GetFormVerifyInGreeting();
       else
          return congrats + m_inGreeting;
    
    }
    else if ( m_operationMode == OPR_SAVE_ATTENDANCE_OUT )
    {
       if ( IsEmptyString(m_outGreeting) )
          return congrats + SETTINGS_MANAGER().GetFormVerifyOutGreeting();
       else
          return congrats + m_outGreeting;    
    }
    else
        return gcnew String(L"");
}

bool fpUser::VerifyFinger(DpSdkEngLib::FPTemplate^ scannedTemplate)
{

    FP_LOGMESSAGE(String::Concat("fpUser::VerifyFinger(): Verifiying fingerprint"));
    
    // template to be verified
    DpSdkEngLib::FPTemplate^ m_scannedFPTemplate = scannedTemplate;
    FP_LOGMESSAGE( "Scanned Verification Template Instance ID : " + m_scannedFPTemplate->InstanceID , LOG_DEBUG);

    // the FPTemplates to be compared
    DpSdkEngLib::FPTemplate^ localRegTemplate = gcnew DpSdkEngLib::FPTemplate();

    DpSdkEngLib::AIErrors errCode;

    fpVerifyTemplate^ templateChecker = gcnew fpVerifyTemplate();

    bool rc = templateChecker->CompareMultipleTemplate(GetFPTemplateArrayString(),scannedTemplate);

    errCode = templateChecker->ErrorCode();
    FP_LOGMESSAGE( "Loaded Registered Template Instance ID : " + templateChecker->RegTemplateInstanceID() );
    FP_LOGMESSAGE( "fpVerify->Compare return code = " + AIErrorsToString(errCode) );
    FP_LOGMESSAGE( "Comparison result   : " + templateChecker->ComparisonResult().ToString() );
    FP_LOGMESSAGE( "Score               : " + templateChecker->Score() );
    FP_LOGMESSAGE( "Threshold           : " + templateChecker->Threshold() );
    FP_LOGMESSAGE( "Learning            : " + templateChecker->Learning() );

    return rc;
}
bool fpUser::SaveAttendance(int try_count)
{

    FP_LOGMESSAGE(String::Concat("fpUser::SaveAttendance(): Saving ",m_name," attendance to database"));

    m_recordedTime      = GetTimeStamp(L"F");
    String^ device_sn   = fingerprintApp::GetDeviceSerialNumber();
    String^ jumlahCoba  = try_count.ToString();
    String^ tipeAbsen;
    String^ kodeLokasi = SETTINGS_MANAGER().GetOfficeLocation();

    bool rc1;
    bool rc2;

    String^ currentUserAbsenTableName = String::Concat(L"fp_absen_" ,m_userID);

    // Instantiates current user's table
    fpTableAbsensiUser^ currentUserAbsenTable = gcnew fpTableAbsensiUser(currentUserAbsenTableName,fingerprintApp::GetConnection());
    // instantiates global users table
    fpTableAbsensi^ globalAbsenTable = gcnew fpTableAbsensi(fingerprintApp::GetConnection());

    int jam_pulang_kantor = TimeToNumber( SETTINGS_MANAGER().GetEndOfficeHour() );
    if ( GetTimeInNumber() < jam_pulang_kantor )
    {
         if( !currentUserAbsenTable->AlreadyCheckIn()  )        
         {
            tipeAbsen = gcnew String("MASUK");
            m_operationMode = OPR_SAVE_ATTENDANCE_IN;
         }
         if( currentUserAbsenTable->AlreadyCheckIn()  )        
         {
            tipeAbsen = gcnew String("PULANG");
            m_operationMode = OPR_SAVE_ATTENDANCE_OUT;
         }

    }
    else
    {
        tipeAbsen = gcnew String("PULANG");
        m_operationMode = OPR_SAVE_ATTENDANCE_OUT;
    }

    // prepare global absensi table values
    cli::array<String^>^
    fpTableAbsensiValListArray = gcnew array<String^>
    { 
       m_userID,
       m_name,
       m_recordedTime,
       tipeAbsen,
       kodeLokasi,
       device_sn,
       jumlahCoba 
    };

    // prepare current user absensi table
    cli::array<String^>^
    fpTableAbsensiUserValListArray = gcnew array<String^>
    { 
       GetDayName(),
       GetTimeStamp(L"d"),
       GetTimeStamp(L"T"),
       GetTimeStamp(L"T") 
    };


    rc1 = globalAbsenTable->Insert(fpTableAbsensiValListArray);

    if ( currentUserAbsenTable->AlreadyCheckIn()  )
    {
         // Set the key to check
         currentUserAbsenTable->SetKey(gcnew String("m_date"),GetTimeStamp(L"d"));

         cli::array<String^>^
         UpdatefpTableAbsensiUserValListArray = gcnew array<String^>
         { 
            String::Empty, 
            String::Empty,
            String::Empty,
            GetTimeStamp(L"T") 
         };

         rc2 = currentUserAbsenTable->Update(UpdatefpTableAbsensiUserValListArray);
    }
    else
    {
        // this is first absen in this day. insert record to database.
        rc2 = currentUserAbsenTable->Insert(fpTableAbsensiUserValListArray);
    }

    return rc1 && rc2;
}



bool fpUser::Register()
{

   FP_LOGMESSAGE(String::Concat("fpUser::Register(): Registering ",m_name," to database"));

    m_appUser = Environment::UserName;
    m_creationTime = GetTimeStamp(L"F");
    String^ device_sn = fingerprintApp::GetDevice()->SerialNumber;

    // JS: this array is representing the value for each column in a table (fp_template)
    cli::array<String^>^ fpTableTemplateValListArray = gcnew array<String^>
            {
                m_verifyCode,
                m_userID,
                m_creationTime,
                m_appUser,
                m_updateTime,
                m_fingerTemplateArrayString[0],
                m_fingerTemplateArrayString[1],
                m_fingerTemplateArrayString[2],
                m_fingerTemplateArrayString[3],
                m_fingerTemplateArrayString[4],
                m_fingerTemplateArrayString[5],
                m_fingerTemplateArrayString[6],
                m_fingerTemplateArrayString[7],
                m_fingerTemplateArrayString[8],
                m_fingerTemplateArrayString[9],
                device_sn
            };

    // JS: this array is representing the value for each column in a table (fp_karyawan)
    cli::array<String^>^ fpKaryawanValListArray = gcnew array<String^>
            {
                m_userID,
                m_name,
                m_password,
                m_startWorkingHour,
                m_endWorkingHour,
                m_inGreeting,
                m_outGreeting,
                m_creationTime,
                m_updateTime,
                m_appUser,
                m_overtimeMode
               
            };

    fpTableTemplate^ templateTable = gcnew fpTableTemplate(fingerprintApp::GetConnection());
    fpTableKaryawan^ karyawanTable = gcnew fpTableKaryawan(fingerprintApp::GetConnection());

    if ( templateTable->Insert(fpTableTemplateValListArray) && karyawanTable->Insert(fpKaryawanValListArray) )
       return true;
    else
       return false;
}

bool fpUser::Update()
{

   FP_LOGMESSAGE(String::Concat("fpUser::Update(): Updating ",m_name," to database"));

    m_appUser = Environment::UserName;
    m_creationTime = GetTimeStamp(L"F");
    String^ device_sn = fingerprintApp::GetDevice()->SerialNumber;

    // JS: this array is representing the value for each column in a table (fp_template)
    cli::array<String^>^ fpTableTemplateValListArray = gcnew array<String^>
            {
                m_verifyCode,
                String::Empty,
                m_creationTime,
                m_appUser,
                m_updateTime,
                m_fingerTemplateArrayString[0],
                m_fingerTemplateArrayString[1],
                m_fingerTemplateArrayString[2],
                m_fingerTemplateArrayString[3],
                m_fingerTemplateArrayString[4],
                m_fingerTemplateArrayString[5],
                m_fingerTemplateArrayString[6],
                m_fingerTemplateArrayString[7],
                m_fingerTemplateArrayString[8],
                m_fingerTemplateArrayString[9],
                device_sn
            };

    // JS: this array is representing the value for each column in a table (fp_karyawan)
    cli::array<String^>^ fpKaryawanValListArray = gcnew array<String^>
            {
                String::Empty,
                String::Empty,
                m_password,
                m_startWorkingHour,
                m_endWorkingHour,
                m_inGreeting,
                m_outGreeting,
                m_creationTime,
                m_updateTime,
                m_appUser,
                m_overtimeMode
            };

    fpTableTemplate^ templateTable = gcnew fpTableTemplate(fingerprintApp::GetConnection());
    fpTableKaryawan^ karyawanTable = gcnew fpTableKaryawan(fingerprintApp::GetConnection());
   
    templateTable->SetKey(gcnew String("user_id"),m_userID);
    karyawanTable->SetKey(gcnew String("user_id"),m_userID);

    if ( templateTable->Update(fpTableTemplateValListArray) && karyawanTable->Update(fpKaryawanValListArray) )
       return true;
    else
       return false;
}



bool fpUser::CreateAbsenTable()
{
    FP_LOGMESSAGE(String::Concat("fpUser::CreateAbsenTable():Create Absen table for ",m_name," in database"));

    String^ currentUserAbsenTableName = String::Concat(L"fp_absen_" ,m_userID);
    String^ primaryKey = String::Concat(currentUserAbsenTableName,"_pkey");

    String^ sql = String::Empty;
    sql+= "CREATE TABLE attendance.";
    sql+= qtIdent(currentUserAbsenTableName);
    sql+= "\n(\n";
    sql+= "id serial NOT NULL ,\n";
    sql+= "m_day character varying(20),\n";
    sql+= "m_date date,\n";
    sql+= "in_time time without time zone,\n";
    sql+= "out_time time without time zone,\n";
    sql+= "overtime interval,\n";
    sql+= "overtime_int numeric(5,2),\n";
    sql+= "overtime_efektif numeric(5,2),\n";
    sql+= "remark character varying(20),\n";
	sql+= "last_operator text,\n";
	sql+= "last_modified timestamp without time zone DEFAULT now(),\n";
    sql+= "CONSTRAINT ";
    sql+= qtIdent(primaryKey);
    sql+= " PRIMARY KEY (id)";
    sql+= "\n)\n";
    sql+= "WITHOUT OIDS;\n";
    sql+= "ALTER TABLE " + qtIdent(currentUserAbsenTableName) + " OWNER TO postgres;\n";
    sql+= "COMMENT ON TABLE " + qtIdent(currentUserAbsenTableName) + " IS 'absen table for "+ m_name + "'\n";

    fingerprintApp::GetConnection()->Close();

    if ( fingerprintApp::GetConnection()->ExecuteSQL(sql) )
       return true;
    else
       return false;
}