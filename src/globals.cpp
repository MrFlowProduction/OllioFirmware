#include <globals.h>
#include <enum.h>
// ____________________________________________ Globals ___________________________________________________
// ========================================================================================================
// TYPE             NAME                    DEF. VALUE         DESCRIPTION
// ========================================================================================================
char                wifi_ssid[] =           "Anna & Flori"; // Router SSID
char                wifi_pass[] =           "pO5NNrc6";     // Router Password
bool                terminal_enabled =      true;           // Terminal enabled
bool                wifi_connected =        false;          // Wifi is connected
bool                isExpanderReady =       false;          // MCP23017 I/O Expander Module is ready to use
bool                isAdcReady =            false;          // ADS1115 ADC Module is ready to use
bool                isScaleReady =          false;          // HX711 ADC Module is ready to use
volatile bool       isButtonPressed =       false;          // User button pressed and not handled
volatile bool       isTankFull =            false;          // Tank is fullfilled
volatile bool       isDoorOpened =          false;          // Is top door opened
byte                tapState;                               // Current tap state
byte                statePoint =            NONE;           // Current machine State
float               probe_votlage;                          // Current probe voltage
float               progress;                               // Current progress state in percent
// Oil values
// ========================================================================================================
float               oilquality_max =        10;             // Oil quality max value
float               oilquality_min =        5;              // Oil quality max value
// Scale values
// ========================================================================================================
float               scale_value;                            // Scale measured value
bool                task_scale_isEnabled;                   // Scale task enabling
bool                task_ads_isEnabled;                     // ASD task enabling
volatile byte       error_code =            0;              // Hibak??d
//int                 machineState =          SEPARATE;
// ========================================================================================================