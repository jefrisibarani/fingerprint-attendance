/******************************************************************************
* filename : fpDateTime.h
* author   : Jefri Sibarani
* created  : November 17 2006
* summary  : Time checker class
*
******************************************************************************/

#pragma once
#pragma warning(disable:4677)

/**
   Time checker class.
   this class is a static member of fingerprintApp class, which must be initialized
   before settingsManager.

   settingsManager will load last logged datetime from application settings file
   ( fingerprint-conf.xml ) then sets this class new value ( m_dateTime ) from loaded 
   datetime.


 */

ref class fpDateTime
{
public:
   fpDateTime(void);
   fpDateTime( System::DateTime dt );
   
   fpDateTime( System::String^ dtInBase64);
   
   fpDateTime( System::Int64 dtInInt64);


   /// Initialize from DateTime.
   void FromDateTime(System::DateTime dt);

   /// Initialize from binary form. 
   void FromBinary(System::String^ dtInBase64);

   /// Initialize from encoded Base64 seting binary form.
   /// If input conversion error occured, m_dateTime will nerver changed
   void FromBinary(System::Int64 dtInInt64);

   /** Synchronize m_dateTime with current system time. */
   fpDateTime^ Now();

   /** Returns m_dateTime in binary in Base64 encoded string.*/
   System::String^ GetBase64();

   /** Returns m_datetime in binary. */
   Int64           GetBinary();

   ///  Return m_dateTime time stamp.
   System::String^ GetTimeStamp(String^ format);

   /// Return m_DateTime.
   System::DateTime GetDateTime(){return m_dateTime;}

   /** Returns true if system time changed.
       
       ONLY USE WITH fingerprintApp::timeChecker.IsTimeChanged()
       
       This function also set systemTimeClean false.
       fingerPrintAppForm does the check every 0.5 seconds in functions
       fingerPrintAppForm::TimerEventProcessor( Object^, EventArgs^) and 
       fingerPrintAppForm::WatchTimeChange()
    */   
   bool IsTimeChanged();
   bool IsSystemTimeClean() { return systemTimeClean; }


private:

   /** Last logged time. updated every 0.5 second by fingerPrintAppForm::TimerEventProcessor */
   System::DateTime m_dateTime;

   /** Application initial run time */
   System::DateTime m_firstTimeRun;

   bool systemTimeClean;

};
