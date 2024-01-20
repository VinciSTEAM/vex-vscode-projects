#include "manul-function.h"
#include "controller.h"
#include "robot-config.h"
#include "utils.h"
#include "vex.h"

using namespace vex;

bool enableCata = true;
bool enableHighHang = true;
bool enableWing = true;
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
  if (Controller1.ButtonR2.pressing()){
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

void controlWings() {
  if (Controller1.ButtonR1.pressing()){
    if (enableWing == true){
      enableWing = false;
      wings.set(true);
      wait(200, msec);
    }else{
      enableWing = true;
      wings.set(false);
      wait(200, msec);
    }
  }
    wait(10, msec);
}

/*void controlArm() {

  if (Controller1.ButtonR1.pressing() && !Controller1.ButtonR2.pressing()){
    arm.spin(forward, motorVoltage * 100, vex::voltageUnits::mV);
    arm.setStopping(hold);
    bType = hold;
  }else if (Controller1.ButtonR2.pressing() && !Controller1.ButtonR1.pressing()){
    arm.spin(forward, - motorVoltage * 100, vex::voltageUnits::mV);
    arm.setStopping(coast);
    bType = coast;
  }else{
    arm.stop(bType);
  }
}*/

void controlHang() {  
  if (Controller1.ButtonY.pressing()) {
    hang.set(true);
  }
}

void controlHighHang() {
  if (Controller1.ButtonX.pressing()){
    if (enableHighHang == true){
      enableHighHang = false;
      highhang.set(true);
      wait(200, msec);
    }else{
      enableHighHang = true;
      highhang.set(false);
      wait(200, msec);
    }
  }
    wait(10, msec);
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

