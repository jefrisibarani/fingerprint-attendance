/******************************************************************************
* filename : fpUtils.h
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : Contains various utility for FingerPrint device SDK
*
******************************************************************************/
#pragma once

/** Convert AIError enumeration value to String representation. 
 * @param : DpSdkEngLib::AIErrors errorCode, error code
 */
System::String^ AIErrorsToString(DpSdkEngLib::AIErrors errorCode);

/** Convert AISecureModeMask enumeration to String value.
 * @param : DpSdkEngLib::AISecureModeMask sec,security mode
 */
System::String^ SecureModeToString( DpSdkEngLib::AISecureModeMask sec);

System::String^ FPTemplateToHexString(DpSdkEngLib::FPTemplate^ tmpl);