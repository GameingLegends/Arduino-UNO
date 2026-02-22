#include <Arduino.h>

#define TRIG_PIN 7
#define ECHO_PIN 6

long duration;
int distance;

int getDistanceRaw() {

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH, 30000);

    if (duration == 0) return -1;

    distance = duration * 0.034 / 2;
    return distance;
}

int getDistanceStable() {

    int total = 0;
    int validReads = 0;

    for (int i = 0; i < 5; i++) {

        int d = getDistanceRaw();

        if (d != -1) {
            total += d;
            validReads++;
        }

        delay(10);   // Sensor settling
    }

    if (validReads == 0) return -1;

    return total / validReads;
}

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    Serial.begin(9600);
}

void loop() {

    int dist = getDistanceStable();

    if (dist == -1) {
        Serial.println("No object detected");
    } else {
        Serial.print("Distance: ");
        Serial.print(dist);
        Serial.println(" cm");
    }

    delay(60);   // Correct sensor cycle timing
}
