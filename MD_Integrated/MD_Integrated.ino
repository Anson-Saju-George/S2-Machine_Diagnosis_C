#define BLYNK_TEMPLATE_ID "TMPLoRk7iCKW"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "_B79PCTjNrwx7vJ7fW2JRJRz9BUAQWeD"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>
// set the pin number for the vibration sensor
const int vibPin = 14;
// set the pin number for the LM35 sensor
const int lm35Pin = 32;
Adafruit_MPU6050 mpu;

float getTemperature() {
  // read the voltage from the LM35 sensor
  float voltage = analogRead(lm35Pin) * 3.3 / 4095.0;

  // convert the voltage to temperature in degrees Celsius
  float temperature = -(voltage - 0.5) * 100.0;

  return temperature;
}

int getVibrationCount() {
  // set the time interval for counting vibrations (in milliseconds)
  const int interval = 100; // 100 milliseconds

  // variables for counting vibrations
  static unsigned long prevMillis = 0;
  static int vibrationCount = 0;

  // read the vibration sensor
  int vibration = digitalRead(vibPin);

  // if vibration is detected, increment the vibration count
  if (vibration == HIGH) {
    vibrationCount++;
  }

  // check if it is time to count the vibrations
  unsigned long currentMillis = millis();
  if (currentMillis - prevMillis >= interval) {
    // save the vibration count and update the previous time
    int count = vibrationCount;
    prevMillis = currentMillis;
    vibrationCount = 0;
    return count;
  }

  return 0;
}

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "ASG"; // Enter your WiFi SSID here
char pass[] = "Limited Edition";

void setup()
{
  Serial.begin(115200);
  pinMode(vibPin, INPUT);

  // initialize the MPU6050 sensor
  Wire.begin();
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
  Blynk.begin(auth, ssid, pass);
}
void loop() {
  // read the MPU6050 sensor
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  // get the temperature from the LM35 sensor
  float t = getTemperature();
  float temperature = -t;
  // get the vibration count from the vibration sensor
  int vibrationCount = getVibrationCount();

  // print the sensor values
  Serial.print("Accelerometer (m/s^2): ");
  Serial.print(a.acceleration.x);
  Serial.print(", ");
  Serial.print(a.acceleration.y);
  Serial.print(", ");
  Serial.print(a.acceleration.z);
  Serial.print(" | Gyroscope (deg/s): ");
  Serial.print(g.gyro.x);
  Serial.print(", ");
  Serial.print(g.gyro.y);
  Serial.print(", ");
  Serial.print(g.gyro.z);
  Serial.print(" | Temperature (C): ");
  Serial.print(temperature);
  Serial.print(" | Vibrations: ");
  Serial.println(vibrationCount);
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, vibrationCount);
  Blynk.virtualWrite(V2, g.gyro.x);
  Blynk.virtualWrite(V3, g.gyro.y);
  Blynk.virtualWrite(V4, g.gyro.z);
  Blynk.virtualWrite(V5, a.acceleration.x);
  Blynk.virtualWrite(V6, a.acceleration.y);
  Blynk.virtualWrite(V7, a.acceleration.z);
  Blynk.run();
  // wait for 50 milliseconds before taking the next sensor readings
  delay(500);
}

