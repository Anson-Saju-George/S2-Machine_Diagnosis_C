#include <Wire.h>
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
  float temperature = (voltage - 0.5) * 100.0;

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

void setup() {
  // start the serial communication
  Serial.begin(9600);

  // set the vibration sensor pin as input
  pinMode(vibPin, INPUT);

  // initialize the MPU6050 sensor
  Wire.begin();
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
}

void loop() {
  // read the MPU6050 sensor
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // get the temperature from the LM35 sensor
  float temperature = getTemperature();

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

  // wait for 50 milliseconds before taking the next sensor readings
  delay(200);
}