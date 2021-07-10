#include <radio.h>


// Wifi Event Handler
void WiFiEvent(WiFiEvent_t event){
    switch(event) {
        
        case SYSTEM_EVENT_AP_START:
            Serial.println("AP Started");
            //WiFi.softAPsetHostname(AP_SSID);
            break;
            
        case SYSTEM_EVENT_AP_STOP:
            Serial.println("AP Stopped");
            break;
            
        case SYSTEM_EVENT_STA_START:
            Serial.println("\nSTA Started");
            break;
            
        case SYSTEM_EVENT_STA_CONNECTED:
            Serial.println("\nSTA Connected"); 
            break;
            
        case SYSTEM_EVENT_AP_STA_GOT_IP6:
            Serial.print("STA IPv6: ");
            Serial.println(WiFi.localIPv6());
            break;

        case SYSTEM_EVENT_STA_LOST_IP:
            Serial.println("\nLost IP");  
            wifi_connected = false;        
            break;
        
        case SYSTEM_EVENT_STA_GOT_IP:
            Serial.print("\nSTA IPv4: ");
            Serial.println(WiFi.localIP());
            Serial.print("RSSI: ");
            Serial.println(WiFi.RSSI(), DEC);
            wifi_connected = true;
            break;
        
        case SYSTEM_EVENT_STA_DISCONNECTED:

            Serial.println(F("STA Disconnected"));
            wifi_connected = false;   
            break;
        
        case SYSTEM_EVENT_STA_STOP:
           Serial.println("STA Stopped");
           wifi_connected = false;
            break;
        default:
            break;
    }
}


void INIT_WIFI(){

    printinit(F("WiFi"), true);

    Serial.print(F("Set SSID:"));
    Serial.println(wifi_ssid);

    WiFi.onEvent(WiFiEvent);

    WiFi.begin(wifi_ssid, wifi_pass);

    printdone();
}


