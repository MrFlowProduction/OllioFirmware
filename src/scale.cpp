#include <scale.h>

HX711 scale;

// 1. HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

// 2. Adjustment settings
const long LOADCELL_OFFSET = 50682624;
const long LOADCELL_DIVIDER = 5895655;

void INIT_SCALE(){
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    scale.set_scale(LOADCELL_DIVIDER);
    scale.set_offset(LOADCELL_OFFSET);

    if (scale.wait_ready_timeout(1000)) {
        long reading = scale.get_units(10);
        Serial.print("Weight: ");
        Serial.println(reading, 2);
    } else {
        Serial.println("HX711 not found.");
    }
}

void  ACQUIRE_READING(){
    Serial.print("Weight: ");
    Serial.print(scale.read());
    //Serial.println(scale.get_units(10), 2);

    /*if (scale.wait_ready_timeout(1000)) {
        long reading = scale.get_units(10);
        Serial.print("Weight: ");
        Serial.println(reading, 2);
    } else {
        Serial.println("HX711 not found.");
    }*/
}