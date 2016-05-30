/*****************************************************************************
* filename : applog.h
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : Contains application logging declaration
*
*****************************************************************************/
#pragma once

using namespace System;
using namespace System::Windows::Forms;

enum loggingLevel
{
    LOG_ERROR = 0,
    LOG_WARNING,
    LOG_SQL,
    LOG_INFO,
    LOG_DEBUG

};

public ref class appLog : public System::Object
{
public:
    appLog(void);

protected:

public :
    System::Void SetLogFile(String ^file);
    System::Void SetLogLevel(int level);
    System::Void SetLogLevel(loggingLevel level);
    System::Void Log(String ^message, int level);
    System::Void Log(String ^message);

    System::Void StartLogToWindow(TextBox ^logwin);
    System::Void StopLogToWindow();
    System::Void WriteToDatabase(String^ msg,String^ type);

private :
    System::Void DoLog(String ^message);
    System::Void WriteToWindow(String^ msg);
    System::Void InitializeMembers();

    static String^ logFile;
    static loggingLevel minLogLevel;

    bool logToDatabase;

    bool logToWindow;
    System::Windows::Forms::TextBox^ logWindow;
};
