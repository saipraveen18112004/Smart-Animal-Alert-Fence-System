// Arduino code for Smart Animal-Alert Fence System
// Add your sensor and control logic here.
// -----------------------------------------------------
// SmartFence++ - ESP32 Animal Alert Fence System
// -----------------------------------------------------

#include <WiFi.h>
#include <HTTPClient.h>
#include <HardwareSerial.h>

#define PIR_PIN  23
#define IR_PIN   22
#define LDR_PIN  21
#define BUZZER_PIN  19
#define LED_PIN  18
#define RELAY_PIN 17  // For water pump
#define TRIG_PIN 5
#define ECHO_PIN 4

// SIM800L connected to ESP32 Serial2
HardwareSerial sim800(2);

// Distance detection
long readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2; // cm
}

void sendSMS(String msg) {
  sim800.println("AT+CMGF=1");
  delay(500);
  sim800.println("AT+CMGS=\"+91XXXXXXXXXX\""); // Farmer's number
  delay(500);
  sim800.print(msg);
  delay(500);
  sim800.write(26); // Ctrl+Z
  delay(5000);
}

void setup() {
  Serial.begin(115200);
  sim800.begin(9600, SERIAL_8N1, 16, 17); // RX2, TX2
  pinMode(PIR_PIN, INPUT);
  pinMode(IR_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  Serial.println("SmartFence++ system initialized.");
}

void loop() {
  int motion = digitalRead(PIR_PIN);
  int ir = digitalRead(IR_PIN);
  int light = digitalRead(LDR_PIN);
  long distance = readDistance();

  if (motion == HIGH || ir == LOW || distance < 100) {
    Serial.println("⚠️ Animal Detected!");
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(RELAY_PIN, HIGH);
    sendSMS("Alert! Animal detected in your farm. Deterrents activated.");
    delay(10000);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(RELAY_PIN, LOW);
  }
  delay(500);
}
