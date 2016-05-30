/******************************************************************************
* filename : appSettings.cpp
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : applications setting class
*
******************************************************************************/
#include "stdafx.h"
#include "fingerprint.h"
#include "appSettings.h"
#include "utils.h"
#include "tinyxml.h"
#include "fpDateTime.h"

using namespace System::Globalization;
using namespace FingerPrint;

static bool IsNumber(String^ value)
{
    int count = value->Length;
    for ( int i=0; i< count; i++ )
    {
        if ( ! Char::IsNumber(value, i) )
            return false;
    }
    return true;
}
appSettings::appSettings()
{
    Init();
}

void appSettings::Init()
{
    #ifdef GetEnvironmentVariable
    #undef GetEnvironmentVariable
    #endif

    m_enableLogToDatabase       = true;
    
    ms_appVersion               = APP_VERSION;
    ms_appNameShort             = APP_NAME_S;
    ms_appNameLong              = ms_appNameShort + L"-" + ms_appVersion;
    ms_appBuildTime             = __DATE__ + " ," + __TIME__;
    ms_appRevision              = APP_REVISION;
    ms_appBuild                 = "clr: " + __CLR_VER + " , MSVC : " + _MSC_VER + /*" , rev: "+ ms_appRevision +*/ " ,built: " + ms_appBuildTime;

    m_defaultLogDir             = System::Environment::GetEnvironmentVariable( "TEMP" );

    m_defaultSettingsFileDir    = String::Concat(Application::UserAppDataPath, "\\fingerprint-conf.xml");
    m_logFile                   = "\\absensi.log";
    m_soundsDir                 = String::Concat( Application::StartupPath,"\\sounds");

    m_startOfficeHour           = gcnew String("08:00");
    m_endOfficeHour             = gcnew String("17:00");
    m_startBreakTimeHour        = gcnew String("12:00");
    m_endBreakTimeHour          = gcnew String("13:00");

    m_startOfficeHourSound      = String::Concat( Application::StartupPath,"\\sounds\\gong.wav");
    m_endOfficeHourSound        = String::Concat( Application::StartupPath,"\\sounds\\gong.wav");
    m_startBreakTimeSound       = String::Concat( Application::StartupPath,"\\sounds\\gong.wav");
    m_endBreakTimeSound         = String::Concat( Application::StartupPath,"\\sounds\\gong.wav");
    m_successfullSound          = String::Concat( Application::StartupPath,"\\sounds\\success.wav");
    m_failedSound               = String::Concat( Application::StartupPath,"\\sounds\\failed.wav");
    m_warningSound              = String::Concat( Application::StartupPath,"\\sounds\\warning.wav");
    m_errorSound                = String::Concat( Application::StartupPath,"\\sounds\\error.wav");

    m_lastLoggedTime            = fingerprintApp::timeChecker.GetBase64();


    m_formVerifyUseSystemPasswordChar = true;
    m_formVerifyOutGreeting     = L"Selamat Jalan";
    m_formVerifyInGreeting      = L"Selamat Bekerja";
    m_connectDbAtStartUp        = true;
    m_disconnectDbAtClose       = true;
    m_officeLocation            = L"Office";
    m_minLoggingLevel           = LOG_DEBUG;
    m_logFileTarget             = m_defaultLogDir + m_logFile;
    m_userName                  = Environment::UserName;
    m_password                  = "1";
    m_server                    = Environment::MachineName;
    m_port                      = 5432;
    m_database                  = "fp_absensi";
    m_enVerificationMethod      = ENUM_TWO;
    m_formVerifyMaxTry          = 4;
    m_enableEditUser            = true;


	m_smtpServer    = L"127.0.0.1";
	m_emailFrom     = L"admin@example.com"; 
	m_emailTo       = L"admin@example.com"; 
	m_emailSubject  = L"attendance";

    // load settings from file, if any error found, load default values
    string fileName = ToBasicString( m_defaultSettingsFileDir);
    LoadFromXml( fileName.c_str() );

}
loggingLevel appSettings::GetLoggingLevel()
{
    loggingLevel logLevel;
    switch (m_minLoggingLevel)
    {
        case LOG_DEBUG:
        logLevel = LOG_DEBUG;
        break;
        case LOG_INFO:
        logLevel = LOG_INFO;
        break;
        case LOG_SQL:
        logLevel = LOG_SQL;
        break;
        case LOG_WARNING:
        logLevel = LOG_WARNING;
        break;
        case LOG_ERROR:
        logLevel = LOG_ERROR;
        break;
    }
    return logLevel;
}


void appSettings::SaveFile()
{
    string fileName = ToBasicString( m_defaultSettingsFileDir);
    SaveToXml(fileName.c_str() );
}


void appSettings::SaveToXml(const char* pFilename)
{
    TiXmlDocument doc;
    TiXmlComment * comment;
    string s;
    TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );
    doc.LinkEndChild( decl );

    TiXmlElement * root = new TiXmlElement(ToBasicString(ms_appNameShort).c_str());
    doc.LinkEndChild( root );

    comment = new TiXmlComment();
    s = "configurations for " + ToBasicString(ms_appNameLong);
    comment->SetValue(s.c_str());
    root->LinkEndChild( comment );

    // block: version information
    {
        TiXmlElement* appinfo_member;
        TiXmlElement * appinfo = new TiXmlElement( "app_information" );
        root->LinkEndChild( appinfo );

        appinfo_member = new TiXmlElement( "name" );
        appinfo_member->LinkEndChild( new TiXmlText( ToBasicString(ms_appNameShort).c_str() ) );
        appinfo->LinkEndChild( appinfo_member );

        appinfo_member = new TiXmlElement( "version" );
        appinfo_member->LinkEndChild( new TiXmlText( ToBasicString(ms_appVersion).c_str() ) );
        appinfo->LinkEndChild( appinfo_member );

        appinfo_member = new TiXmlElement( "build" );
        appinfo_member->LinkEndChild( new TiXmlText( ToBasicString(ms_appBuild).c_str() ) );
        appinfo->LinkEndChild( appinfo_member );
    }

    // block: connection information
    {
        TiXmlElement * cxn = new TiXmlElement( "connection" );
        root->LinkEndChild( cxn );
        cxn->SetAttribute("user_name", ToBasicString(m_userName).c_str() );

        String^ encodedPasswd = ConvertToBase64String(m_password);
        cxn->SetAttribute("password", ToBasicString(encodedPasswd).c_str() );

        cxn->SetAttribute("server", ToBasicString(m_server).c_str());
        cxn->SetAttribute("port", m_port);
        cxn->SetAttribute("database", ToBasicString(m_database).c_str() );

        TiXmlElement* autoConnect = new TiXmlElement( "connect_at_startup" );
        autoConnect->LinkEndChild( new TiXmlText( BoolToStdString(m_connectDbAtStartUp).c_str() ) );
        cxn->LinkEndChild( autoConnect );
       
        TiXmlElement* autoDisconnect = new TiXmlElement( "disconnect_at_close" );
        autoDisconnect->LinkEndChild( new TiXmlText( BoolToStdString(m_disconnectDbAtClose).c_str() ) );
        cxn->LinkEndChild( autoDisconnect );

    }
    // block: smtp_settings
    {
        TiXmlElement * cxn = new TiXmlElement( "email_settings" );
        root->LinkEndChild( cxn );
        cxn->SetAttribute("smtp_host", ToBasicString(m_smtpServer).c_str() );
        cxn->SetAttribute("email_from", ToBasicString(m_emailFrom).c_str());
        cxn->SetAttribute("email_to", ToBasicString(m_emailTo).c_str());
        cxn->SetAttribute("email_subject", ToBasicString(m_emailSubject).c_str() );
    }
    // block: logging information
    {
        TiXmlElement* log_member;
        TiXmlElement * logging = new TiXmlElement( "logging" );
        root->LinkEndChild( logging );
        //log_member = new TiXmlElement( "log_file" );
        //log_member->LinkEndChild( new TiXmlText( ToBasicString(logFile).c_str() ));
        //logging->LinkEndChild( log_member );
        log_member = new TiXmlElement( "logging_level" );
        log_member->LinkEndChild( new TiXmlText( LogLevelToString( GetLoggingLevel() )->c_str() ));
        logging->LinkEndChild( log_member );

        log_member = new TiXmlElement( "logging_file" );
        log_member->LinkEndChild( new TiXmlText( ToBasicString(m_logFileTarget).c_str() ));
        logging->LinkEndChild( log_member );

        log_member = new TiXmlElement( "to_database" );
        log_member->LinkEndChild( new TiXmlText( BoolToStdString(m_enableLogToDatabase).c_str() ) );
        logging->LinkEndChild( log_member );
    }

    // block: General 
    {
        TiXmlElement* general_member;
        TiXmlElement * general = new TiXmlElement( "general" );

        general_member = new TiXmlElement( "office_location" );

        string tmp;
        tmp = ToBasicString(m_officeLocation);

        general_member->LinkEndChild( new TiXmlText( tmp.c_str() ) );
        general->LinkEndChild( general_member );

       // block: jam pulang/masuk karyawan
        TiXmlElement * start_office_hour = new TiXmlElement( "start_office_hour" );
        std::string startOfficeHourVal = ToBasicString(m_startOfficeHour);
        start_office_hour->LinkEndChild( new TiXmlText(startOfficeHourVal.c_str() )   );
        general->LinkEndChild( start_office_hour );

        TiXmlElement * end_office_hour = new TiXmlElement( "end_office_hour" );
        std::string endOfficeHourVal = ToBasicString(m_endOfficeHour);
        end_office_hour->LinkEndChild( new TiXmlText(endOfficeHourVal.c_str() )   );
        general->LinkEndChild( end_office_hour );

        TiXmlElement * start_break_time = new TiXmlElement( "start_break_time" );
        std::string startBreakTimeVal = ToBasicString(m_startBreakTimeHour);
        start_break_time->LinkEndChild( new TiXmlText(startBreakTimeVal.c_str() )   );
        general->LinkEndChild( start_break_time );

        TiXmlElement * end_break_time = new TiXmlElement( "end_break_time" );
        std::string endBreakTimeVal = ToBasicString(m_endBreakTimeHour);
        end_break_time->LinkEndChild( new TiXmlText(endBreakTimeVal.c_str() )   );
        general->LinkEndChild( end_break_time );

        // user editing
        TiXmlElement* enableEditUser = new TiXmlElement( "privilege_mode" );
        enableEditUser->LinkEndChild( new TiXmlText( BoolToStdString(m_enableEditUser).c_str() ) );
        general->LinkEndChild( enableEditUser );
      
        root->LinkEndChild( general );
    
    }
    // block: form_verify 
    {
        TiXmlElement* form_verify_member;
        TiXmlElement * form_verify = new TiXmlElement( "form_verify" );

        string tmp;
        tmp = BoolToStdString(m_formVerifyUseSystemPasswordChar);
        form_verify_member = new TiXmlElement( "use_system_password_char" );
        form_verify_member->LinkEndChild( new TiXmlText( tmp.c_str() ) );
        form_verify->LinkEndChild( form_verify_member );


        form_verify_member = new TiXmlElement( "in_greeting" );
        form_verify_member->LinkEndChild( new TiXmlText( ToBasicString(m_formVerifyInGreeting).c_str() ) );
        form_verify->LinkEndChild( form_verify_member );

        form_verify_member = new TiXmlElement( "out_greeting" );
        form_verify_member->LinkEndChild( new TiXmlText( ToBasicString(m_formVerifyOutGreeting).c_str() ) );
        form_verify->LinkEndChild( form_verify_member );

        form_verify_member = new TiXmlElement( "maximum_try" );
        string max_try = ToBasicString(Convert::ToString(m_formVerifyMaxTry));
        form_verify_member->LinkEndChild( new TiXmlText( max_try.c_str() ) );
        form_verify->LinkEndChild( form_verify_member );

        root->LinkEndChild( form_verify );
    }
    // block: Last Date  - Save last date time 
    {
        TiXmlElement * last_logged_time = new TiXmlElement( "last_logged_time" );
        root->LinkEndChild( last_logged_time );

        LOG_MANAGER().Log( String::Concat("Last Logged time: ",GiveMeReadableEncodedDateTime(m_lastLoggedTime)), LOG_INFO ) ;

        string lastLoggedTimeVal = ToBasicString(m_lastLoggedTime); 
        last_logged_time->LinkEndChild( new TiXmlText( lastLoggedTimeVal.c_str() ) );
    }

    // block: sounds 
    {
        TiXmlElement* app_sound_member;
        TiXmlElement * app_sound = new TiXmlElement( "sounds" );

        app_sound_member = new TiXmlElement( "start_work_hour" );
        app_sound_member->LinkEndChild( new TiXmlText( ToBasicString(m_startOfficeHourSound).c_str() ) );
        app_sound->LinkEndChild( app_sound_member );

        app_sound_member = new TiXmlElement( "end_work_hour" );
        app_sound_member->LinkEndChild( new TiXmlText( ToBasicString(m_endOfficeHourSound).c_str() ) );
        app_sound->LinkEndChild( app_sound_member );

        app_sound_member = new TiXmlElement( "start_break_time" );
        app_sound_member->LinkEndChild( new TiXmlText( ToBasicString(m_startBreakTimeSound).c_str() ) );
        app_sound->LinkEndChild( app_sound_member );

        app_sound_member = new TiXmlElement( "end_break_time" );
        app_sound_member->LinkEndChild( new TiXmlText( ToBasicString(m_endBreakTimeSound).c_str() ) );
        app_sound->LinkEndChild( app_sound_member );

        app_sound_member = new TiXmlElement( "absen_failed" );
        app_sound_member->LinkEndChild( new TiXmlText( ToBasicString(m_failedSound).c_str() ) );
        app_sound->LinkEndChild( app_sound_member );

        app_sound_member = new TiXmlElement( "absen_okay" );
        app_sound_member->LinkEndChild( new TiXmlText( ToBasicString(m_successfullSound).c_str() ) );
        app_sound->LinkEndChild( app_sound_member );

        app_sound_member = new TiXmlElement( "warning" );
        app_sound_member->LinkEndChild( new TiXmlText( ToBasicString(m_warningSound).c_str() ) );
        app_sound->LinkEndChild( app_sound_member );

        app_sound_member = new TiXmlElement( "error" );
        app_sound_member->LinkEndChild( new TiXmlText( ToBasicString(m_errorSound).c_str() ) );
        app_sound->LinkEndChild( app_sound_member );

        root->LinkEndChild( app_sound );
    }


    doc.SaveFile(pFilename);
}

bool appSettings::LoadFromXml(const char* pFilename)
{
    TiXmlDocument doc(pFilename);
    if (!doc.LoadFile())
        return false;

    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    TiXmlHandle hRoot(0);

    // block: name
    {
        pElem=hDoc.FirstChildElement().Element();
        // should always have a valid root but handle gracefully if it does
        if (!pElem)
            return false;
        //m_appName = new string ( pElem->Value() );

        // save this for later
        hRoot=TiXmlHandle(pElem);
    }

    // block General
    {
        pElem=hRoot.FirstChild("general").FirstChild("office_location").Element();
        if (pElem)
           m_officeLocation = gcnew String( pElem->GetText() );

        pElem=hRoot.FirstChild("general").FirstChild("privilege_mode").Element();
        if (pElem)
           m_enableEditUser = StringToBool(gcnew String(pElem->GetText()) ); 
    }

    // block form Verify
    {
        pElem=hRoot.FirstChild("form_verify").FirstChild("use_system_password_char").Element();
        if (pElem)
        {
           string value;
           value = pElem->GetText();
           m_formVerifyUseSystemPasswordChar = StdStringToBool(value);
        }

        pElem=hRoot.FirstChild("form_verify").FirstChild("in_greeting").Element();
        if (pElem)
           m_formVerifyInGreeting = gcnew String( pElem->GetText() );

        pElem=hRoot.FirstChild("form_verify").FirstChild("out_greeting").Element();
        if (pElem)
           m_formVerifyOutGreeting = gcnew String( pElem->GetText() );

        pElem=hRoot.FirstChild("form_verify").FirstChild("maximum_try").Element();
        if (pElem)
        {
           String^ num = gcnew String(pElem->GetText());
           if ( IsNumber(num) )
               m_formVerifyMaxTry =  Convert::ToInt32(num);
        }
    }
    
    // block logging
    {
        pElem=hRoot.FirstChild("logging").FirstChild("logging_level").Element();
        if (pElem)
            m_minLoggingLevel = StringToLogLevel(string (pElem->GetText() ));

        pElem=hRoot.FirstChild("logging").FirstChild("logging_file").Element();
        if (pElem)
            m_logFileTarget = gcnew String(pElem->GetText() );

        pElem=hRoot.FirstChild("logging").FirstChild("to_database").Element();
        if (pElem)
            m_enableLogToDatabase = StringToBool(gcnew String(pElem->GetText()) ); 
    }

    // block jam pulang /masuk
    {
        pElem=hRoot.FirstChild("general").FirstChild("start_office_hour").Element();
        if (pElem)
           SetStartOfficeHour(  gcnew String(pElem->GetText() )   );
        
        pElem=hRoot.FirstChild("general").FirstChild("end_office_hour").Element();
        if (pElem)
           SetEndOfficeHour( gcnew String(pElem->GetText() )   );

        pElem=hRoot.FirstChild("general").FirstChild("start_break_time").Element();
        if (pElem)
            SetStartBreakTimeHour(  gcnew String(pElem->GetText()) );
        
        pElem=hRoot.FirstChild("general").FirstChild("end_break_time").Element();
        if (pElem)
           SetEndBreakTimeHour( gcnew String(pElem->GetText()) );
    }
    // block email_settings
    {
        pElem=hRoot.FirstChild("email_settings").Element();
        if (pElem)
		{
			m_smtpServer = gcnew String( pElem->Attribute("smtp_host") );
			m_emailFrom = gcnew String( pElem->Attribute("email_from") );
			m_emailTo = gcnew String( pElem->Attribute("email_to") );
			m_emailSubject = gcnew String( pElem->Attribute("email_subject") );
		}
    }

    // block: connection
    {
        pElem=hRoot.FirstChild("connection").Element();
        if (pElem)
        {
            m_userName = gcnew String( pElem->Attribute("user_name") );

            String^ encodedPasswd = gcnew String(pElem->Attribute("password") );
            m_password = ConvertFromBase64String(encodedPasswd);

            m_server = gcnew String(pElem->Attribute("server") );
            String^ rPort = gcnew String(pElem->Attribute("port") );
            m_port = Convert::ToInt32(rPort);
            m_database = gcnew String(pElem->Attribute("database") );
        }
        pElem=hRoot.FirstChild("connection").FirstChild("connect_at_startup").Element();
        if (pElem)
           m_connectDbAtStartUp = StringToBool(gcnew String(pElem->GetText()) ); 
    }

    // block: timeChecker - Load Last saved Date and Time
    {
        pElem=hRoot.FirstChild("last_logged_time").Element();
        if (pElem)
           m_lastLoggedTime = gcnew String(pElem->GetText()) ; 
    }

    // block sound
    {
        pElem=hRoot.FirstChild("sounds").FirstChild("start_work_hour").Element();
        if (pElem)
           m_startOfficeHourSound = gcnew String(pElem->GetText());

        pElem=hRoot.FirstChild("sounds").FirstChild("end_work_hour").Element();
        if (pElem)
           m_endOfficeHourSound = gcnew String(pElem->GetText());

        pElem=hRoot.FirstChild("sounds").FirstChild("start_break_time").Element();
        if (pElem)
           m_startBreakTimeSound = gcnew String(pElem->GetText());

        pElem=hRoot.FirstChild("sounds").FirstChild("end_break_time").Element();
        if (pElem)
           m_endBreakTimeSound = gcnew String(pElem->GetText());

        pElem=hRoot.FirstChild("sounds").FirstChild("absen_failed").Element();
        if (pElem)
           m_failedSound = gcnew String(pElem->GetText());

        pElem=hRoot.FirstChild("sounds").FirstChild("absen_okay").Element();
        if (pElem)
           m_successfullSound = gcnew String(pElem->GetText());

        pElem=hRoot.FirstChild("sounds").FirstChild("warning").Element();
        if (pElem)
           m_warningSound = gcnew String(pElem->GetText());

        pElem=hRoot.FirstChild("sounds").FirstChild("error").Element();
        if (pElem)
           m_errorSound = gcnew String(pElem->GetText());
    }
    return true;
}


string* appSettings::ReservedEnumToString(reservedEnum method)
{
    switch (method)
    {
        case ENUM_ONE:
        return new string("ENUM_ONE");
        break;
        case ENUM_TWO:
        return new string("ENUM_TWO");
        break;
    }
    return new string("ENUM_TWO");

}

reservedEnum  appSettings::StringToReservedEnum(string& logLevel)
{
    reservedEnum method;

    if (logLevel == "ENUM_ONE" )
        method = ENUM_ONE;
    //else
    if (logLevel == "ENUM_TWO" )
        method = ENUM_TWO;
    //else
    return method;

}
string* appSettings::LogLevelToString(loggingLevel level)
{

    //level = GetLoggingLevel();
    switch (level)
    {
        case LOG_DEBUG:
        return new string("LOG_DEBUG");
        break;
        case LOG_INFO:
        return new string("LOG_INFO");
        break;
        case LOG_SQL:
        return new string("LOG_SQL");
        break;
        case LOG_WARNING:
        return new string("LOG_WARNING");
        break;
        case LOG_ERROR:
        return new string("LOG_ERROR");
        break;
    }
    return new string("UNKNOWN_LEVEL");
}

loggingLevel appSettings::StringToLogLevel(string& logLevel)
{
    loggingLevel level;

    if (logLevel == "LOG_DEBUG" )
        level = LOG_DEBUG;
    //else
    if (logLevel == "LOG_INFO" )
        level = LOG_INFO;
    //else
    if (logLevel == "LOG_SQL" )
        level = LOG_SQL;
    //else
    if (logLevel == "LOG_WARNING" )
        level = LOG_WARNING;
    //else
    if (logLevel == "LOG_ERROR" )
        level = LOG_ERROR;

    return level;
}

void appSettings::PrintAllSettings()
{
   
}

