#include "vex.hpp"
#include"Driver_control.hpp"


int catvel=0;
bool wingout=false;

void spintake()
{
    intake.setVelocity(100,percent);
    intake.setStopping(coast);
    if(control.ButtonL1.pressing()){
        intake.spin(fwd);
    }
    if(control.ButtonL2.pressing()){
        intake.spin(reverse);
    }
    if(control.ButtonL1.pressing()==control.ButtonL2.pressing()){
        intake.stop();
    }
}
void cata(){
    catvel=100-catvel;
    catap.spin(fwd,catvel,pct);
}
void flip(){
    wing.setTimeout(350,msec);
    if(control.ButtonR1.pressing()){
        wing.spinToPosition(180,deg);
    }
    else if(control.ButtonR2.pressing()){
        wing.spinToPosition(0,deg);
    }
    wait(300,msec);
    wing.stop(hold);
    wait(15,msec);
}
void drivetime()
{
  drivtrain dris;
  dris.dri();
}
void driver()
{
    mitimer thyme;
    thyme.reset();
    drivtrain drivy;
    rights.setStopping(coast);
    lefts.setStopping(coast);
    catap.setVelocity(100,percent);
    wing.setVelocity(100,percent);
    catap.setStopping(coast);
    control.ButtonA.pressed(cata);
    thread drive(drivetime);
    catap.stop();
    while(1){
        flip();
        spintake();
        task::sleep(15);
    }
}