#include "main.h"

void setLow(int power){
  krutilkaLow = power;
}
void intakesLow(int power){
  intakeLeft = power;
  intakeRight = power;
}
void setLowMotors(){
    int power = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
    setLow(power);
    intakesLow(power);
}

void lowkrutilkas(int degrees, int voltage){
  int direction = abs(degrees) / degrees;
  krutilkaLow.tare_position();
  while(abs(krutilkaLow.get_position()) < abs(degrees)){
    setLow(voltage * direction);
    pros::delay(10);
  }
  setLow(0);
}
