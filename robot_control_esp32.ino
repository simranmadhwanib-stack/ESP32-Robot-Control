/*
 * File Name   : robot_control_esp32.c
 * Board       : ESP32
 * Language    : C (Arduino framework)
 * Description : Robot movement control using switch-case
 *
 * Commands:
 *   F - Move Forward
 *   B - Move Backward
 *   L - Turn Left
 *   R - Turn Right
 *   S - Stop
 */

#include <Arduino.h>

/* Motor Driver Pins */
#define IN1 26   // Left motor forward
#define IN2 27   // Left motor backward
#define IN3 14   // Right motor forward
#define IN4 12   // Right motor backward

char command;

/* Function Declarations */
void moveForward(void);
void moveBackward(void);
void turnLeft(void);
void turnRight(void);
void stopRobot(void);

void setup() {
    Serial.begin(9600);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    stopRobot();
    Serial.println("ESP32 Robot Ready...");
}

void loop() {
    if (Serial.available() > 0) {
        command = Serial.read();
        command = toupper(command);

        switch (command) {
            case 'F':
                moveForward();
                break;

            case 'B':
                moveBackward();
                break;

            case 'L':
                turnLeft();
                break;

            case 'R':
                turnRight();
                break;

            case 'S':
                stopRobot();
                break;

            default:
                stopRobot();
                break;
        }
    }
}

/* Motor Control Functions */

void moveForward(void) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void moveBackward(void) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void turnLeft(void) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void turnRight(void) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void stopRobot(void) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}
