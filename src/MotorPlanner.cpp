#include "MotorPlanner.h"
#include "Motor.h"
#include <EEPROM.h>

MotorPlanner::MotorPlanner(Motor *motor)
{
    this->motor = motor;
    EEPROM.begin();
}

bool MotorPlanner::needsWater()
{
    Serial.print("Working on plant: ");
    Serial.print(motor->index);
    Serial.print("  Irrigation frecuency: ");
    Serial.print(motor->irrigationFrecuency);
    Serial.print("  Days without water: ");
    Serial.println(daysWithoutWater());

    increaseMotorCount();
    if (daysWithoutWater() >= motor->irrigationFrecuency)
    {
        resetMotorCount();
        return true;
    }
    return false;
}

int MotorPlanner::daysWithoutWater()
{
    return EEPROM.read(motor->index);
}

void MotorPlanner::increaseMotorCount()
{
    EEPROM.write(motor->index, daysWithoutWater() + 1);
}

void MotorPlanner::resetMotorCount()
{
    EEPROM.write(motor->index, 0);
}
