#include <Arduino.h>
#include <Servo.h>

Servo myServo;

void setup() {
    myServo.attach(9);
}

void loop() {

    // Move 0 → 180 smoothly
    for (int pos = 0; pos <= 180; pos++) {
        myServo.write(pos);
        delay(10);   // Controls speed
    }

    delay(100);

    // Move 180 → 0 smoothly
    for (int pos = 180; pos >= 0; pos--) {
        myServo.write(pos);
        delay(10);
    }

    delay(100);
}
