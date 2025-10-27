# YOLO-based animal detection script
# Add your AI model integration here.
# -----------------------------------------------------
# SmartFence++ - YOLO Animal Detection Script
# -----------------------------------------------------

import cv2
from ultralytics import YOLO
import requests

# Load YOLO model
model = YOLO("yolov8n.pt")  # Pretrained YOLOv8 model

# ESP32 endpoint or local display (optional)
ESP32_IP = "http://192.168.4.1/alert"

# Start video feed (webcam or ESP32-CAM)
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    # YOLO prediction
    results = model.predict(frame, conf=0.5)
    detections = results[0].boxes.data.cpu().numpy()

    for det in detections:
        x1, y1, x2, y2, conf, cls = det
        class_name = model.names[int(cls)]

        if class_name.lower() in ["cow", "dog", "goat", "cat", "animal"]:
            print("⚠️ Animal Detected:", class_name)
            cv2.rectangle(frame, (int(x1), int(y1)), (int(x2), int(y2)), (0, 0, 255), 2)
            cv2.putText(frame, class_name, (int(x1), int(y1) - 10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)

            # Optionally trigger ESP32 via HTTP
            try:
                requests.get(f"{ESP32_IP}?alert=1")
            except:
                pass

    cv2.imshow("SmartFence++ Detection", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
