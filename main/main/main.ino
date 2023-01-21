#ifdef ENABLE_DEBUG
   #define DEBUG_ESP_PORT Serial
   #define NODEBUG_WEBSOCKETS
   #define NDEBUG
#endif 

#include <Arduino.h>
#ifdef ESP8266 
   #include <ESP8266WiFi.h>
#endif 
#ifdef ESP32   
   #include <WiFi.h>
#endif

#include "SinricPro.h"
#include "SinricProSwitch.h"

#define WIFI_SSID         "My Room"
#define WIFI_PASS         "bangkris18"
#define APP_KEY           "6e7808f1-4167-4b31-9f99-7e47a814bb0c"
#define APP_SECRET        "798b121f-8051-45ce-889e-a6e8e028b652-221da1a1-1ecf-4254-9587-1d63118b0c97"

#define SWITCH_ID_1       "63cb877d07e1833ecb468399"
#define RELAYPIN_1        5

#define SWITCH_ID_2       "63cb87bc22e49e3cb5ea6eb6"
#define RELAYPIN_2        4

const int ledPin =  13;

// Variables will change:
int ledState = LOW;          
long previousMillis = 0;        
long interval = 3000;    

#define BAUD_RATE         115200                // Change baudrate to your need

bool onPowerState1(const String &deviceId, bool &state) {
 Serial.printf("Device 1 turned %s", state?"off":"on");
 digitalWrite(RELAYPIN_1, state ? LOW:HIGH);
 return true; // request handled properly
}

bool onPowerState2(const String &deviceId, bool &state) {
 Serial.printf("Device 2 turned %s", state?"off":"on");
 digitalWrite(RELAYPIN_2, state ? LOW:HIGH);
 digitalWrite(RELAYPIN_1, state ? HIGH:LOW);
 return true; // request handled properly
}

// setup function for WiFi connection
void setupWiFi() {
  Serial.printf("\r\n[Wifi]: Connecting");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.printf(".");
    delay(250);
  }

  Serial.printf("connected!\r\n[WiFi]: IP-Address is %s\r\n", WiFi.localIP().toString().c_str());
}

// setup function for SinricPro
void setupSinricPro() {
  // add devices and callbacks to SinricPro
  pinMode(RELAYPIN_1, OUTPUT);
  pinMode(RELAYPIN_2, OUTPUT);
    
  SinricProSwitch& mySwitch1 = SinricPro[SWITCH_ID_1];
  mySwitch1.onPowerState(onPowerState1);
  
  SinricProSwitch& mySwitch2 = SinricPro[SWITCH_ID_2];
  mySwitch2.onPowerState(onPowerState2);
  
  
  // setup SinricPro
  SinricPro.onConnected([](){ Serial.printf("Connected to SinricPro\r\n"); }); 
  SinricPro.onDisconnected([](){ Serial.printf("Disconnected from SinricPro\r\n"); });
   
  SinricPro.begin(APP_KEY, APP_SECRET);
}

// main setup function
void setup() {
  Serial.begin(BAUD_RATE); Serial.printf("\r\n\r\n");
  setupWiFi();
  setupSinricPro();
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   


      if (ledState == LOW)
        ledState = HIGH;
      else
        ledState = LOW;
    digitalWrite(ledPin, ledState);
  }
  SinricPro.handle();
}
