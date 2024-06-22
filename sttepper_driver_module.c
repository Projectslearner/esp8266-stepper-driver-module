/*
    Project name : ESP8266 Stepper Driver Module
    Modified Date: 20-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp8266-stepper-driver-module
*/

#include <AccelStepper.h>

// Define stepper motor connections and steps per revolution
#define STEP_PIN D1 // GPIO pin connected to STEP pin of stepper driver
#define DIR_PIN D2  // GPIO pin connected to DIR pin of stepper driver
#define STEPS_PER_REVOLUTION 200 // Number of steps per revolution of your stepper motor

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  // Set maximum speed and acceleration
  stepper.setMaxSpeed(1000); // Adjust as needed, in steps per second
  stepper.setAcceleration(500); // Adjust as needed, in steps per second^2
}

void loop() {
  // Rotate stepper motor 360 degrees (1 revolution) clockwise
  stepper.moveTo(STEPS_PER_REVOLUTION);
  stepper.runToPosition();

  delay(1000); // Delay for 1 second
  
  // Rotate stepper motor 360 degrees (1 revolution) counterclockwise
  stepper.moveTo(-STEPS_PER_REVOLUTION);
  stepper.runToPosition();

  delay(1000); // Delay for 1 second
}
