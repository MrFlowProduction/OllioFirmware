#include "terminal.h"
#include <Arduino.h> /* we need arduino functions to implement this */



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
    char c;

    while (Serial.available() > 0) {
      c = (char)Serial.read();

      if (c == '@') {
        Serial.flush();
        return;
      }

      if (c == '\n' || c == '\r') {
        continue;
      }

      temp += c;
      delay(1);
    }


    // ========================== System ==================================

    if (temp == "setup system") {
    }

    else if (temp == "usbmode"){
      printdone();
    }

    else {
      Serial.println(F("Unknown command"));
    }

  }
}