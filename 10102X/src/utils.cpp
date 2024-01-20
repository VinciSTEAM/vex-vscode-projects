#include "utils.h"
#include "robot-config.h"
#include "vex.h"

using namespace vex;

double IMUHeading() {
    double heading = Inertial.rotation(rotationUnits::deg);
    // IMUCoefficient need be tested
    heading = heading * IMUCoefficient; // 
    while (heading < 0) heading += 360;
    while (heading > 360) heading -= 360;
    return heading;
}

void setIMUHeading(double degree)
{
    Inertial.setRotation(degree, rotationUnits::deg);
}

void openWings(float percent){
  wings.spinToPosition(90, degrees);
  wings.setTimeout(500, msec);
}

void closeWings(){
  wings.spinToPosition(0, degrees);
  wings.setTimeout(500, msec);
}

void intakeTriball(float percent) {
  intake.spin(forward, motorVoltage * percent, vex::voltageUnits::mV);
}

void stopIntake(){
  intake.stop();
}


void drive(float lpercent, float rpercent) {
    RightMotor.spin(forward, motorVoltage * rpercent, vex::voltageUnits::mV);
    LeftMotor.spin(forward, motorVoltage * lpercent, vex::voltageUnits::mV);
 
}









