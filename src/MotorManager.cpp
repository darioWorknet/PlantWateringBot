#include "MotorManager.h"

MotorManager::MotorManager() {}

void MotorManager::add(Motor &motor)
{
  motors[count] = &motor;
  count++;
  Serial.print("Motor ");
  Serial.print(count);
  Serial.println(" added");
}

void MotorManager::waterAll()
{
  for (int i = 0; i < count; i++)
  {
    Serial.print("Checking plant: ");
    Serial.println(i);
    if (motors[i]->needsWater())
    {
      Serial.println("WATERING PLANT");
      motors[i]->water();
    }
    Serial.println();
    Serial.println("---------------------------------");
    Serial.println();
  }
}
