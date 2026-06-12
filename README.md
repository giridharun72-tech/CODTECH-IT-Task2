# TASK 2: IoT WEATHER STATION PROTOCOLS

## 👤 Intern Information
* **Intern ID:** CITS4432
* **Full Name:** Giridharun S
* **Domain:** Internet of Things (IoT)
* **Duration:** 4 Weeks

---

## 📌 Project Overview
This project presents an intermediate-level architectural design for an IoT environmental telemetry logging node built using an ESP32 microcomputing unit. Developed as a high-fidelity software model, the system samples localized ambient atmospheric changes via digital data pipelines and displays metrics dynamically to an onboard character terminal interface.

This model is configured to manage rapid environmental sampling cycles safely while outputting system diagnostics via high-speed serial outputs.
---

## 🔗 Live Simulation
You can view and run the real-time simulation of this IoT Weather Station on Wokwi here:
[View Live Project](https://wokwi.com/projects/466592433088880641)
---

## 🏗️ System Architecture
The data collection architecture flows systematically as detailed below:

```text
[ DHT22 Sensor Node ] ──(Digital GPIO 15)──> [ ESP32 MCU ] ──(I2C Pins 21/22)──> [ LCD Display 16x2 ]
                                                  │
                                                  └──(UART Terminal)──> [ Serial Monitor Logs ]
