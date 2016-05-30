/******************************************************************************
* filename : fpVerify.cpp
* author   : Jefri Sibarani
* created  : November 17 2006
* summary  : fingerprint template verify and compare class
*
******************************************************************************/


#include "stdafx.h"
#include "fingerprint.h"
#include "fpVerify.h"
#include "fpUtils.h"

using namespace FingerPrint;


fpVerifyTemplate::fpVerifyTemplate()
{
   m_FPVerify = gcnew DpSdkEngLib::FPVerify();
   m_scannedTmpl = gcnew DpSdkEngLib::FPTemplate();
   m_registeredTmpl = gcnew DpSdkEngLib::FPTemplate();
   m_errCode = DpSdkEngLib::AIErrors::Er_OK;


   m_comparisonResult = false;
   m_score = gcnew System::Object();
   m_threshold = gcnew System::Object();
   m_learnDone = false;
   m_unknown = 0;
   m_secureMode = DpSdkEngLib::AISecureModeMask::Sm_None;

   m_verboseLog = false;

}

fpVerifyTemplate::~fpVerifyTemplate()
{

}
bool fpVerifyTemplate::CompareTemplate(DpSdkEngLib::FPTemplate^ registeredTemplate, DpSdkEngLib::FPTemplate^ scannedTemplate)
{
   m_registeredTmpl = registeredTemplate;
   m_scannedTmpl = scannedTemplate;
   DoVerify();
   return m_comparisonResult;
}
bool fpVerifyTemplate::CompareTemplate(System::String^ str_registeredTemplate, DpSdkEngLib::FPTemplate^ scannedTemplate)
{
   DpSdkEngLib::FPTemplate^ tmpRegisteredTmpl = gcnew DpSdkEngLib::FPTemplate();

   cli::array<Byte>^ byteArray;
   int length = str_registeredTemplate->Length/2 ;
   byteArray = gcnew cli::array<System::Byte>(length);

   int i = 0;
   for (int j=0; j < str_registeredTemplate->Length; j+=2 )
   {
      byteArray[i]= System::Convert::ToByte( str_registeredTemplate->Substring(j,2),16);
      i++;
   }

   // upload template data to registeredTemplate
   m_errCode = tmpRegisteredTmpl->Import( byteArray );
   
   if (AIErrorsToString(m_errCode) != "OK"  )
   {
       String^ err = String::Concat("Error occured when trying to load fingerprint template \n",
                                    "The error was : ", AIErrorsToString(m_errCode) );
       FP_LOGMESSAGE(err,LOG_WARNING);
   }

   m_registeredTmpl = tmpRegisteredTmpl;
   m_scannedTmpl = scannedTemplate;
   DoVerify();
   return m_comparisonResult;
}
bool fpVerifyTemplate::CompareMultipleTemplate(cli::array<String^>^ strRegTemplateArray, DpSdkEngLib::FPTemplate^ scannedTemplate)
{
  
   int templateCount;
   int i;

   templateCount = strRegTemplateArray->Length;

   for ( i=0; i < templateCount ; i++ )
   {
      
      FP_LOGMESSAGE(strRegTemplateArray[i],LOG_DEBUG);
      if ( CompareTemplate(strRegTemplateArray[i],scannedTemplate) )
         return true;
   }
   return false;
}

bool fpVerifyTemplate::CompareMultipleTemplate(cli::array<DpSdkEngLib::FPTemplate^>^ regTemplateArray, DpSdkEngLib::FPTemplate^ scannedTemplate)
{
   
   m_scannedTmpl = scannedTemplate;
   
   int templateCount;
   int i;

   templateCount = regTemplateArray->Length;

   for ( i=0; i < templateCount ; i++ )
   {
      m_registeredTmpl = regTemplateArray[i];

      DoVerify();
      if ( m_comparisonResult )
         return true;
   }
   return false;
}

bool fpVerifyTemplate::ComparisonResult()
{
   return m_comparisonResult;
}
System::String^ fpVerifyTemplate::Score()
{
   return m_score->ToString();
}
System::String^ fpVerifyTemplate::Threshold()
{
   return m_threshold->ToString();
}

System::String^ fpVerifyTemplate::Learning()
{
   return m_learnDone.ToString();
}
DpSdkEngLib::AIErrors fpVerifyTemplate::ErrorCode()
{
   return m_errCode;
}
void fpVerifyTemplate::StartLogging()
{
    m_verboseLog = true;
}
System::String^ fpVerifyTemplate::RegTemplateInstanceID()
{
    return m_regTemplateInstanceID;
}

void fpVerifyTemplate::DoVerify()
{
   m_regTemplateInstanceID = m_registeredTmpl->InstanceID; 
   m_errCode = m_FPVerify->Compare(m_registeredTmpl,
                                 m_scannedTmpl,
                                 m_comparisonResult,
                                 m_score,
                                 m_threshold,
                                 m_learnDone,
                                 m_secureMode);
}