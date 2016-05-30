/******************************************************************************
* filename : appSettings.h
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : applications setting class
*
******************************************************************************/
#pragma once
#include "applog.h"

#include <string>
using namespace System;

enum reservedEnum
{
   ENUM_ONE = 0,
   ENUM_TWO
};


/** appSettings class. 
 * this class holds and manages application settings information
 * the class is a static public member of fingerprintApp class,
 * and do its job as settingsManager.
 */

public ref class appSettings
{
public:
   /** Constructor.*/ 
   appSettings();
   /** Actually initializes members. */
   void Init();

protected:
    //~appSettings(){}

private:
    /// Log File Directory. 
    /// Default to C:\Documents and Settings\$USERNAME\Local Settings\Temp\.
    String^ m_defaultLogDir;           
    /// fingerprint-conf.xml location.
    /// Default to C:\Documents and Settings\$USERNAME\Application Data\absensi\1.0.0.0\fingerprint-conf.xml
    String^ m_defaultSettingsFileDir;  

    String^ m_soundsDir;

    String^ m_name  ;

    static String^ ms_appVersion;
    static String^ ms_appNameShort;
    static String^ ms_appNameLong;
    static String^ ms_appRevision;
    static String^ ms_appBuildTime;
    static String^ ms_appBuild;
 
    /// Connection informations.
    String^ m_userName;
    String^ m_password;
    String^ m_server;
    int     m_port;
    String^ m_database;


   /**
    * logging properties.
    */
    /// Log File Name. default is fingerprint.log
    String^ m_logFile;                 
    /// Complete log file path.
    /// Default to C:\Documents and Settings\$USERNAME\Local Settings\Temp\fingerprint.log
    String^ m_logFileTarget;           
    /// enable/disable log to window.
    bool m_enableLogToDatabase;          
    /// application logging level.
    int m_minLoggingLevel;             

    String^ m_startOfficeHour;
    String^ m_endOfficeHour;
    String^ m_startBreakTimeHour;
    String^ m_endBreakTimeHour;

    bool m_connectDbAtStartUp;
    bool m_disconnectDbAtClose;

    reservedEnum  m_enVerificationMethod;

    /// Form Verify 
    bool m_formVerifyUseSystemPasswordChar;
    String^ m_formVerifyOutGreeting;
    String^ m_formVerifyInGreeting;

    int m_formVerifyMaxTry;

    /// General settings
    /// office code
    String^ m_officeLocation;

    /// user editing
    bool m_enableEditUser;

    String^ m_startOfficeHourSound;
    String^ m_endOfficeHourSound;
    String^ m_startBreakTimeSound;
    String^ m_endBreakTimeSound;
    String^ m_successfullSound;
    String^ m_failedSound;
    String^ m_warningSound;
    String^ m_errorSound;

    // obseleted by fingerprintApp::CheckDateTime()
    String^ m_lastLoggedTime;

	String^ m_smtpServer;
	String^ m_emailFrom;
	String^ m_emailTo;
	String^ m_emailSubject;

public:

   // Getters
	String^ GetSmtpServer()								{ return m_smtpServer; }
	String^ GetEmailFrom()								{ return m_emailFrom; }
	String^ GetEmailTo()								{ return m_emailTo; }
	String^ GetEmailSubject()							{ return m_emailSubject; }

   static String^ GetAppVersion()                       { return ms_appVersion;   } 
   static String^ GetAppShortName()                     { return ms_appNameShort; } 
   static String^ GetApplongName()                      { return ms_appNameLong;  } 
   static String^ GetAppRevision()                      { return ms_appRevision;  } 
   static String^ GetAppBuildTime()                     { return ms_appBuildTime; }
   static String^ GetAppBuildInfo()                     { return ms_appBuild;     } 

   // not used
   String^ GetLastLoggedTime()                          { return m_lastLoggedTime;}

   bool GetEnableEditUser()                             { return m_enableEditUser;}
   int GetFormVerifyMaxTry()                            { return m_formVerifyMaxTry;   }
   bool GetStartDbAtStartup()                           { return m_connectDbAtStartUp; }
   bool GetDisconnectDbAtClose()                        { return m_disconnectDbAtClose; }
 
   System::String^ GetFormVerifyOutGreeting()           { return m_formVerifyOutGreeting;}
   System::String^ GetFormVerifyInGreeting()            { return m_formVerifyInGreeting;}
   System::String^ GetOfficeLocation()                  { return m_officeLocation;}
   bool GetFormVerifyUseSystemPasswordChar ()           { return m_formVerifyUseSystemPasswordChar; }

   System::String^ GetLogFileName()                     { return m_logFile;           }  
   bool GetLogToDatabase()                              { return m_enableLogToDatabase; } 
   System::String^ GetLogFileTarget()                   { return m_logFileTarget;     }   ///< Returns full name of log file target.
   int GetMinLoggingLevel()                             { return m_minLoggingLevel;   }
   loggingLevel GetLoggingLevel();                                              ///< Returns current application logging level.

   System::String^ GetDBUserName()                      { return m_userName;}             ///< Returns current username used to connect to database.
   System::String^ GetPassword()                        { return m_password;}             ///< Returns current password used to connect to database.
   System::String^ GetServer()                          { return m_server;}               ///< Returns current server where the database resides.
   System::String^ GetDatabase()                        { return m_database;}             ///< Returns current database .
   int GetServerPort()                                  { return m_port;}                 ///< Returns current server port.

   reservedEnum GetVerificationMethod()                  { return m_enVerificationMethod; }
   System::String^ GetAppSoundsDir()                     { return m_soundsDir; } 

   // Time Stuff
   System::String^ GetStartOfficeHour()                  { return m_startOfficeHour; }
   System::String^ GetEndOfficeHour()                    { return m_endOfficeHour; }
   System::String^ GetStartBreakTimeHour()               { return m_startBreakTimeHour; }
   System::String^ GetEndBreakTimeHour()                 { return m_endBreakTimeHour; }

   // Sounds stuff
   System::String^ GetStartOfficeHourSound()             { return m_startOfficeHourSound; }
   System::String^ GetEndOfficeHourSound()               { return m_endOfficeHourSound; }
   System::String^ GetStartBreakTimeSound()              { return m_startBreakTimeSound; }
   System::String^ GetEndBreakTimeSound()                { return m_endBreakTimeSound; }
   System::String^ GetFailedSound()                      { return m_failedSound; }
   System::String^ GetSuccessSound()                     { return m_successfullSound; }
   System::String^ GetWarningSound()                     { return m_warningSound; }
   System::String^ GetErrorSound()                       { return m_errorSound; }

   // Setters 
   void SetSmtpServer(String^ val)						 { m_smtpServer = val; }
   void SetEmailFrom(String^ val)                        { m_emailFrom = val; }
   void SetEmailTo(String^ val)                          { m_emailTo = val; } 
   void SetEmailSubject(String^ val)                     { m_emailSubject = val; }

   void SetLastLoggedTime(String^ timeVal)               { m_lastLoggedTime = timeVal; }
   void SetStartDbAtStartup(bool value)                  { m_connectDbAtStartUp = value ; }
   void SetDisconnectDbAtClose(bool value)               { m_disconnectDbAtClose = value ; }
   void SetFormVerifyOutGreeting(String^ value)          { m_formVerifyOutGreeting    = value; }
   void SetFormVerifyInGreeting(String^ value)           { m_formVerifyInGreeting    = value; }
   void SetOfficeLocation(String^ value)                 { m_officeLocation = value;}
   void SetFormVerifyUseSystemPasswordChar (bool value)  { m_formVerifyUseSystemPasswordChar = value; }
   void SetLogToDatabase(bool value )                    { m_enableLogToDatabase = value; } 
   void SetLogFileTarget(String ^value)                  { m_logFileTarget     = value; }
   void SetMinLoggingLevel(int value)                    { m_minLoggingLevel   = value; }
   void SetLoggingLevel(int value)                       { m_minLoggingLevel   = value; }

   void SetUserName(String^ name)                        { m_userName = name;  }
   void SetPassword(String^ passwd)                      { m_password = passwd;}
   void SetServer(String^ server)                        { m_server = server;  }
   void SetDatabase(String^ db)                          { m_database = db;    }
   void SetServerPort(int port)                          { m_port = port;      }
   // Time Stuff
   void SetStartOfficeHour(String^ _time )               { m_startOfficeHour = _time; }
   void SetEndOfficeHour(String^ _time )                 { m_endOfficeHour = _time; }
   void SetStartBreakTimeHour(String^ _time )            { m_startBreakTimeHour = _time; }
   void SetEndBreakTimeHour(String^ _time )              { m_endBreakTimeHour = _time; }
   // sound stuff
   void SetStartOfficeHourSound(String^ snd )            { m_startOfficeHourSound = snd; }
   void SetEndOfficeHourSound(String^ snd )              { m_endOfficeHourSound = snd; }
   void SetStartBreakTimeSound(String^ snd )             { m_startBreakTimeSound = snd; }
   void SetEndBreakTimeSound(String^ snd )               { m_endBreakTimeSound = snd; }
   void SetFailedSound(String^ snd )                     { m_failedSound = snd; }
   void SetSuccessSound(String^ snd )                    { m_successfullSound = snd; }
   void SetWarningSound(String^ snd )                    { m_warningSound = snd; }
   void SetErrorSound(String^ snd )                      { m_errorSound = snd; }


   // Save Settings to xml file
   void SaveFile();
   void SaveToXml(const char* pFilename);
   // Load settings from xml files
   bool LoadFromXml(const char* pFilename);

   void PrintAllSettings();

private:

   /// Convert loggingLevel to string.    
   string*       ReservedEnumToString(reservedEnum method);
   reservedEnum  StringToReservedEnum(string& method);

   /// Convert loggingLevel to string.    
   string*       LogLevelToString(loggingLevel level);
   /// Convert string to loggingLevel.
   loggingLevel  StringToLogLevel(string& logLevel);

};