#include <expander.h>

// MCP Library
Adafruit_MCP23017 mcp;

// MCP Connection state
bool isMcpConnected;


/* Init expander */
void INIT_EXTERNAL_PORTS(){
    
    printinit("MCP23017 I/O Expander");

    if(i2c_address_check(0x20) > 0){
        printreason(F("Not available"));
        return;
    }

    // Init connection
    mcp.begin();

    // Init pin directions
    mcp.pinMode(BUTTON_LED,     OUTPUT);
    mcp.pinMode(TANK_SENSOR,    INPUT);
    mcp.pinMode(USER_BUTTON,    INPUT);
    mcp.pinMode(DOOR_SENSOR,    INPUT);
    mcp.pinMode(DC_EN,          OUTPUT);
    mcp.pinMode(DC_IN1,         OUTPUT);
    mcp.pinMode(DC_IN2,         OUTPUT);

    // turn on a 100K pullup internally
    mcp.pullUp(TANK_SENSOR, HIGH);  
    mcp.pullUp(USER_BUTTON, HIGH);  
    mcp.pullUp(DOOR_SENSOR, HIGH);  

    mcp.digitalWrite(BUTTON_LED, HIGH);
    mcp.setupInterruptPin(USER_BUTTON, FALLING);
    mcp.setupInterruptPin(TANK_SENSOR, CHANGE);
    mcp.setupInterruptPin(USER_BUTTON, CHANGE);

    attachInterrupt(EXP_INTB, handlingExpInterrupt, FALLING);

    isMcpConnected = true;

    InitExpanderStates();

    printdone();
}


/* Init Default States */
void InitExpanderStates(){
    isTankFull = !mcp.digitalRead(TANK_SENSOR);
    isDoorOpened = mcp.digitalRead(DOOR_SENSOR);
}



/* Handling Interrupts */
void handlingExpInterrupt(){
    
    // Get more information from the MCP from the INT
    uint8_t pin=mcp.getLastInterruptPin();
    uint8_t val=mcp.getLastInterruptPinValue();

    // Handling user button
    if (pin == USER_BUTTON){
        isButtonPressed = true;
    }

    // Handling water tank
    if(pin == TANK_SENSOR){
        if(val == 0) {isTankFull = true; }
        else{ isTankFull = false; }
    }

    // Handling Door sensor
    if(pin == DOOR_SENSOR){
        if(val == 0) {isDoorOpened = false; }
        else{ isTankFull = true; }
    }
}


/* Set DC Motor driver pins */
void setDcMotorPins(bool in1, bool in2, bool enable){

    if(!isMcpConnected){ return; }

    mcp.digitalWrite(DC_IN1, in1);
    mcp.digitalWrite(DC_IN2, in1);
    mcp.digitalWrite(DC_EN, enable);

}


/* Set User button backlight */
void setButtonLight(bool state){

    if(!isMcpConnected){ return; }

    mcp.digitalWrite(BUTTON_LED, state);

}

