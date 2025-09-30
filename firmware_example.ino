/*
Smart Helmet - example skeleton (firmware_example.ino)
This is a minimal template. Calibrate thresholds and expand modules.
*/
#include <SoftwareSerial.h>

#define MQ3_PIN A0
#define FSR_PIN A1
#define VIB_PIN 2
#define BUZZER_PIN 3
#define LED_GREEN 4
#define LED_ORANGE 5
#define LED_RED 6

SoftwareSerial gpsSerial(10, 11); // RX, TX
SoftwareSerial gsmSerial(8, 9);

const int ALCOHOL_THRESHOLD_BLOCK = 400; // calibrate
const int ALCOHOL_THRESHOLD_WARN = 200; // calibrate
const int FSR_ACCIDENT_THRESHOLD = 700; // calibrate (0-1023)

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  gsmSerial.begin(9600);

  pinMode(VIB_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  Serial.println("Smart Helmet: Booting...");
}

void loop() {
  int alcohol = analogRead(MQ3_PIN);
  int fsr = analogRead(FSR_PIN);
  int vib = digitalRead(VIB_PIN);

  // Alcohol logic
  if (alcohol >= ALCOHOL_THRESHOLD_BLOCK) {
    // Block start
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_ORANGE, LOW);
    digitalWrite(LED_GREEN, LOW);
    tone(BUZZER_PIN, 2000);
    Serial.println("ALCOHOL LEVEL: BLOCK - Do not start");
  } else if (alcohol >= ALCOHOL_THRESHOLD_WARN) {
    digitalWrite(LED_ORANGE, HIGH);
    digitalWrite(LED_GREEN, LOW);
    noTone(BUZZER_PIN);
    Serial.println("ALCOHOL LEVEL: WARNING");
  } else {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_ORANGE, LOW);
    noTone(BUZZER_PIN);
    Serial.println("ALCOHOL LEVEL: OKAY");
  }

  // Accident detection
  if (fsr >= FSR_ACCIDENT_THRESHOLD || vib == HIGH) {
    Serial.println("ACCIDENT DETECTED - Triggering emergency flow");
    // Obtain GPS + send SMS via GSM - implement in final firmware
  }

  delay(1000);
}
