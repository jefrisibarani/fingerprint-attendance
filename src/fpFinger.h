/******************************************************************************
* filename : fpFinger.h
* author   : Jefri Sibarani
* created  : November 17 2006
* summary  : enum class for fingers
*
******************************************************************************/


#pragma once

namespace FingerPrint {

enum fpFingerEnum 
{
    FP_LEFT_THUMB   = 0,
    FP_LEFT_INDEX   = 1,
    FP_LEFT_MIDDLE  = 2,
    FP_LEFT_RING    = 3,
    FP_LEFT_PINKIE  = 4,
    FP_RIGHT_THUMB  = 5,
    FP_RIGHT_INDEX  = 6,
    FP_RIGHT_MIDDLE = 7,
    FP_RIGHT_RING   = 8,
    FP_RIGHT_PINKIE = 9
};

ref class fpFinger
{
public:
   
   fpFinger(fpFingerEnum finger);
   System::String^ GetString();
   fpFingerEnum Finger();
   int GetInt();

private:
   fpFingerEnum      m_finger;

};
}

