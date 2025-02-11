# ESP32-CAM Door Lock System with Face Recognition

## Project Overview
This project demonstrates a smart door lock system using the ESP32-CAM module for face detection, enrollment, and recognition. The system controls a door lock via an ESP8266 board and integrates with the Blynk and Telegram apps for enhanced functionality.

---
## Features
- **Face Enrollment:** Capture and store human faces for recognition.
- **Face Detection and Recognition:** Recognize enrolled faces to unlock the door.
- **Secure Door Control:** The ESP8266 board manages door lock operations.
- **IoT Integration:**
  - **Blynk App:** Control and monitor the door lock remotely.
  - **Telegram App:** Receive real-time notifications and interact with the system.

---
## Components Used
- **ESP32-CAM Module (AI Thinker)** for face detection and recognition
- **ESP8266 Board** for door lock control and IoT communication
- **Relay Module** for door lock control
- **Door Lock Mechanism**
- **Power Supply** (5V DC for ESP32-CAM and ESP8266)
- **MicroSD Card** for storing face datasets

---
## Circuit Diagram
Connect the components as follows:
- **ESP32-CAM:** Connect the relay module to GPIO pins for door control.
- **ESP8266:** Communicate with the ESP32-CAM and control the door lock.
- **Relay Module:** Control the door lock mechanism.

---
## Software Setup
### Prerequisites
- Arduino IDE installed
- ESP32 and ESP8266 Board Managers installed in Arduino IDE

### Libraries Required
- `WiFi.h` (for ESP32)
- `ESPAsyncWebServer.h` (for web server operations)
- `BlynkSimpleEsp8266.h` (for Blynk integration)
- `UniversalTelegramBot.h` (for Telegram communication)
- `ArduinoJson.h` (for handling JSON data)

### Uploading the Code
1. Open the Arduino IDE.
2. Connect the ESP32-CAM and ESP8266 boards to your computer via USB.
3. Select the correct board and port for each.
4. Upload the respective code for the ESP32-CAM and ESP8266.

---
## Usage Instructions
1. Power on the system.
2. **Face Enrollment:**
   - Open the ESP32-CAM web interface.
   - Click the **Enroll** button and capture face samples.
3. **Door Control:**
   - Recognized faces will unlock the door automatically.
   - Control the door lock manually via the Blynk app.
4. **Notifications:**
   - Receive alerts on the Telegram app for door lock events.

---
## Troubleshooting
- **Face Recognition Fails:** Ensure proper lighting and face alignment during enrollment.
- **Door Lock Not Responding:** Verify connections between the ESP8266 and relay module.
- **Blynk or Telegram Not Working:** Check Wi-Fi credentials and internet connection.

---
## Future Improvements
- Implement multi-factor authentication.
- Add voice command integration.
- Improve face recognition accuracy.

---
## License
This project is open-source and available under the MIT License.

---
## Contact
If you have any questions or suggestions, feel free to contact [Your Name or GitHub Username] at [Your Contact Email].

