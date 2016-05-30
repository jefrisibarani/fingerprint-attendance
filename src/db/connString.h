/******************************************************************************
* filename : connString.h
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : postgresql Connection string class
*
******************************************************************************/
#pragma once

using namespace System;

public ref class connString : public System::Object
{
public:
    connString(void); 
    ~connString(); 
    
    inline void SetUsername( String^ username)
    {
        m_username = username;
    }
    inline void SetPassword( String^ password)
    {
        m_password = password;
    }
    inline void SetHost( String^ host)
    {
        m_host = host;
    }
    inline void SetDbname( String^ dbname)
    {
        m_dbname = dbname;
    }
    inline void SetHostPort(int port)
    {
        m_port = port;
    }
    
    inline String^ GetConnString()
    {
        return m_connstr;
    }
    inline String^ GetUsername()
    {
        return m_username;
    }
    inline String^ GetPassword()
    {
        return m_password;
    }
    inline String^ GetHost()
    {
        return m_host;
    }
    inline String^ GetDbname()
    {
        return m_dbname;
    }
    inline int GetHostPort()
    {
        return m_port;
    }
    inline int GetSslmode()
    {
        return m_sslmode;
    }

    void SaveConnString();

private:

    String^     m_connstr;
    String^     m_username;
    String^     m_password;
    String^     m_host;
    String^     m_dbname;
    int          m_port;
    int          m_sslmode;
    bool         m_saveConnString;

};

