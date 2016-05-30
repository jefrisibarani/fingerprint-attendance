/******************************************************************************
* filename : fingerprint.h
* author   : Jefri Sibarani
* created  : March 20 2007
* summary  : Contains sound player
*
******************************************************************************/

#pragma once
namespace FingerPrint
{
   void PlayTheSound(System::String^ filetoplay);   
   void PlayFailedSound();
   void PlaySuccesSound();
}