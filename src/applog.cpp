/******************************************************************************
* filename : applog.cpp
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : Contains application logging class definition
*
******************************************************************************/

#include "stdafx.h"
#include "fingerprint.h" 
#include "utils.h"
#include "applog.h"
using namespace FingerPrint;

appLog::appLog(void)
{
    InitializeMembers();
}

System::Void appLog::InitializeMembers()
{

    this->logFile = fingerprintApp::settingsManager.GetLogFileTarget();
    minLogLevel = fingerprintApp::settingsManager.GetLoggingLevel();
    logToWindow = fingerprintApp::settingsManager.GetLogToDatabase();
    logToDatabase = fingerprintApp::settingsManager.GetLogToDatabase();

}
System::Void appLog::SetLogFile(String ^file)
{
    this->logFile = file;
}
System::Void appLog::SetLogLevel(int level)
{
    switch (level)
    {
        case LOG_DEBUG:
        minLogLevel = LOG_DEBUG;
        break;
        case LOG_INFO:
        minLogLevel = LOG_INFO;
        break;
        case LOG_SQL:
        minLogLevel = LOG_SQL;
        break;
        case LOG_WARNING:
        minLogLevel = LOG_WARNING;
        break;
        case LOG_ERROR:
        minLogLevel = LOG_ERROR;
        break;
    }
}
System::Void appLog::SetLogLevel(loggingLevel level)
{
    minLogLevel = level;
}

System::Void appLog::Log(String ^message)
{

    Log(message,LOG_INFO);
}
System::Void appLog::Log(String ^message, int level)
{
    String^ msg;
    String^ currentDateTime = GetTimeStamp(L"s");

    switch (level)
    {
        case LOG_DEBUG:
        if (minLogLevel >= LOG_DEBUG)
        {
            msg = currentDateTime + " DEBUG  : " + message;
            DoLog(msg);
        }
        break;
        case LOG_INFO:
        if (minLogLevel >= LOG_INFO)
        {
            msg = currentDateTime + " INFO   : " + message;
            DoLog(msg);
        }
        break;
        case LOG_SQL:
        if (minLogLevel >= LOG_SQL)
        {
            msg = currentDateTime + " SQL    : " + message;
            DoLog(msg);
        }
        break;
        case LOG_WARNING:
        if (minLogLevel >= LOG_WARNING)
        {
            msg = currentDateTime + " WARNING: " + message;
            DoLog(msg);
        }
        break;
        case LOG_ERROR:
        {

            msg = currentDateTime + " ERROR  : " + message;
            MessageBox::Show( message,
                              "An error occurred ",
                              MessageBoxButtons::OK,
                              MessageBoxIcon::Error );

            DoLog(msg);
        }
        break;
    }
}
System::Void appLog::DoLog(String ^message)
{
    FileWrite(this->logFile , message);
}

System::Void appLog::StartLogToWindow(TextBox ^logwin)
{
    logWindow = logwin;
    logToWindow = true;
}

System::Void appLog::StopLogToWindow()
{
    logWindow = nullptr;
    logToWindow = false;
}

System::Void appLog::WriteToDatabase(String^ msg,String^ type)
{
   if (logToDatabase && fingerprintApp::IsConnected )
    {
       String^ message = msg;
       String^ sql;
       String^ username = fingerprintApp::GetCurrentOperator()->GetName();
       String^ log_type = type;
       String^ log_date = GetTimeStamp(L"d");
       String^ log_day  = GetDayName();
       String^ log_time = GetTimeStamp(L"t");
       sql = String::Concat("INSERT INTO fp_logger (log_date,log_day,log_time,user_name,log_type,log_message) VALUES (",
                             qtString(log_date), " , ",
                             qtString(log_day) , " , ",
                             qtString(log_time), " , ",
                             qtString(username), " , ",
                             qtString(log_type), " , ",
                             "'",message,"' )");

       if ( fingerprintApp::fpConn->ExecuteInsert(sql) )
          return;
       else
          return;
    }
}

System::Void appLog::WriteToWindow(String^ msg)
{
    if (logToWindow )
    {
        if (!logWindow)
            return;
        else
            logWindow->AppendText("Device error message :   AlreadyCreated" + "\n");
    }
    else
        return;
}
