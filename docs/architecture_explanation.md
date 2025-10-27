# System Architecture – SmartFence++

The SmartFence++ system is designed using a **5-layer architecture**:

1. **Sensing Layer**  
   - IR, PIR, Ultrasonic, LDR, DHT11 sensors  
   - Detect motion, light, temperature, and humidity  

2. **Processing Layer**  
   - ESP32 Controller + ESP32-CAM  
   - Processes input data, captures images, and controls deterrents  

3. **Action and Deterrent Layer**  
   - Relay module triggers buzzer, LED, water pump, and ultrasonic repeller  

4. **Communication Layer**  
   - SIM800L or Wi-Fi module for SMS and push notifications  

5. **AI Recognition Layer**  
   - YOLO model on Laptop/Cloud for animal detection and image classification  
