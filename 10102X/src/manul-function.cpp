#include "manul-function.h"
#include "controller.h"
#include "robot-config.h"
#include "utils.h"
#include "vex.h"

using namespace vex;

bool enableCata = true;
bool enableFlyWheel = true;
bool enableArm = true;
vex::brakeType bType = coast;



void controlIntake() {
  if  (Controller1.ButtonL1.pressing()){
    intakeTriball(100);
  }else if (Controller1.ButtonL2.pressing()){
    intakeTriball(-100);
  }else{
    stopIntake();
  } 
}

void controlCatapult() {
  if (Controller1.ButtonA.pressing()){
    if (enableCata == true){
      enableCata = false;
      catapult.spin(fwd, motorVoltage * 100, voltageUnits::mV);
      wait(200, msec);
    }else{
      enableCata = true;
      catapult.stop();
      wait(200, msec);
    }
  }
    wait(10, msec);
}

void controlFlyWheel() {
    if (Controller1.ButtonA.pressing()){
    if (enableFlyWheel == true){
      enableFlyWheel = false;
      flywheel.spin(fwd, motorVoltage * 100, voltageUnits::mV);
      wait(200, msec);
    }else{
      enableFlyWheel = true;
      flywheel.stop();
      wait(200, msec);
    }
  }
    wait(10, msec);
}

/*
void controlWings() {
  Controller1.ButtonR1.pressed(openWings);
  Controller1.ButtonR1.released(closeWings);
}
*/
void controlArm() {

  if (Controller1.ButtonR1.pressing()){
    if (enableArm == true){
      enableArm = false;
      arm.spinToPosition(150, degrees);
      arm.setTimeout(300, msec);
      wait(200, msec);
    }else{
      enableArm = true;
      arm.spinToPosition(0, degrees);
      arm.setTimeout(300, msec);
      wait(200, msec);
    }
  }
    wait(10, msec);
}

void controlHang() {  
  if (Controller1.ButtonY.pressing()) {
    hang.set(true);
  }
}

void defineDriveMode() {

    int lstick, rstick;

    switch (driveMode) {

        case DriveMode::Arcade: {
            if (fabs(A3) <= joystickDeadZone) {
                lstick = 0;
            } else {
                lstick = A3;
            }
            if (fabs(A1) <= joystickDeadZone) {
                rstick = 0;
            } else {
                rstick = A1;
            }
            drive(lstick + rstick, lstick - rstick);
        }
        break;

        case DriveMode::Tank: {
            if (fabs(A3) <= joystickDeadZone) {
                lstick = 0;
            } else {
                lstick = A3;
            }
            if (fabs(A2) <= joystickDeadZone) {
                rstick = 0;
            } else {
                rstick = A2;
            }
            drive(lstick, rstick);
        }        
        break;
        default:
            Brain.Screen.print("This driveMode has not been defined yet");
        break;
    }
}

void setDriveMode(DriveMode dMode) {
    driveMode = dMode;
}

void setJoystickDeadZone(int deadzone) {
    joystickDeadZone = deadzone;
}

