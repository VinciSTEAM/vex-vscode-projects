#include "vex.hpp"
#include "Drivtrain.hpp"
#include "autonomouse.hpp"
#include "pid.hpp"
#include "Driver_control.hpp"
// void drive(float dis){
//   dis=M_PI*4*
//   rights.spinFor()
// }
void consume(){
  intake.spin(fwd,100,pct);
}
void vomit(){
  intake.spin(reverse,100,pct);
}
void full(){
  intake.setStopping(hold);
  intake.stop();
}
void preauton(void){
  tracker.setHeading(0,degrees);
  tracker.resetHeading();
  tracker.startCalibration();
  tracker.calibrate();
  while(tracker.isCalibrating()==true){
    wait(15,msec);
  }
}
void auton()
{
  rights.setStopping(hold);
  intake.setStopping(hold);
  lefts.setStopping(hold);
  wing.setVelocity(100,pct);
  tracker.resetRotation();
  tracker.setHeading(0,degrees);
  wing.setPosition(0,deg);
  wing.spin(reverse,100,pct);
  drivtrain drivy;
  consume();
  wait(200,msec);
  drivy.predicthead=0;
  wing.stop(hold);
  drivy.tpid(21);
  drivy.drive(51);
  drivy.tpid(3);
  drivy.drive(-52);
  drivy.predicthead=24;
  drivy.tpid(72);
  vomit();
  wait(200,msec);
  drivy.tpid(45);
  drivy.drive(-26);
  drivy.tpid(33);
  drivy.drive(18);
  flip();
  wing.spin(fwd);
  drivy.tpid(-110);
  flip();
  drivy.tpid(56);
  drivy.drive(45);
  drivy.drive(-3);
}