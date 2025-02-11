#define BLYNK_TEMPLATE_ID "TMPL6cNdB5I9k"
#define BLYNK_TEMPLATE_NAME "DoorLock"

#include <ESP8266WiFi.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>
#include <BlynkSimpleEsp8266.h>

// Replace with your Wi-Fi credentials
const char* ssid = "Galaxy";
const char* password = "11111111";

// Telegram Bot details
const String BOT_TOKEN = "7759159838:AAG3pDHH5aNzR7lkbdUt-OshpG3_sCnXfXg";
const String CHAT_ID = "6040428455";

// Blynk credentials
char auth[] = "ouhjmhT-1zpLvaZlkWHA7zMKuxPC9C85";

// Sensor pins
const int PIR_PIN = D5;  // Motion sensor pin
const int IR_PIN = D6;   // Door status sensor pin
const int RELAY_PIN = D2; // Relay control pin

// Telegram and Wi-Fi setup
WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

// State variables
bool doorOpen = false;
unsigned long lastMotionTime = 0;

void setup() {
  Serial.begin(9600);

  // Initialize pins
  pinMode(PIR_PIN, INPUT);
  pinMode(IR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  // Ensure relay is off initially

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  client.setInsecure();  // Bypass SSL certificate

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  // Blynk setup
  Blynk.begin(auth, ssid, password);

  // Confirmation message
  bot.sendMessage(CHAT_ID, "ESP8266 Bot is online!", "");
}

void loop() {
  Blynk.run();

  // Motion Detection (PIR Sensor)
  if (digitalRead(PIR_PIN) == HIGH) {
    if (millis() - lastMotionTime > 5000) {  // Avoid message spam
      Serial.println("Motion detected");
      bot.sendMessage(CHAT_ID, "Motion detected", "");
      lastMotionTime = millis();
    }
  }

  // Door Status Detection (IR Sensor)
  int irState = digitalRead(IR_PIN);

  if (irState == HIGH && !doorOpen) {
    Serial.println("Door opened");
    bot.sendMessage(CHAT_ID, "Door opened", "");
    doorOpen = true;
  } else if (irState == LOW && doorOpen) {
    Serial.println("Door closed");
    bot.sendMessage(CHAT_ID, "Door closed", "");
    doorOpen = false;
  }

  delay(100); // Sensor debounce delay
}

// Blynk Virtual Pin V0 handler to control the relay
BLYNK_WRITE(V0) {
  int pinValue = param.asInt();  // Get the value sent from the Blynk app
  digitalWrite(RELAY_PIN, pinValue);
  Serial.print("Relay state: ");
  Serial.println(pinValue ? "ON" : "OFF");
}
