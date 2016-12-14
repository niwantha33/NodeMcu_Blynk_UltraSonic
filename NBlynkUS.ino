// Free to Use
// Algobel TI

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "........."; // Wifi SSID
char pass[] = "........"; // Password (WIFI)
char auth[] =  "............" // Blynk Key 

#define TRIGGER_PIN  14 // D5 _NodeMcu Pin
#define ECHO_PIN     12 //D6  _NodeMcu Pin


BLYNK_READ(V1) {
  double duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);  // Get Start
  delayMicroseconds(2); // stable the line
  digitalWrite(TRIGGER_PIN, HIGH); // sending 10 us pulse
  delayMicroseconds(10); // delay
  digitalWrite(TRIGGER_PIN, LOW); // after sending pulse wating to receive signals
  duration = pulseIn(ECHO_PIN, HIGH); // calculating time
  distance = (duration / 2) / 29.1; // single path
  Serial.print(distance);  
  delay(100);
  Blynk.virtualWrite(V1, distance);
}

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Blynk.begin(auth, ssid, pass); //
}

void loop() {
  Blynk.run(); // Keep looping
}
