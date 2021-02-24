#include "main.h"
using namespace pros;

void setAll(int power){
  krutilkaHigh = power;
  krutilkaLow = power;
  intakeLeft = power;
  intakeRight = power;
}

void setAllMotors(){
    int power = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
    setAll(power);
}
