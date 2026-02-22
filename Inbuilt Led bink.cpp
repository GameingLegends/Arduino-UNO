#include <Arduino.h>

void setup() {
  // Initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);   // Turn the LED on
  delay(500);               // Wait for 500ms
  digitalWrite(13, LOW);    // Turn the LED off
  delay(500);               // Wait for 500ms
}
