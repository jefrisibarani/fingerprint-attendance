/******************************************************************************
* filename : fpFinger.cpp
* author   : Jefri Sibarani
* created  : November 17 2006
* summary  : enum class for fingers
*
******************************************************************************/

#include "StdAfx.h"
#include "fpFinger.h"

using namespace FingerPrint;

fpFinger::fpFinger(fpFingerEnum finger)
{
   m_finger = finger;
}

fpFingerEnum fpFinger::Finger()
{

   return m_finger;
}
int fpFinger::GetInt()
{
   switch ( m_finger )
   {
      case FP_LEFT_THUMB:
         return 0;
      case FP_LEFT_INDEX:
         return 1;
      case FP_LEFT_MIDDLE:
         return 2;
      case FP_LEFT_RING:
         return 3;
      case FP_LEFT_PINKIE:
         return 4;
      case FP_RIGHT_THUMB:
         return 5;
      case FP_RIGHT_INDEX:
         return 6;
      case FP_RIGHT_MIDDLE:
         return 7;
      case FP_RIGHT_RING:
         return 8;
      case FP_RIGHT_PINKIE:
         return 9;
   }
   return -1;
}
System::String^ fpFinger::GetString()
{
   switch ( m_finger )
   {
      case FP_LEFT_THUMB:
         return gcnew System::String("Jempol kiri");
      case FP_LEFT_INDEX:
         return gcnew System::String("Telunjuk kiri");
      case FP_LEFT_MIDDLE:
         return gcnew System::String("Tengah kiri");
      case FP_LEFT_RING:
         return gcnew System::String("Manis kiri");
      case FP_LEFT_PINKIE:
         return gcnew System::String("Kelingking kiri");
      case FP_RIGHT_THUMB:
         return gcnew System::String("Jempol kanan");
      case FP_RIGHT_INDEX:
         return gcnew System::String("Telunjuk kanan");
      case FP_RIGHT_MIDDLE:
         return gcnew System::String("Tengah kanan");
      case FP_RIGHT_RING:
         return gcnew System::String("Manis kanan");
      case FP_RIGHT_PINKIE:
         return gcnew System::String("Kelingking kanan");
   }
   return System::String::Empty;
}