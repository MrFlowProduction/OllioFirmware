#include <expander.h>

Adafruit_MCP23017 mcp;

bool isMcpConnected;

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

    isMcpConnected = true;
}

