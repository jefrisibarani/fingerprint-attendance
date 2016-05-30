/******************************************************************************
* filename : fpUser.h
* author   : Jefri Sibarani
* created  : November 17 2006
* summary  : user class
*
******************************************************************************/



#pragma once



namespace FingerPrint {

   enum operationMode
   {
      OPR_SAVE_ATTENDANCE_IN = 0,
      OPR_SAVE_ATTENDANCE_OUT = 1,
      OPR_REGISTER_USER = 2,
      OPR_UNKNOWN = 3
   };

ref class fpUser
{
public:
   
   fpUser(void);

   
   /** Initialize registered user from database.
    * used in verifying user fingerprint template
    * eg. frmVerify
    */
   System::String^ InitFromDB(System::String^ userCode);

   /** Create and Initialize New User.
    * used to create and register new user to database
    * eg. frmRegisterTemplate
    */
   System::Void CreateNew( System::String^ name,
                           System::String^ id,
                           System::String^ code,
                           System::String^ passwd,
                           cli::array<System::String^>^ fingers,
                           System::String^ sw,
                           System::String^ ew,
                           System::String^ inGreet,
                           System::String^ outGreet,
                           System::String^ ot
                         );
   
   
   /** Update stored user properties.
    */
   //bool UpdateProperties();


   /** Save and record user checkin or checkou to database.
    * used in frmVerify
    */
   bool SaveAttendance(int try_count);
   /** Creates and register user to database.
    * used in frmRegisterTemplate
    */
   bool Register();
   
   
   bool Update();

   /** Create user absen table in database.
    * used in frmRegisterTemplate
    @verbatim 
    This method will generate SQL query similar with this query:

      CREATE TABLE "fp_absen_06-001"
      (
      id int8 NOT NULL DEFAULT nextval('"fp_absen_06-001_id_seq"'::regclass),
      m_day varchar(20),
      m_date varchar(20),
      in_time varchar(10),
      out_time varchar(10),
      CONSTRAINT "fp_absen_06-001_pkey" PRIMARY KEY (id)
      ) 
      WITHOUT OIDS;
      ALTER TABLE "fp_absen_06-001" OWNER TO postgres;
      COMMENT ON TABLE "fp_absen_06-001" IS 'absen table for Jefri Sibarani';
   @endverbatim
    */
   bool CreateAbsenTable();


   /** Verify fingerprint template from scanned template with registered template
    * stored at database.
    * used in frmVerify.
    */
   bool VerifyFinger(DpSdkEngLib::FPTemplate^ scannedTemplate);


   // Getters
   System::String^ GetName()        { return m_name; }
   System::String^ GetID()          { return m_userID; }
   System::String^ GetVerifyCode()  { return m_verifyCode;}
   cli::array<System::String^>^ GetFPTemplateArrayString();
   System::String^ GetGreeting();   
   System::String^ GetRecordedTime();
   System::String^ GetPassword()    { return m_password; }
   System::String^ GetStartWorkHour()    { return m_startWorkingHour; }
   System::String^ GetEndWorkHour()    { return m_endWorkingHour; }
   System::String^ GetInGreeting()    { return m_inGreeting; }
   System::String^ GetOutGreeting()    { return m_outGreeting; }
   System::String^ GetOvertimeMode()    { return m_overtimeMode; }

   // Setters
   System::Void SetName(System::String^ name)         { m_name = name;  }
   System::Void SetUserID(System::String^ id)         { m_userID = id;  }
   System::Void SetVerifyCode(System::String^ code)   { m_verifyCode = code; }
   System::Void SetPassword(System::String^ passwd)   { m_password = passwd; }
   System::Void SetFingersTemplate(cli::array<System::String^>^ fingers); 
   System::Void SetStartWorkHour(System::String^ sw)  { m_startWorkingHour = sw; }
   System::Void SetEndWorkHour(System::String ^ ew)   { m_endWorkingHour = ew; }
   System::Void SetInGreeting(System::String^ greet)  { m_inGreeting = greet; }
   System::Void SetOutGreeting(System::String^ greet) { m_outGreeting = greet; }
   System::Void SetOvertimeMode(System::String^ ot)   { m_overtimeMode = ot; }
private:

   /// Left Hand Fingers.
   System::String^         m_left_thumb;
   System::String^         m_left_index;
   System::String^         m_left_middle;
   System::String^         m_left_ring;
   System::String^         m_left_pinkie;
   /// Right Hand Fingers.
   System::String^         m_right_thumb;
   System::String^         m_right_index;
   System::String^         m_right_middle;
   System::String^         m_right_ring;
   System::String^         m_right_pinkie;

   /// Fingerprint template array.
   /// member of this array is left and right fingers
   cli::array<System::String^>^                   m_fingerTemplateArrayString;

   System::String^         m_name;                 ///< User Name.
   System::String^         m_userID;               ///< User ID.
   System::String^         m_verifyCode;           ///< User Verification Code
   System::String^         m_password;             ///< User ID.
   System::String^         m_startWorkingHour;     ///< User start working hour.
   System::String^         m_endWorkingHour;       ///< User end working hour.
   System::String^         m_inGreeting;           ///< User in greeting.
   System::String^         m_outGreeting;          ///< User out greeting.
   System::String^         m_overtimeMode;
   System::String^         m_creationTime;         ///< User creation/registration time.
   System::String^         m_updateTime;           ///< User update time.
   System::String^         m_appUser;              ///< Application's operator.


   System::String^         m_recordedTime;

   cli::array<DpSdkEngLib::FPTemplate^>^  
                           m_FPTemplateArray;

   DpSdkEngLib::FPTemplate^
                           m_scannedFPTemplate;

   operationMode           m_operationMode;

};
}