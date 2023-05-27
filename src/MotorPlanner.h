#ifndef MOTORPLANNER_H
#define MOTORPLANNER_H


#include "Motor.h"


class MotorPlanner
{

private:
  Motor* motor;

public:
  MotorPlanner(Motor* motor);
  int daysWithoutWater();
  bool needsWater();
  void resetMotorCount();
  void increaseMotorCount();
};

#endif
