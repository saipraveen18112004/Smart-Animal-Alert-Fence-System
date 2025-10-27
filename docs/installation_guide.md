# Installation & Setup Guide

## Hardware Setup
1. Connect sensors (IR, PIR, Ultrasonic, LDR, DHT11) to ESP32.
2. Attach relay to buzzer, LED, and water pump.
3. Connect SIM800L or Wi-Fi module.
4. Power with solar/battery supply.

## Software Setup
1. Install Arduino IDE and required libraries:
   - WiFi.h
   - HTTPClient.h
2. Upload `animal_alert.ino` to ESP32.
3. For YOLO:
   ```bash
   pip install ultralytics opencv-python requests
   python yolo_detection.py
