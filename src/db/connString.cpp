/******************************************************************************
* filename : connString.cpp
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : connection string class definition
******************************************************************************/

#include "stdafx.h"
#include "fingerprint.h"
#include "db/connString.h"

using namespace FingerPrint;

connString::connString()
{
    fingerprintApp::logManager.Log( "Creating connString object");
	 m_saveConnString = false;
    m_port = 5432;
    m_sslmode = 2;
}

connString::~connString()
{
    SaveConnString();

    m_connstr = ("");
    m_username = ("");
    m_password = ("");
    m_host = ("");
    m_dbname = ("");
    m_port = 5432;
    m_sslmode = 0;

    fingerprintApp::logManager.Log( "Destroying connString object", LOG_DEBUG);
}
void connString::SaveConnString()
{
    fingerprintApp::logManager.Log( "Saving connString properties", LOG_DEBUG);
}