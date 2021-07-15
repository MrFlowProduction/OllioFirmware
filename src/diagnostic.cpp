#include <diagnostic.h>

// Checking address and return error code
byte i2c_address_check(byte address){
  Wire.beginTransmission(address);
  delay(2);
  return Wire.endTransmission();
}


// I2C address scanner (Serial)
void i2c_scanner(){
  byte error, address;
  uint8_t nDevices;
  
  delay(15); // Sensors PowerUp Time
  Wire.begin();

  Serial.println(F("\nScanning..."));

  nDevices = 0;
   for(address = 0; address <= 127; address++ )
  {
     error = i2c_address_check(address);

    if (error == 0)
    {
      Serial.print(F("I2C device found at address 0x"));
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println(" !");

      nDevices++;
    }
    else if (error==4)
    {
       Serial.print(F("Unknow error at address 0x"));
       if (address<16)
        Serial.print("0");
       Serial.println(address,HEX);
     }
     delay(20);
   }
   if (nDevices == 0)
     printfail();
   else
     printdone();
}


