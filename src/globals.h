#ifndef GLOBALS_H /* include guards */
#define GLOBALS_H

#include <Arduino.h> /* we need arduino functions to implement this */

// ____________________________________________ Globals ___________________________________________________
// ========================================================================================================
// TYPE             NAME                    DEF. VALUE         DESCRIPTION
// ========================================================================================================
extern char                wifi_ssid[]; // Router SSID
extern char                wifi_pass[];     // Router Password
extern bool                terminal_enabled;
extern bool                wifi_connected;
// ========================================================================================================

#endif

