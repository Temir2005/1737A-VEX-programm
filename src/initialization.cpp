#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello, my name is Jamal!");

	backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	backRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	krutilkaHigh.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	krutilkaLow.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intakeLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intakeRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	pros::ADIGyro gyro('B', 1.00);
	pros::delay(2000);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
