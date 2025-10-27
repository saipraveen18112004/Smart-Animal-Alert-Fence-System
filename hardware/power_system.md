# SmartFence++ - Power Management System

## ⚡ Power Sources
- **Primary:** 12V Solar Panel (10W)
- **Backup:** 12V 7Ah Battery
- **Optional:** DC Adapter for indoor testing

## 🔋 Power Flow
1. Solar Panel → Charging Controller → Battery
2. Battery → ESP32 Controller + Sensors + Deterrents
3. Controller automatically switches between solar and battery during night.

## 🔌 Charging Controller Role
- Prevents overcharging and discharging
- Manages current flow between solar and battery
- Provides stable 5V/12V output for ESP32 and modules

## 💡 Consumption Estimates
| Module | Voltage | Current | Power |
|---------|----------|----------|--------|
| ESP32 | 5V | 200 mA | 1.0 W |
| Sensors | 5V | 150 mA | 0.75 W |
| Relay Module | 5V | 100 mA | 0.5 W |
| Deterrents | 12V | 500 mA | 6 W |
| **Total:** | — | — | **~8.25 W** |

🔋 With a 7Ah battery, the system can run for **~8–10 hours** without sunlight.
