#include "main.h"


void setAll(int power1){
  krutilkaHigh = power1;
  krutilkaLow = power1;
}
void setIntakes(int power){
  intakeLeft = power;
  intakeRight = power;
}
void setAllMotors(){
    int power = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
    setAll(power);
    setIntakes(power);
}

void allkrutilkas(int degrees, int voltage){
  int direction = abs(degrees) / degrees;
  krutilkaHigh.tare_position();
  while(abs(krutilkaHigh.get_position()) < abs(degrees)){
    setAll(voltage * direction);
    pros::delay(10);
  }
  setAll(0);
}
void intakes(int degrees, int voltage){
  int direction = abs(degrees) / degrees;
  intakeLeft.tare_position();
  while(abs(intakeLeft.get_position()) < abs(degrees)){
    setIntakes(voltage * direction);
    pros::delay(10);
  }
  setIntakes(0);
}
