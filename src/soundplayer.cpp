#include "stdafx.h"

#include "fingerprint.h"
#include "soundplayer.h"

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Media;

void FingerPrint::PlayFailedSound()
{
    String^ soundfile = fingerprintApp::settingsManager.GetFailedSound();
    /*FingerPrint::*/PlayTheSound(soundfile);
}
void FingerPrint::PlaySuccesSound()
{
    String^ soundfile = fingerprintApp::settingsManager.GetSuccessSound();
    /*FingerPrint::*/PlayTheSound(soundfile);
}

void FingerPrint::PlayTheSound(String^ filetoplay)
{
    FP_LOGMESSAGE(filetoplay); 
    
      try
      {
         SoundPlayer^ simpleSound = gcnew SoundPlayer(filetoplay);
         simpleSound->Play();
      }
      catch(FileNotFoundException^ ex)
      {
         FP_LOGMESSAGE(System::String::Concat("FingerPrint::PlayTheSound() error : ", ex->Message ) ); 
         return;
      }
      catch(InvalidOperationException^ ex)
      {
         FP_LOGMESSAGE(System::String::Concat("FingerPrint::PlayTheSound() error : ", ex->Message ) ); 
         return;
      }
}