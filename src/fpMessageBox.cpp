#include "StdAfx.h"
#include "fpMessageBox.h"

using namespace FingerPrint;

fpMessageBox::fpMessageBox(System::String^ txtToShow,System::String^ timeToShow)
{
	InitializeComponent();

    SetMessage(txtToShow);
	SetTime(timeToShow);
}