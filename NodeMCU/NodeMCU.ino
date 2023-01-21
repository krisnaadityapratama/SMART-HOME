#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "kq1SM774NRCw23r78fjhXMMY6bqUKRyb";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "My Room";
char pass[] = "bangkris18";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass, "iot.amikom.ac.id", 8080);
}

void loop()
{
  Blynk.run();
}
