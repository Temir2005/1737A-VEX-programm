#include "main.h"
using namespace pros;

void setLow(int power){
  krutilkaLow = power;
  intakeLeft = power;
  intakeRight = power;
}

void setAllMotors(){
    int power = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
    setAll(power);
}
