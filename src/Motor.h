#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class MotorPlanner;

class Motor
{
private:
  byte pin;
  float rate;
  int ml;
  static int count;

  unsigned long getWaterTime();
  void start();
  void stop();

public:
  int index;
  int irrigationFrecuency;
  MotorPlanner *planner;
  Motor(byte pin, float rate, int ml, int irrigationFrecuency); // Constructor
  void water();
  bool needsWater();
};

#endif