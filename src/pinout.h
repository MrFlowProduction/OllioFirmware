#ifndef PINOUT_H /* include guards */
#define PINOUT_H

// ===============================================================================
//      NAME                    PIN            DESCRIPTION
// ===============================================================================
#define LED                     19          // Built-in LED
#define HX711_SCK               33          // Clock
#define HX711_DAT               25          // DATA
#define NEO_PIXEL               26          // NEO Pixel LED
#define EXP_INTB                5           // Expander Interrupt Pin
// ===============================================================================

// Expander Pinout
// ===============================================================================
//      NAME                    PIN          DESCRIPTION
// ===============================================================================
#define BUTTON_LED              4         // Button backlight
#define TANK_SENSOR             0         // Tank full sensor
#define USER_BUTTON             1         // User control button
#define DOOR_SENSOR             2         // User control button
#define DC_EN                   8         // Tank full sensor
#define DC_IN1                  10        // User control button
#define DC_IN2                  9         // User control button
// ===============================================================================

// ADS1115 ADC
// ===============================================================================
//      NAME                    PIN          DESCRIPTION
// ===============================================================================
#define PROBE_PIN               0         // User control button
// ===============================================================================


#endif