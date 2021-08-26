#ifndef GLOBALS_H /* include guards */
#define GLOBALS_H

#include <Arduino.h> /* we need arduino functions to implement this */

// ____________________________________________ Globals ___________________________________________________
// ========================================================================================================
// TYPE                     NAME                    DEF. VALUE         DESCRIPTION
// ========================================================================================================
extern char                 wifi_ssid[]; // Router SSID
extern char                 wifi_pass[];     // Router Password
extern bool                 terminal_enabled;
extern bool                 wifi_connected;
extern bool                 isExpanderReady;
extern bool                 isAdcReady;
extern bool                 isScaleReady;
extern volatile bool        isButtonPressed;
extern volatile bool        isTankFull;
extern volatile bool        isDoorOpened;
extern byte                 tapState;
extern byte                 statePoint;
extern float                probe_votlage;
extern float                progress;
extern float                oilquality_max;
extern float                oilquality_min;
extern bool                 task_scale_isEnabled;
extern bool                 task_ads_isEnabled;
extern volatile byte        error_code;
//extern int                  machineState;
// ========================================================================================================

#endif

