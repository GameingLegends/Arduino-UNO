#include <Arduino.h>

#define TRIG_PIN 7
#define ECHO_PIN 6

long duration;
int distance;

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    Serial.begin(9600);
}

int getDistance() {

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH, 30000);  // KEY FIX

    if (duration == 0) {
        return -1;   // No echo detected
    }

    distance = duration * 0.034 / 2;
    return distance;
}

void loop() {

    int dist = getDistance();

    if (dist == -1) {
        Serial.println("No object detected");
    } else {
        Serial.print("Distance: ");
        Serial.print(dist);
        Serial.println(" cm");
    }

    delay(500);
}
