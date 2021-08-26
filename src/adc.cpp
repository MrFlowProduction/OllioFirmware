#include <adc.h>

ADS1115 ads(0x48);

/* INIT adc module */
void INIT_ADC(){
    
    printinit("ADS1115 ADC Module", true);
    Serial.print("ADS1X15_LIB_VERSION: ");
    Serial.println(ADS1X15_LIB_VERSION);

    ads.begin();
    

    if(!ads.isConnected()){
        printreason("Not available!");
        return;
    }

    ads.setGain(0);      // 6.144 volt
    ads.setDataRate(0);  // SLOW
    ads.setMode(0);      // continuous mode
    ads.readADC(0);      // first read to trigger

    isAdcReady = true;
    printdone();
}


/* Read probe voltage */
float readProbeVoltage(){

    // Check State
    if(!isAdcReady) { return 0.0; }

    // Read analog voltage
    int16_t value = ads.readADC(PROBE_PIN);  

    // voltage factor
    float f = ads.toVoltage(1);  

    // Convert to voltage and return
    return f * value;
}


/* Read ADC Values*/
void adc_reading(){
    probe_votlage = readProbeVoltage();
}