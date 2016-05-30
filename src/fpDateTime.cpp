/******************************************************************************
* filename : fpDateTime.cpp
* author   : Jefri Sibarani
* created  : November 17 2006
* summary  : Time checker class
*
******************************************************************************/

#include "StdAfx.h"
#include "utils.h"
#include "fpDateTime.h"

using namespace System::Globalization;

fpDateTime::fpDateTime(void)
{
   m_dateTime = System::DateTime::Now;
   m_firstTimeRun = m_dateTime;
   systemTimeClean = true;
}


fpDateTime::fpDateTime( System::DateTime dt )
{
   m_dateTime = dt;
   m_firstTimeRun = System::DateTime::Now;
   systemTimeClean = true;
}

fpDateTime::fpDateTime( System::String^ dtInBase64)
{
   m_dateTime = System::DateTime::Now;
   m_firstTimeRun = System::DateTime::Now;
   FromBinary(dtInBase64);
   systemTimeClean = true;
}

fpDateTime::fpDateTime( System::Int64 dtInInt64)
{
   m_firstTimeRun = System::DateTime::Now;
   m_dateTime = DateTime::FromBinary(dtInInt64);
   systemTimeClean = true;
}

void fpDateTime::FromDateTime(System::DateTime dt)
{
   m_dateTime = dt;
}

void fpDateTime::FromBinary(System::String^ dtInBase64)
{
   System::String^ timeFromBase64 = ConvertFromBase64String(dtInBase64);
   if (timeFromBase64 != String::Empty )
   {
      Int64 time_in_long_FromBase64 = Convert::ToInt64(timeFromBase64);
      m_dateTime = DateTime::FromBinary(time_in_long_FromBase64);
   }
}

void fpDateTime::FromBinary(System::Int64 dtInInt64)
{
   m_dateTime = DateTime::FromBinary(dtInInt64);
}


fpDateTime^ fpDateTime::Now()
{
   m_dateTime = System::DateTime::Now;
   return this;
}

System::String^ fpDateTime::GetBase64()
{
   
   Int64 dt_in_long = m_dateTime.ToBinary();
   System::String^ time = dt_in_long.ToString();
   System::String^ timeB64 = ConvertToBase64String(time);

   return timeB64;
}


Int64 fpDateTime::GetBinary()
{
   return m_dateTime.ToBinary();
}
   
System::String^ fpDateTime::GetTimeStamp(String^ format)
{
    String^ date_time;
    date_time = m_dateTime.ToString( format, DateTimeFormatInfo::InvariantInfo );
    return date_time;
}


bool fpDateTime::IsTimeChanged()
{
   if ( m_firstTimeRun > DateTime::Now )
   {
      systemTimeClean = false;
      return true; // we are in the future
   }
   else if ( m_dateTime > DateTime::Now )
   {
      systemTimeClean = false;
      return true; // we are in the future
   }
   //else if( m_firstTimeRun < DateTime::Now )
   return false; // present

}