#include "main.h"

pros::ADIGyro gyro('B', 1.00);

void setDrive(int left, int right){
  backLeft = left;
  backRight = right;
  frontRight = right;
  frontLeft = left;
}

void setDriveMotors(){
  int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  if(abs(leftJoystick) < 10){
    leftJoystick = 0;
  }
  if(abs(rightJoystick) < 10){
    rightJoystick = 0;
  }
  setDrive(leftJoystick, rightJoystick);
}

void setSideways(int power){
  backLeft = -power;
  backRight = power;
  frontRight = -power;
  frontLeft = power;
}

void setSidewaysMotors(){
  int power = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y));
  setSideways(power);
}

void resetDriveEncoders(){
  backLeft.tare_position();
  backRight.tare_position();
  frontLeft.tare_position();
  frontRight.tare_position();
}

double average(){
  return fabs(backLeft.get_position()) +
         fabs(backRight.get_position()) +
         fabs(frontLeft.get_position()) +
         fabs(frontRight.get_position()) / 4;
}

void translate(int units, int voltage){
  int direction = abs(units) / units;
  //reset motor encoders
  resetDriveEncoders();
  gyro.reset();
  //drive forward until units are reached
  while(average() < abs(units)){
    setDrive(voltage  * direction + gyro.get_value(), voltage * direction - gyro.get_value());
    pros::delay(10);
  }
  //brief brake
  setDrive(-10 * direction + gyro.get_value(), -10 * direction - gyro.get_value());
  pros::delay(50);
  //set drive back to neutral
  setDrive(0, 0);
}

void rotate(int degrees, int voltage){
  //define our direction
  int direction = abs(degrees) / degrees;
  //resetting gyro
  gyro.reset();
  //turn until units are reached
  setDrive(-voltage * direction, voltage * direction);
  while(fabs(gyro.get_value()) < abs(degrees * 10) - 30) {
    pros::delay(10);
  }
  pros::delay(100);
  if(fabs(gyro.get_value()) > abs(degrees * 10)){
    setDrive(0.5 * voltage * direction,0.5 * -voltage * direction);
    while(fabs(gyro.get_value()) > abs(degrees * 10)) {
      pros::delay(10);
    }
  }
  else if(fabs(gyro.get_value()) < abs(degrees * 10)){
    setDrive(0.5 * -voltage * direction,0.5 * voltage * direction);
    while(fabs(gyro.get_value()) < abs(degrees * 10)) {
      pros::delay(10);
    }
  }
  //reset to zero
  setDrive(0, 0);
}
