#define BLYNK_TEMPLATE_ID "TMPLoRk7iCKW"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "_B79PCTjNrwx7vJ7fW2JRJRz9BUAQWeD"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "ASG"; // Enter your WiFi SSID here
char pass[] = "Limited Edition";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  // Add any additional setup code here
}

void loop()
{
  float sensorValue = 14414803; // Replace this with your sensor value

  Blynk.virtualWrite(V0, sensorValue); // Send sensor value to Blynk app using virtual pin V0

  Blynk.run(); // Run Blynk
}
