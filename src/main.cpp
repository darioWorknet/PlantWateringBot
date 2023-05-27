#include <Arduino.h>
#include "MotorManager.h"
#include "Motor.h"

/*
How to calculate the rate (s/ml) for a motor?
Turn on the motor for a time period, eg: 100 seconds.
Measure the ammount of water pumped by the motor in ml, eg: 211ml.
rate = 211 / 100 = 2.11
*/

// MOTOR 1
#define MOTOR_1_PIN                      12
#define MOTOR_1_RATE                   1.72
#define MOTOR_1_ML                      150
#define MOTOR_1_IRRIGATION_FRECUENCY      1

// MOTOR 2
#define MOTOR_2_PIN                      11
#define MOTOR_2_RATE                   1.47
#define MOTOR_2_ML                      150
#define MOTOR_2_IRRIGATION_FRECUENCY      1

// MOTOR 3
#define MOTOR_3_PIN                      10
#define MOTOR_3_RATE                   1.72
#define MOTOR_3_ML                      150
#define MOTOR_3_IRRIGATION_FRECUENCY      1

// MOTOR 4
#define MOTOR_4_PIN                       9
#define MOTOR_4_RATE                   1.72
#define MOTOR_4_ML                      150
#define MOTOR_4_IRRIGATION_FRECUENCY      1

// MOTOR 5
#define MOTOR_5_PIN                       8
#define MOTOR_5_RATE                   1.72
#define MOTOR_5_ML                      150
#define MOTOR_5_IRRIGATION_FRECUENCY      1

// MOTOR 6
#define MOTOR_6_PIN                       6
#define MOTOR_6_RATE                   1.57
#define MOTOR_6_ML                      150
#define MOTOR_6_IRRIGATION_FRECUENCY      1

// MOTOR 7
#define MOTOR_7_PIN                       7
#define MOTOR_7_RATE                   1.91
#define MOTOR_7_ML                      150
#define MOTOR_7_IRRIGATION_FRECUENCY      1

// Define motor manager
MotorManager motorManager = MotorManager();

// Instantiate all motors
Motor motor_1 = Motor(MOTOR_1_PIN, MOTOR_1_RATE, MOTOR_1_ML, MOTOR_1_IRRIGATION_FRECUENCY);
Motor motor_2 = Motor(MOTOR_2_PIN, MOTOR_2_RATE, MOTOR_2_ML, MOTOR_2_IRRIGATION_FRECUENCY);
Motor motor_3 = Motor(MOTOR_3_PIN, MOTOR_3_RATE, MOTOR_3_ML, MOTOR_3_IRRIGATION_FRECUENCY);
Motor motor_4 = Motor(MOTOR_4_PIN, MOTOR_4_RATE, MOTOR_4_ML, MOTOR_4_IRRIGATION_FRECUENCY);
Motor motor_5 = Motor(MOTOR_5_PIN, MOTOR_5_RATE, MOTOR_5_ML, MOTOR_5_IRRIGATION_FRECUENCY);
Motor motor_6 = Motor(MOTOR_6_PIN, MOTOR_6_RATE, MOTOR_6_ML, MOTOR_6_IRRIGATION_FRECUENCY);
Motor motor_7 = Motor(MOTOR_7_PIN, MOTOR_7_RATE, MOTOR_7_ML, MOTOR_7_IRRIGATION_FRECUENCY);

void setup()
{
  Serial.begin(9600);
  // Add motors to the manager
  motorManager.add(motor_1);
  motorManager.add(motor_2);
  motorManager.add(motor_3);
  motorManager.add(motor_4);
  motorManager.add(motor_5);
  motorManager.add(motor_6);
  motorManager.add(motor_7);
}

void loop()
{
  Serial.println("Watering all the plants");
  Serial.println();
  Serial.println("--------------");
  Serial.println();
  motorManager.waterAll();
  Serial.println("All plants watered successfully");
  delay(1000); // Just to give enough time to finish serial output
  exit(0);
}