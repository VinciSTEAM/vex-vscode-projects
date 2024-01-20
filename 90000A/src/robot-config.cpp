#include "robot-config.h"
#include "driveMode.h"
#include "vex.h"
using namespace vex;

competition Competition;
brain Brain;
motor leftFront = motor(PORT11, ratio6_1, true);
motor leftBack = motor(PORT7, ratio6_1, true);
motor leftMiddle = motor(PORT15, ratio6_1, true);
motor rightFront = motor(PORT9, ratio6_1, false);
motor rightBack = motor(PORT1, ratio6_1, false);
motor rightMiddle = motor(PORT2, ratio6_1, false);
motor catapult = motor(PORT8, ratio36_1, false);
//motor arm = motor(PORT11, ratio36_1, true);
motor intake = motor(PORT6, ratio18_1, false);
digital_out wings = digital_out(Brain.ThreeWirePort.G);
digital_out hang = digital_out(Brain.ThreeWirePort.H);
motor highhang = motor(PORT16, ratio18_1, true);
inertial Inertial = inertial(PORT5);
controller Controller1 = controller(primary);
motor_group LeftMotor = motor_group(leftFront, leftMiddle, leftBack);
motor_group RightMotor = motor_group(rightFront, rightMiddle, rightBack);

DriveMode driveMode = DriveMode::Arcade; // Arcade or Tank
int joystickDeadZone = 5;
