#include "main.h"


/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void redLeftCorner(){
  intakes(300, -100);
  translate(1700, 60);
  setLow(127);
  setIntakes(100);
  translate(400, 60);
  pros::delay(400);
  setLow(0);
  setIntakes(0);
  rotate(35, 80);
  pros::delay(500);
  translate(8000, 60);
  rotate(50, 80);
  translate(1200, 50);
  allkrutilkas(200, -100);
  setAll(127);
  setIntakes(127);
  pros::delay(2100);
  setAll(0);
  setIntakes(0);
  translate(1700, -80);
  rotate(54, -80);
  intakes(300, -100);
  translate(8500, 70);
  setLow(127);
  setIntakes(127);
  translate(4600, 70);
  setLow(0);
  rotate(35, 80);
  translate(2600, 80);
  setAll(127);
  pros::delay(1100);
  setAll(0);
  setIntakes(0);
  translate(2300, -60);
  rotate(140, -80);
  translate(5060, -70);
  setDrive(30, 30);
  pros::delay(500);
  intakes(300, -100);
  translate(11500, 80);
  setIntakes(127);
  setLow(127);
  translate(400, 80);
  rotate(90, 80);
  translate(2000, 80);
  setLow(0);
  setAll(127);
  pros::delay(1500);
  setIntakes(0);
  setAll(0);
  //rotate(90, 60);
}

void redRightCorner(){

}

void blueLeftCorner(){

}

void blueRightCorner(){

}
void autonomous() {
  redLeftCorner();
  //redRightCorner();
  //blueRightCorner();
  //blueLeftCorner();
}

