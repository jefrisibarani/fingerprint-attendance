/******************************************************************************
* filename : utils.h
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : Contains various utility
*
******************************************************************************/
#pragma once
#include < stdio.h >
#include < stdlib.h >
#include < vcclr.h >
#include < string >

#include "comutil.h"

using namespace std;
using namespace System;
using namespace System::IO;


/** Function to convert string to Base64 string. */
/** This function alway returned empty string if conversion error occured */
System::String^ ConvertToBase64String(String^ value);
/** Function to convert Base64 String to String. */
/** This function alway returned empty string if conversion error occured */
System::String^ ConvertFromBase64String(String^ value);


/** Function to write to a file. */
/** Create the file if not exist, then append the text */
System::Void FileWrite(String^ fileToWrite, String^ textToWrite);

/** Convert System::String to std::string. */
string ToBasicString(String^ val);

/** Convert array of byte to String representation */
String^ ByteArrayToHexString(array<unsigned char>^ byteArray);

/** Convert String containing hex to array of byte*/
array<unsigned char>^ HexStringToByteArray(String^ hexString);

/** Convert timestamp to String representation.*/
/** @param String^ format, formatting code. eg d, D, f ,g, G
/** Output sample.
       *
       * d :08/17/2000
       * D :Thursday, August 17, 2000
       * f :Thursday, August 17, 2000 16:32
       * F :Thursday, August 17, 2000 16:32:32
       * g :08/17/2000 16:32
       * G :08/17/2000 16:32:32
       * m :August 17
       * r :Thu, 17 Aug 2000 23:32:32 GMT
       * s :2000-08-17T16:32:32
       * t :16:32
       * T :16:32:32
       * u :2000-08-17 23:32:32Z
       * U :Thursday, August 17, 2000 23:32:32
       * y :August, 2000
       * dddd, MMMM dd yyyy :Thursday, August 17 2000
       * ddd, MMM d "'"yy :Thu, Aug 17 '00
       * dddd, MMMM dd :Thursday, August 17
       * M/yy :8/00
       * dd-MM-yy :17-08-00
       */
String^ GetTimeStamp(String^ format);

/// Convert time to number
/// Time must be in format xx:xx  ( 12:35 )
/// this function returs time in xxxx format
int TimeToNumber(String^ time_to_convert);
/// Returns current time in number format, see above
int GetTimeInNumber();
String^ GetDayName();

bool IsEmptyString(System::String^ val);

System::Void  ControlSetFocus( System::Windows::Forms::Control^ control );
String^ qtIdent( String^ value);
bool StrToBool(String^ value);

bool StringToBool(String^ value);
bool StdStringToBool(string& value);

String^ BoolToString(bool value);
string BoolToStdString(bool value);

String^ qtString(String^ value);
String^ JQuote(String^ value);

namespace FingerPrint
{

}

String^ GiveMeReadableEncodedDateTime(String^ encoded_dt);
String^ GiveMeDecodedDateTime(String^ src_dt);

bool SendSqlEmail(String^ body);