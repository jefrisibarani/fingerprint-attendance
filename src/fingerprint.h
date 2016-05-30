/******************************************************************************
* filename : fingerprint.h
* author   : Jefri Sibarani
* created  : July 23 2006
* summary  : Contains main application class
*
******************************************************************************/

#pragma once

#include "fpdefs.h"
#include "db/libpqxxConn.h"
#include "fpOperator.h"
#include "applog.h"
#include "appSettings.h"
#include "fpDateTime.h"
#include "fingerPrintAppForm.h"

#define LOG_MANAGER() fingerprintApp::logManager
#define FP_LOGMESSAGE LOG_MANAGER().Log 
#define SETTINGS_MANAGER() fingerprintApp::settingsManager

namespace FingerPrint
{

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


    //static int DecodeTime(String^ binaryTime);

    enum InitDeviceResult
    {
        NO_DEVICE =0,
        DEVICE_FOUND,
    };

    /** fingerprintApp class,Main application class.
     * This is the main class. which starts up 
     * <ul> settingsManager
     * <ul> logManager
     * <ul> initializing Finger Print devices(s)
     * <ul> start up main form ( fingerPrintAppForm )
     */
    public ref class fingerprintApp : public ApplicationContext

    {
    public:
        fingerprintApp(void);
        void OnApplicationExit( Object^ /*sender*/, EventArgs^ /*e*/ );
    public :

        System::Void InitFP_Device();

        /** Returns current Finger Print device. */
        static DpSdkEngLib::FPDevice^ GetDevice();
      
        /** Return device Serial Number. */
        static System::String^ GetDeviceSerialNumber();
        /** Returns total devices. */
        int GetDeviceCount();

        static pqxxConn *GetConnection();

		
		//static bool SendEmail(/*String^ from,String^ to,String^ subject,*/String^ body);

        /** Last date and time. */
        static fpDateTime timeChecker;

        /** Application Setttings manager. */
        static appSettings settingsManager;
        
        /** Application Logging manager. */
        static appLog logManager;
        
        static fpOperator^ GetCurrentOperator();

        /** Application connection object to postgreSQL database. */
        static pqxxConn *fpConn;

        static bool debuggingMode;
        fingerPrintAppForm^ theAppForm;                        ///< Main application form.
        void TestDateTime();

        static String^ user_name;
        static fpOperator^ m_operator;
        static bool IsConnected;
        static String^ timeToDecode;
        static bool formVerifyFingerIsOpen;
    protected:
        ~fingerprintApp()
        {}
    private :
        static DpSdkEngLib::FPDevice^ m_currentDevice;         ///< pointer to the selected device.
        DpSdkEngLib::FPDevices^ m_deviceList;                  ///< device manager object.
        static int deviceCount;                                         
        String^ m_currentDeviceSN;                             ///< current device Serial Number.   

        int formCount;


        System::Drawing::Rectangle mainAppFormPosition;
        FileStream^ userData;    

        void OnFormClosing( Object^ sender, CancelEventArgs^ /*e*/ );
        void OnFormClosed( Object^ /*sender*/, EventArgs^ /*e*/ );
        
        System::Void OnFPDevice_FingerLeaving( );
        System::Void OnFPDevice_FingerTouching(/*System::Object^  sender,DpSdkEngLib::_IFPDeviceEvents_Event^  e*/);

       void CheckDateTime();
       
       bool closeClean;
    };
}