#include <scale.h>

HX711 scale;
//LINKEK
//https://learn.sparkfun.com/tutorials/load-cell-amplifier-hx711-breakout-hookup-guide/all
//https://github.com/sparkfun/HX711-Load-Cell-Amplifier/tree/master/firmware

// 1. HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 25;
const int LOADCELL_SCK_PIN = 33;

// 2. Adjustment settings
long ZERO_FACTOR = 2117;
long LOADCELL_OFFSET = -7070 / 0.45359237; //LBS HELYETT KG-BAN KAPJUK AZ ÉRTÉKET
const long LOADCELL_DIVIDER = 0.45359237;

void INIT_SCALE(){
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    //scale.set_scale(LOADCELL_DIVIDER);
    //scale.set_offset(LOADCELL_OFFSET);
    scale.set_scale();
    scale.tare();

    ZERO_FACTOR = scale.read_average(); //Get a baseline reading
    Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
    Serial.println(ZERO_FACTOR);
}

void  acquire_reading(){
    scale.set_scale(LOADCELL_OFFSET);
    scale.set_offset(ZERO_FACTOR);
    //scale.set_scale(15542);
    Serial.print("Weight: ");
    
    //scale.tare();
    Serial.print(scale.get_units(), 1);

    Serial.println(" kg");

    /*Serial.print(" calibration_factor: ");
    Serial.print(LOADCELL_OFFSET);
    Serial.println();


    if(Serial.available())
    {
        char temp = Serial.read();
        if(temp == '+' || temp == 'a')
        LOADCELL_OFFSET += 10;
        else if(temp == '-' || temp == 'z')
        LOADCELL_OFFSET -= 10;
    }*/
    /*if (scale.wait_ready_timeout(1000)) {
        long reading = scale.get_units(10);
        Serial.print("Weight: ");
        Serial.println(reading, 2);
    } else {
        Serial.println("HX711 not found.");
    }*/
}