#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPLwrIYwRuL"
#define BLYNK_DEVICE_NAME "SmartHome"
#define BLYNK_AUTH_TOKEN "Qu3OUzhKSCLcZ44rdCPebb1RLh1OzAF4"
 
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 
 
// You should get Auth Token in the Blynk App. 
// Go to the Project Settings (nut icon). 
char auth[] = BLYNK_AUTH_TOKEN; 
 
// Your WiFi credentials. 
// Set password to "" for open networks. 
char ssid[] = "My Room";
char pass[] = "bangkris18";
 
void setup() 
{ 
  // Debug console 
  Serial.begin(9600); 
 
  Blynk.begin(auth, ssid, pass); 
  // You can also specify server: 
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80); 
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080); 
} 
 
void loop() 
{ 
  Blynk.run(); 
}
