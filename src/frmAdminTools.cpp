#include "StdAfx.h"

#include "fingerprint.h"
#include "utils.h"
#include "appOptions.h"
#include "dlgNeedPassword.h"
#include "frmAdminTools.h"

using namespace FingerPrint;

frmAdminTools::frmAdminTools(void)
{
	InitializeComponent();
   m_convertMode = READ_FROM_BINARY;
   m_cbConversionMode->SelectedIndex = 0;

}

System::Void frmAdminTools::OnCbConversionChanged(System::Object^  sender, System::EventArgs^  e)
{
   if ( m_cbConversionMode->SelectedIndex == 0 )
      m_convertMode = READ_FROM_BINARY;
   if ( m_cbConversionMode->SelectedIndex == 1 )
      m_convertMode = TIME_TO_BINARY;

}

System::Void frmAdminTools::OnDoConversion(System::Object^  sender, System::EventArgs^  e)
{
   String^ source = this->m_txtconversionsource->Text;
   if ( m_convertMode == READ_FROM_BINARY )
      this->m_lblTimeConversionResult->Text = GiveMeReadableEncodedDateTime(source);
   if ( m_convertMode == TIME_TO_BINARY )
   {
               MessageBox::Show( "\n" + "Sorry, Unimplemented yet, please wait for new release",
                             "",
                             MessageBoxButtons::OK,
                             MessageBoxIcon::Information );
   }
}