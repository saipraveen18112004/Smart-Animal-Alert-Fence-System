# SmartFence++ - Hardware Connections

## 1. Sensor Connections (Input)
| Sensor | ESP32 Pin | Function |
|---------|------------|-----------|
| PIR Sensor | GPIO 23 | Motion detection |
| IR Sensor | GPIO 22 | Presence detection |
| Ultrasonic TRIG | GPIO 5 | Trigger pin |
| Ultrasonic ECHO | GPIO 4 | Echo pin |
| LDR Sensor | GPIO 21 | Light detection |
| DHT11 Sensor | GPIO 19 | Temp & Humidity |

---

## 2. Deterrent Connections (Output)
| Actuator | ESP32 Pin | Function |
|-----------|------------|-----------|
| LED / Light Strip | GPIO 18 | Flash deterrent |
| Buzzer / Siren | GPIO 17 | Sound alarm |
| Water Pump (Relay) | GPIO 16 | Spray water |
| Ultrasonic Repeller | GPIO 25 | Emit high-frequency sound |

---

## 3. Communication Modules
| Module | ESP32 Pins | Description |
|---------|-------------|--------------|
| SIM800L | TX2 (17), RX2 (16) | Sends SMS alerts |
| Wi-Fi | Built-in ESP32 | Push notifications or cloud sync |

---

## 4. Power Management
| Component | Input | Output | Function |
|------------|--------|---------|----------|
| Solar Panel | 12V | — | Power source |
| Charging Controller | 12V Solar Input | Charges 12V battery |
| Battery | 12V | ESP32, Sensors, Relays | Backup power |
| Adapter (Optional) | 12V | Direct power during testing |

---

## 5. Additional Components
- **Manual Reset Button** – Connected to GPIO 26 (resets system)
- **Data Logger Module (SD Card)** – SPI pins for storing image logs
