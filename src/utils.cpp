/******************************************************************************
* filename : utils.cpp
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : Contains various utility
*
******************************************************************************/
#include "stdafx.h"
#include "fingerprint.h"
#include "utils.h"
#include "fpDateTime.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Text;
using namespace System::Collections;
using namespace System::Data;

using namespace System::Globalization;
using namespace System::Net;
using namespace System::Net::Mail;
using namespace System::Net::Mime;

using namespace FingerPrint;;

static bool myMailSent = false;

System::String^ ConvertToBase64String(String^ value)
{
   System::Text::ASCIIEncoding^ ascii = gcnew System::Text::ASCIIEncoding;

   array<Byte>^ encodedBytes = ascii->GetBytes( value );

   String^ str = Convert::ToBase64String(encodedBytes);
   return str;

}

System::String^ ConvertFromBase64String(String^ value)
{
   
   array<Byte>^ decodedBytes;
   try
   {
      decodedBytes= Convert::FromBase64String(value);
   }
   catch ( ArgumentNullException^ ) 
   {
      return String::Empty;
   }
   catch ( FormatException^ ) 
   {
      return String::Empty;
   }

   System::Text::ASCIIEncoding^ ascii = gcnew System::Text::ASCIIEncoding;

   String^ decodedString = ascii->GetString( decodedBytes );
   
   return decodedString;
}


System::Void ControlSetFocus( System::Windows::Forms::Control^ control )
{
    // Set focus to the control, if it can receive focus.
    if ( control->CanFocus )
    {
        control->Focus();
    }
}
System::Void FileWrite(String^ fileToWrite, String^ textToWrite)
{
    // Create the file if not exist, then append the text
    if (  !File::Exists( fileToWrite ) )
    {
        // Create a file to write to.
        StreamWriter^ sw = File::CreateText( fileToWrite );
        try
        {
            sw->WriteLine("--------------------------------------------------------------------------------");
        }
        finally
        {
            if ( sw )
                delete (IDisposable^)sw;
        }
    }
    // If the file exist,  append text to the file
    StreamWriter^ sw = File::AppendText( fileToWrite );
    try
    {
        sw->WriteLine( textToWrite );
    }
    finally
    {
        if ( sw )
            delete (IDisposable^)sw;
    }
}
string ToBasicString(String^ str)
{
    // Pin memory so GC can't move it while native function is called
    pin_ptr<const wchar_t> wch = PtrToStringChars(str);

    // Conversion to char* :
    // Can just convert wchar_t* to char* using one of the
    // conversion functions such as:
    // WideCharToMultiByte()
    // wcstombs_s()
    // ... etc
    size_t convertedChars = 0;
    size_t  sizeInBytes = ((str->Length + 1) * 2);
    errno_t err = 0;
    char    *ch = (char *)malloc(sizeInBytes);

    err = wcstombs_s(&convertedChars,
                     ch, sizeInBytes,
                     wch, sizeInBytes);
    if (err != 0)
    {
        //printf_s("wcstombs_s  failed!\n");
        return "test";
    }
    else
    {
        string result ( ch );
        return result;
    }
}
String^ ByteArrayToHexString(array<unsigned char>^ byteArray)
{
    String^ result;// = gcnew String();

    for ( int i = 0; i < byteArray->Length; i++ )
    {
        result += byteArray[i].ToString("X2");
    }
    return result;
}
array<unsigned char>^ HexStringToByteArray(String^ hexString)
{
    array<Byte>^ byteArray;
    int length = hexString->Length/2 ;
    byteArray = gcnew array<Byte>(length);

    int i = 0;
    for (int j=0; j < hexString->Length; j+=2 )
    {

        byteArray[i]= Convert::ToByte( hexString->Substring(j,2),16);
        i++;
    }
    return byteArray;
}
String^ GetTimeStamp(String^ format)
{
    DateTime dt = DateTime::Now;
    String^ date_time;
    date_time = dt.ToString( format, DateTimeFormatInfo::InvariantInfo );
    return date_time;
}

int TimeToNumber(String^ time_to_convert)
{
   String^ rippedTime = time_to_convert->Remove(2,1);// remove   : , result is 1235;
   int returnedTime = int::Parse(rippedTime);   
   return returnedTime;
}

int GetTimeInNumber()
{
   String ^currentShortTime = GetTimeStamp(L"t"); // produces eg : 12:35
   int returned = TimeToNumber(currentShortTime);
   if ( returned > 0 )
      return returned;
   else
      return 0;
}


String^ GetDayName()
{
   String ^current = GetTimeStamp(L"D"); // produces eg : Thursday, August 17, 2000
   String ^result = String::Empty;

   int strLength = current->Length;
   
   int i;
   for( i=0;i<strLength;i++)
   {
	   if( ! current[i].Equals(',') )
		  result += current[i];
	   else
		  break; 		
   }
   return result;
}
static bool IsNumber(String^ value)
{
    int last = value->Length - 1;
    if ( Char::IsNumber(value, 0) && Char::IsNumber(value, last) )
        return true;
    else
        return false;
}



static bool needsQuoting(String^ value)
{
    // Replace Double Quotes
    if (value->Replace("\"", "\"\"")->Length > 0)
        return true;

    // Is it a number?
    if (  IsNumber(value) )
        return true;
    else
    {
        int pos = 0;
        while (pos < value->Length)
        {
            Char c = value[pos];
            if (!((pos > 0) && (c >= '0' && c <= '9')) &&
                    !(c >= 'a' && c  <= 'z') &&
                    !(c == '_'))
            {
                return true;
            }
            pos++;
        }
    }
    return false;
}
String^ qtIdent( String^ value)
{
    if (value->Length == 0)
        return value;

    String^ result = value;

    if ( needsQuoting(result) )
        return String::Concat("\"",result,"\"");
    else
        return result;
}



bool StrToBool(String^ value)
{
    if ( value->StartsWith("t") )
    {
        return true;
    }
    else if (value->StartsWith("T") )
    {
        return true;
    }
    else if (value->StartsWith("1"))
    {
        return true;
    }
    else if (value->StartsWith("Y"))
    {
        return true;
    }
    else if (value->StartsWith("y"))
    {
        return true;
    }
    else if (value == "on")
        return true;

    return false;
}

bool StringToBool(String^ value)
{
   bool result;
   string tmp;
   
   tmp = ToBasicString(value);
   
   result = StdStringToBool(tmp);
   return result;

}

bool StdStringToBool(string& value)
{
    string val;
    val = value;
           
    if ( value == "TRUE" )
        return true;
    else if ( value == "true" )
        return true;
    else if ( value == "True" )
        return true;
    else if ( value == "Yes" )
        return true;
    else if ( value == "y" )
        return true;
    else if ( value == "On" )
        return true;
    else if ( value == "on" )
        return true;
    else if ( value == "1" )
        return true;
    else if ( value == "on" )
        return true;
    
    return false;
}

String^ boolToString(bool value)
{
   String^ result;

   result = gcnew String ( BoolToStdString(value).c_str() );
   return result;

}
string BoolToStdString(bool value)
{
   string result;
   result = "FALSE";

   if ( value )
   {
      result = "TRUE";
      return result;
   }
   else
      return result;
}

String^ JQuote(String^ value)
{
    String^ str;
    Boolean booleanVal;
    str="NULL";
   
    if ( value == nullptr )
       return str;

    if ( value->Equals(String::Empty) )
        str="NULL";
    else if ( Boolean::TryParse( value,  booleanVal ) )
        str = value;
    else if (value == "\\'\\'")
        str = qtString("''");
    else if (value == "''")
        str = "''";
    else
        str=qtString(value);

    return str;// + wxT("::") + qtIdent(typeNspName) + wxT(".") + qtIdent(typeName);
}
String^ qtString(String^ value)
{
    String^ result = value;

    result->Replace( "\\" ,   "\\\\");
    result->Replace( "'" ,    "''");
    result += "'" ;

    return String::Concat("'",result);
}


bool IsEmptyString(System::String^ val)
{
    if ( val->Equals(gcnew String("")) )
      return true;
    else
       return false;
}

String^ GiveMeReadableEncodedDateTime(String^ encoded_dt)
{

      String^ binTime = encoded_dt;
      fpDateTime^ converter = gcnew fpDateTime(binTime);
      String^ out = converter->GetTimeStamp(L"F");
      return out;
}
String^ GiveMeDecodedDateTime(String^ src_dt)
{
/*
      String^ srcTime = src_dt;
      
      String^ day;
      String^ month;
      int date;
      int year;
      int hour;
      int minute;
      int second;
      int milisecond;

      //Thursday, August 17, 2000 16:32:32
      int strLength = srcTime->Length;
      int i;
      for( i=0;i<strLength;i++)
      {
	      if( ! srcTime[i].Equals(',') )
		      day += current[i];
	      else
		      break; 		
      }
      
      fpDateTime^ converter = gcnew fpDateTime(
*/
   return String::Empty;
}


static void SendCompletedCallback(Object ^sender, AsyncCompletedEventArgs^ e)
{
    // Get the unique identifier for this asynchronous operation.
     String^ token = (String^) e->UserState;
   
    if (e->Cancelled)
    {
		FP_LOGMESSAGE( token + "  Send canceled.");
    }
    if (e->Error != nullptr)
    {
		FP_LOGMESSAGE("[ " + token + "  " + e->Error->ToString()+ " ]");
    } else
    {
        FP_LOGMESSAGE("SQL Message sent.");
    }
    myMailSent = true;
}
bool SendSqlEmail(/*String^ from,String^ to,String^ subject,*/String^ body)
{
	FP_LOGMESSAGE("Send email started...",LOG_DEBUG);

    // Command line argument must the the SMTP host.
    SmtpClient ^client = gcnew SmtpClient(SETTINGS_MANAGER().GetSmtpServer());
    
	// Specify the e-mail sender.
    // Create a mailing address that includes a UTF8 character
    // in the display name.
    MailAddress ^from = gcnew MailAddress(SETTINGS_MANAGER().GetEmailFrom(),SETTINGS_MANAGER().GetEmailSubject());
    
	// Set destinations for the e-mail message.
    MailAddress ^to = gcnew MailAddress(SETTINGS_MANAGER().GetEmailTo());
    
	// Specify the message content.
    MailMessage ^message = gcnew MailMessage(from, to);
    message->Body = body;
	message->Subject = SETTINGS_MANAGER().GetEmailSubject();
        
    client->SendCompleted += gcnew SendCompletedEventHandler(SendCompletedCallback);
    String^ userState = "test message1";
    client->SendAsync(message, userState);
	delete client;

    FP_LOGMESSAGE("Send email finished...");
	return true;

}