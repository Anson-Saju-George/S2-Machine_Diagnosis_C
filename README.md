# Real-Time IoT Based Pre & Post Machine Diagnosis & Fault Analysis

## 🎯 Project Overview
This repository contains a comprehensive **IoT-based Machine Diagnosis System** developed during my **Second Semester**. The project implements real-time monitoring and fault analysis of industrial machines using multiple sensors and cloud connectivity through the Blynk platform.

## 📋 Project Details
- **Student:** Anson Saju George
- **Semester:** 2nd Semester
- **Project Type:** IoT-based Machine Condition Monitoring
- **Platform:** ESP32 with Arduino IDE
- **Cloud Platform:** Blynk IoT

## 🔧 System Architecture

### Hardware Components
- **ESP32 Development Board** - Main microcontroller with Wi-Fi capability
- **MPU6050** - 6-axis accelerometer and gyroscope sensor
- **LM35** - Temperature sensor for thermal monitoring
- **Vibration Sensor** - Digital vibration detection sensor
- **Wi-Fi Connectivity** - For real-time data transmission to cloud

### Sensor Configuration
- **Vibration Sensor Pin:** GPIO 14
- **Temperature Sensor Pin:** GPIO 32 (Analog)
- **I2C Communication:** For MPU6050 (SDA/SCL)

## 📊 Monitored Parameters

### 1. **Vibration Analysis**
- Real-time vibration counting
- Digital vibration detection
- 100ms sampling interval for accurate measurement

### 2. **Temperature Monitoring**
- Continuous temperature measurement using LM35
- Voltage to temperature conversion
- Thermal fault detection capabilities

### 3. **Motion Analysis**
- **Accelerometer Data:** 3-axis acceleration (m/s²)
- **Gyroscope Data:** 3-axis angular velocity (deg/s)
- Motion pattern analysis for anomaly detection

## 📁 Repository Structure
```
├── README.md                                    # Project documentation
├── IMAGES/                                      # Project images and screenshots
│   ├── MD blink app.jpg                        # Blynk mobile app interface
│   ├── MD open img.jpg                         # Hardware setup images
│   ├── MD top open view.jpg                    # Top view of the system
│   └── Real-Time IoT Based... .jpg             # System overview images
├── MD_Integrated/                              # Complete integrated system
│   └── MD_Integrated.ino                       # Full IoT implementation with Blynk
├── MD_sketch/                                  # Basic sensor monitoring
│   └── MD_sketch.ino                           # Standalone sensor reading code
├── MD_WiFi/                                    # Wi-Fi connectivity module
│   └── MD_WiFi.ino                            # Network configuration code
├── source/                                     # Source code backup
│   ├── MD_Integrated.ino
│   ├── MD_sketch.ino
│   └── MD_WiFi.ino
├── MD_Paper/                                   # Research documentation
│   ├── Real-Time IoT Based... .docx           # Project paper
│   └── Real-Time IoT Based... .pdf            # Published paper
├── MD Reference Paper/                         # Academic references
└── Documentation Files/                        # Project reports and presentations
    ├── 1st IOT-based Pre & Post Machine...docx
    ├── MACHINE DIAGNOSIS INFORMATION.docx
    ├── MD Report 2.0.docx
    └── SUD PPT.pptx
```

## 💻 Code Implementation

### Main Features

#### 1. **Sensor Data Acquisition**
```cpp
// Temperature reading from LM35
float getTemperature()
// Vibration counting with time-based sampling
int getVibrationCount()
// MPU6050 accelerometer and gyroscope data
sensors_event_t a, g, temp;
```

#### 2. **Cloud Connectivity (Blynk Integration)**
- **Template ID:** TMPLoRk7iCKW
- **Real-time data streaming** to 8 virtual pins (V0-V7)
- **Remote monitoring** through Blynk mobile app
- **Data visualization** and historical analysis

#### 3. **Multi-Version Implementation**
- **MD_Integrated.ino:** Complete IoT system with cloud connectivity
- **MD_sketch.ino:** Basic sensor monitoring for local analysis
- **MD_WiFi.ino:** Network configuration and connectivity testing

## 📱 Blynk Dashboard Configuration

| Virtual Pin | Parameter | Unit |
|-------------|-----------|------|
| V0 | Temperature | °C |
| V1 | Vibration Count | Count |
| V2 | Gyro X-axis | deg/s |
| V3 | Gyro Y-axis | deg/s |
| V4 | Gyro Z-axis | deg/s |
| V5 | Accel X-axis | m/s² |
| V6 | Accel Y-axis | m/s² |
| V7 | Accel Z-axis | m/s² |

## 🚀 Getting Started

### Prerequisites
- Arduino IDE with ESP32 board package
- Required Libraries:
  ```cpp
  #include <WiFi.h>
  #include <BlynkSimpleEsp32.h>
  #include <Adafruit_Sensor.h>
  #include <Adafruit_MPU6050.h>
  ```

### Installation & Setup
1. **Hardware Connection:**
   - Connect MPU6050 to I2C pins
   - Connect LM35 to GPIO 32
   - Connect vibration sensor to GPIO 14

2. **Software Configuration:**
   - Update Wi-Fi credentials in the code
   - Configure Blynk authentication token
   - Upload the desired sketch to ESP32

3. **Blynk Setup:**
   - Install Blynk mobile app
   - Create new project with provided template
   - Configure widgets for data visualization

## 📊 System Capabilities

### Pre-Diagnosis Features
- **Baseline Establishment:** Normal operating parameter ranges
- **Preventive Monitoring:** Continuous parameter tracking
- **Early Warning System:** Threshold-based alerts

### Post-Diagnosis Features
- **Fault Analysis:** Pattern recognition in sensor data
- **Historical Data:** Trend analysis for predictive maintenance
- **Remote Diagnostics:** Cloud-based monitoring and analysis

## 🎓 Learning Outcomes
This project provided hands-on experience with:
- **IoT System Design:** End-to-end IoT implementation
- **Sensor Integration:** Multiple sensor fusion techniques
- **Cloud Connectivity:** Real-time data streaming
- **Embedded Programming:** ESP32 and Arduino development
- **Data Analysis:** Machine condition monitoring principles
- **Research Skills:** Academic paper writing and documentation

## 📈 Future Enhancements
- Machine Learning integration for predictive analysis
- Additional sensor types (current, voltage, acoustic)
- Local data storage with SD card logging
- Advanced fault classification algorithms
- Web-based dashboard development

## 📚 Academic Context
This project was developed as part of the second semester curriculum, demonstrating the integration of:
- Internet of Things (IoT) concepts
- Embedded systems programming
- Sensor interfacing and data acquisition
- Cloud computing and remote monitoring
- Research methodology and technical documentation

---
**Note:** This is an academic project created for educational purposes, showcasing IoT-based industrial monitoring solutions.