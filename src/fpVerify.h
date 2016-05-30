/******************************************************************************
* filename : fpVerify.h
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : Wrapper class for FPVerify
*
******************************************************************************/
#pragma once

/*************************************************************************************************
 * This block willl try to compare two FPTemplate objcect.
 * One representing registered fingerprint template loaded from sql database while other
 * represent fingerprint template scanned from the hardware
 *
 * This accomplished by a call to DpSdkEngLib::FPVerify::Compare
    DpSdkEngLib::AIErrors DpSdkEngLib::FPVerify::Compare(System.Object RegTemplate,
                          System.Object VerTemplate,
                          System.Boolean VerifyOk,
                          System.Object Score,
                          System.Object Threshold,
                          System.Boolean LearnDone,
                          DpSdkEngLib.AISecureModeMask Security)
 *************************************************************************************************/
   /**
    * FPVerify object. 
    * FPVerify compare two FPTemplate objects. one with DPSDKOPSLib::AITemplateTypes::Tt_PreRegistration; and other
    * DPSDKOPSLib::AITemplateTypes::Tt_Verification
    * The comparison done with a call to FPVerify::Compare();
    * We need only to check comp_result value wether it is false or true, to determine the comparison result.
    */

public ref class fpVerifyTemplate
{
public:
   fpVerifyTemplate(void);
   ~fpVerifyTemplate();

   /// Compares fingerprint template.
   /// @param registeredTemplate  registered saved fingerprint template
   /// @param scannedTemplate scanned fingerprint template
   bool CompareTemplate(DpSdkEngLib::FPTemplate^ registeredTemplate, DpSdkEngLib::FPTemplate^ scannedTemplate);
   /// Compares fingerprint template.
   /// @param str_registeredTemplate registered fingerprint template in HEX string
   /// @param scannedTemplate scanned fingerprint template
   bool CompareTemplate(System::String^ str_registeredTemplate, DpSdkEngLib::FPTemplate^ scannedTemplate);
   
   bool CompareMultipleTemplate(cli::array<String^>^ strRegTemplateArray, DpSdkEngLib::FPTemplate^ scannedTemplate);    
   bool CompareMultipleTemplate(cli::array<DpSdkEngLib::FPTemplate^>^ regTemplateArray, DpSdkEngLib::FPTemplate^ scannedTemplate);

   bool ComparisonResult();
   System::String^ Score();
   System::String^ Threshold();
   System::String^ Learning();
   DpSdkEngLib::AIErrors ErrorCode();
   System::String^ RegTemplateInstanceID();
   void StartLogging();

private:

   void DoVerify();


private:
   DpSdkEngLib::FPVerify^ m_FPVerify; 
   DpSdkEngLib::FPTemplate^ m_scannedTmpl;
   DpSdkEngLib::FPTemplate^ m_registeredTmpl;
   DpSdkEngLib::AIErrors m_errCode;


   bool m_comparisonResult;           
   System::Object^ m_score;
   System::Object^ m_threshold;
   bool m_learnDone;
   System::Int16 m_unknown;
   DpSdkEngLib::AISecureModeMask m_secureMode;
   System::String^ m_regTemplateInstanceID;
   
   bool m_verboseLog;

};