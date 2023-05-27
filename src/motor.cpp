#include "Motor.h"
#include "MotorPlanner.h"

int Motor::count = 0;

Motor::Motor(byte pin, float rate, int ml, int irrigationFrecuency)
{
  pinMode(pin, OUTPUT);
  this->pin = pin;
  this->rate = rate;
  this->ml = ml;
  this->irrigationFrecuency = irrigationFrecuency;
  this->index = count;
  count++;
  this->planner = new MotorPlanner(this);
}

unsigned long Motor::getWaterTime()
{
  return (ml / rate) * 1000;
}

void Motor::start()
{
  digitalWrite(pin, HIGH);
}

void Motor::stop()
{
  digitalWrite(pin, LOW);
  delay(500);
}

void Motor::water()
{
  Serial.print("Watering plant for ");
  Serial.print(getWaterTime());
  Serial.println(" milliseconds");
  Serial.print("Pin: ");
  Serial.print(pin);
  Serial.print("  Rate: ");
  Serial.print(rate);
  Serial.print("  Ml: ");
  Serial.println(ml);

  start();
  delay(getWaterTime());
  Serial.println("Plant watered");
  stop();
}

bool Motor::needsWater()
{
  return planner->needsWater();
}
