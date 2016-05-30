/******************************************************************************
* filename : fpUtils.cpp
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : variuos utilities specific for FingerPrint SDK
*
******************************************************************************/
#include "stdafx.h"
#include "fpUtils.h"
#include "utils.h"

System::String^ AIErrorsToString(DpSdkEngLib::AIErrors errorCode)
{
    switch (errorCode)
    {
        case DpSdkEngLib::AIErrors::Er_AlreadyCreated:
            return gcnew System::String("Already Created");
        break;
        case DpSdkEngLib::AIErrors::Er_BadQuality:
            return gcnew System::String("Bad Quality");
        break;
        case DpSdkEngLib::AIErrors::Er_BadSignature:
            return gcnew System::String("Bad Signature" );
        break;
        case DpSdkEngLib::AIErrors::Er_DevBroken:
            return gcnew System::String("Device Broken" );
        break;
        case DpSdkEngLib::AIErrors::Er_InvalidArg:
            return gcnew System::String("Invalid Argument");
        break;
        case DpSdkEngLib::AIErrors::Er_InvalidId:
            return gcnew System::String("Invalid ID");
        break;
        case DpSdkEngLib::AIErrors::Er_NoDevice:
            return gcnew System::String("No Device");
        break;
        case DpSdkEngLib::AIErrors::Er_NoHost:
            return gcnew System::String("No Host");
        break;
        case DpSdkEngLib::AIErrors::Er_OK:
            return gcnew System::String("OK");
        break;
        case DpSdkEngLib::AIErrors::Er_OperNotRunning:
            return gcnew System::String("Oper Not Running");
        break;
        case DpSdkEngLib::AIErrors::Er_RegFailed:
            return gcnew System::String("Reg Failed");
        break;
        case DpSdkEngLib::AIErrors::Er_System:
            return gcnew System::String("System");
        break;

        default:
            return gcnew System::String("Unknown Error");
        break;
    }
}
//-----------------------------------------------------------------------------//
/// Convert DpSdkEngLib.AISecureModeMask enum to string
System::String^ SecureModeToString( DpSdkEngLib::AISecureModeMask sec)
{
    System::String^ s;

    switch (sec)
    {
        case DpSdkEngLib::AISecureModeMask::Sm_DevEncryption:
        {
            s = L"DevEncryption";
            return s;
        }
        break;
        case DpSdkEngLib::AISecureModeMask::Sm_DevNonce:
        {
            s = L"DevNonce";
            return s;
        }
        break;
        case DpSdkEngLib::AISecureModeMask::Sm_DevSignature:
        {
            s = L"DevSignature";
            return s;
        }
        break;
        case DpSdkEngLib::AISecureModeMask::Sm_FakeFingerDetection:
        {
            s = L"FakeFingerDetection";
            return s;
        }
        break;
        case DpSdkEngLib::AISecureModeMask::Sm_NonceNotVerified:
        {
            s = L"NonceNotVerified";
            return s;
        }
        break;
        case DpSdkEngLib::AISecureModeMask::Sm_None:
        {
            s = L"None";
            return s;
        }
        break;
        case DpSdkEngLib::AISecureModeMask::Sm_SignatureNotVerified:
        {
            s = L"SignatureNotVerified";
            return s;
        }
        break;
        default:
        s = L"None";
        return s;
        break;
    }
}

System::String^ FPTemplateToHexString(DpSdkEngLib::FPTemplate^ tmpl)
{
    DpSdkEngLib::AIErrors errorCode;                  // JS: Error code
    String^ errmsg;                                     // JS: Error message
    String^ templateInString;                           // JS: Template to save
    // array<unsigned char>^ tmpResult;                 // JS: Template buffer
    array<Byte>^tmpResult;
    System::Object ^tmpBuffer;                          // JS: Template buffer with object type

    tmpBuffer = gcnew System::Object();                 // JS: instantiate tmpBuffer
    errorCode = tmpl->Export(tmpBuffer);        // JS: Export scanned fingerprint data to tmpBuffer
    errmsg = AIErrorsToString(errorCode);             // JS: conver error code to string

    //tmpResult = safe_cast<array<unsigned char>^>(tmpBuffer);
    tmpResult = safe_cast<array<Byte>^>(tmpBuffer);     // JS: Convert data in tmpBuffer to tmpResult ( from Object to Array of byte)

    templateInString =  ByteArrayToHexString(tmpResult);
    return templateInString;
}