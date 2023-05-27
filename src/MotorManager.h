#ifndef MOTORMANAGER_H
#define MOTORMANAGER_H

#include "Motor.h"

const int MAX_MOTORS = 10; // Maximum number of motors

class MotorManager
{

private:
  int count = 0;
  Motor *motors[MAX_MOTORS];

public:
  MotorManager();
  void add(Motor &motor);
  void waterAll();
};

#endif
