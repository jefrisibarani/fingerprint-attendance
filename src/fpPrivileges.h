#pragma once


namespace FingerPrint
{
   enum fpPrivileges
   {
      ABSEN_ONLY  = 1 << 0,
      REGISTER_ONLY  = 1 << 1,
      EDIT_USER_ONLY  = 1 << 2,
      SUPERVISOR  = 1 << 3,
      ADMINISTRATOR = ABSEN_ONLY | REGISTER_ONLY | EDIT_USER_ONLY | SUPERVISOR
   };

}

