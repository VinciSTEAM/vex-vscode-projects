/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       cheez                                                     */
/*    Created:      Sat Jul 01 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "PID.hpp"
#include <iostream>
#include <vector>
#include <Drivtrain.hpp>
#include "Driver_control.hpp"
#include "autonomouse.hpp"
#include "vex.hpp"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen

bool RemoteControlCodeEnable=true;

using namespace std;
using namespace vex;


//using namespace vex;
using namespace std;
int main() {
  competition compete;
  preauton();
  compete.autonomous(auton);
  wait(5,msec);
  compete.drivercontrol(driver);
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}
