#include <terminal.h>
#include <expander.h>
#include <string.h>
#include <lcd.h>
#include <scale.h>


void INIT_TERMINAL(){
    Serial.begin(BAUDRATE);
}


void printSysData(char* version){

  Serial.print(F("\nOllio Firmware "));
  Serial.println(version);
  
}


void printtestpassed(){
  Serial.println(F("[TEST PASSED]\n"));
}


void printtestfailed(){
  Serial.println(F("[TEST FAILED]\n"));
}


void printready(){
  Serial.println(F("[RDY]"));
}


void printdone(){
  Serial.println(F("[DONE]"));
}

void printfail(){
  Serial.println(F("[FAIL]"));
}

void printok(){
  Serial.println(F("[OK]"));
}

void printerror(){
  Serial.println(F("[ERROR]"));
}


void printinit(String text, bool withNewLine){

  Serial.print(F("\n[INIT]\n"));
  Serial.print(text);
  Serial.print("...");

  if(withNewLine){
    Serial.println();
  }

  
}

void printreason(String text, bool withFail){

  if(withFail){
    printfail();
  }

  Serial.print(F("[REASON]: "));
  Serial.print(text);
  Serial.println();

}


void terminal_handler() {

  if (Serial.available() > 0) {

    String temp = "";

    while (Serial.available() > 0) {

      temp = Serial.readStringUntil('\n');
      temp.trim();

      delay(1);
    }


    // ========================== System ==================================

    if (temp == "setup system") {
    }

    else if (temp == "mode none"){
      statePoint = NONE;
      Serial.println("LCD mode set to NONE");
    }

    else if (temp == "mode shorting"){
      statePoint = SHORTING;
      Serial.println("LCD mode set to SHORTING");
    }

    else if (temp == "mode separete"){
      statePoint = SEPARATE;
      Serial.println("LCD mode set to SEPARATE");
    }

    else if (temp == "mode measure"){
      statePoint = MEASURE;
      Serial.println("LCD mode set to MEASURE");
    }

    else if (temp == "mode printing"){
      statePoint = PRINTING;
      Serial.println("LCD mode set to PRINTING");
    }

    else if (temp == "mode closing"){
      statePoint = CLOSING;
      Serial.println("LCD mode set to CLOSING");
    }

    else if (temp == "mode service"){
      statePoint = SERVICE;
      Serial.println("LCD mode set to SERVICE");
    }

    else if (temp == "mode demo"){
      statePoint = DEMO;
      Serial.println("LCD mode set to DEMO");
    }

    else if (temp == "mode fault"){
      statePoint = FAULT;
      Serial.println("LCD mode set to FAULT");
    }

    else if (temp == "buttonled on"){
      
      Serial.println("Button Led On");
      setButtonLight(true);
      
    }

    else if (temp == "buttonled off"){
      
      Serial.println("Button Led Off");
      setButtonLight(false);
    }

    else if (temp == "readsens"){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sensor table");
      
      Serial.println("Reading sensors:");
      
      lcd.setCursor(0,1);
      int val = getSensValue(DOOR_SENSOR);
      lcd.print("Door Sensor: "+String(val));
      Serial.println("DOOR sensor:"+String(val));
      
      lcd.setCursor(0,2);
      val = getSensValue(TANK_SENSOR);
      lcd.print("TANK Sensor: "+String(val));
      Serial.println("TANK sensor:"+String(val));
      
      lcd.setCursor(0,3);
      val = getSensValue(USER_BUTTON);
      lcd.print("USER Button: "+String(val));
      Serial.println("USER_BUTTON:"+String(val));

      INIT_SCALE();
      acquire_reading();
      
    }

    else if (temp == "progress") {
      Serial.println("Give me a percentage value from 1 to 100:");

      boolean waitForNum = true;
      //char array[4];
      while (waitForNum) {

        temp = Serial.readStringUntil('\n');
        temp.trim();
        //unsigned int n = temp.length();
        //Serial.println(n);
        //temp.toFloat();
        //temp.toCharArray(array, n);
        if (temp != NULL) {
          waitForNum = false;
        }
        Serial.println(temp);
        delay(1);
      }
      progress = temp.toFloat();
      Serial.printf("progress set to %.1f%%\n", progress);
    }

    else {
      
      char buf[temp.length()+1];
      temp.toCharArray(buf,0,temp.length()+1);
      Serial.printf("Unknown command: %s\n",buf);
    }

  }
}