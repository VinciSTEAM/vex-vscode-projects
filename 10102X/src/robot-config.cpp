#include "robot-config.h"
#include "driveMode.h"
#include "vex.h"
using namespace vex;

competition Competition;
brain Brain;
motor leftFront = motor(PORT7, ratio6_1, true);
motor leftBack = motor(PORT9, ratio6_1, true);
motor leftMiddle = motor(PORT8, ratio6_1, false);
motor rightFront = motor(PORT13, ratio6_1, false);
motor rightBack = motor(PORT15, ratio6_1, false);
motor rightMiddle = motor(PORT14, ratio6_1, true);
motor flywheel = motor(PORT1, ratio6_1, false);
motor catapult = motor(PORT20, ratio36_1, false);
motor arm = motor(PORT10, ratio18_1, false); 
motor intake = motor(PORT11, ratio18_1, true);
motor wings = motor(PORT21, ratio6_1, false);

digital_out hang = digital_out(Brain.ThreeWirePort.H);
inertial Inertial = inertial(PORT2);
controller Controller1 = controller(primary);
motor_group LeftMotor = motor_group(leftFront, leftMiddle, leftBack);
motor_group RightMotor = motor_group(rightFront, rightMiddle, rightBack);

DriveMode driveMode = DriveMode::Tank; // Arcade or Tank 
int joystickDeadZone = 5;
