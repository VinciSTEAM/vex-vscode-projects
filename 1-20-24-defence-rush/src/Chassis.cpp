#include "Drivtrain.hpp"
#include "pid.hpp"
#include "vex.hpp"
using namespace std;
using namespace vex;
void drivtrain::dri()
{
    rights.setStopping(coast);
    lefts.setStopping(coast);
    float a1;
    float a2;
    bool arcadeswitch = true;
    while (true)
    {
        a1=control.Axis3.value()*0.127;
        a2=control.Axis1.value()*0.127;
        if(control.ButtonRight.pressing()&&control.ButtonDown.pressing()&&control.ButtonLeft.pressing()){
          arcadeswitch=!arcadeswitch;
        }
        if(arcadeswitch==false){
          rights.spin(fwd,control.Axis2.position()*0.5,volt);
          lefts.spin(fwd,control.Axis3.position()*0.5,volt);
        }
        else if(arcadeswitch==true){
          rights.spin(fwd,a1-a2,volt);
          lefts.spin(fwd,a1+a2,volt);
        }

    }
}
float drivtrain::tracking(){
  curhead=tracker.heading();
  return curhead;
}
void drivtrain::tpid(float degree)
{
      time.reset();
      thead=degree+predicthead;
      if(thead>=360){
        thead-=360;
      }
      if(thead<0){
        thead-+360;
      }
      predicthead=thead;
      // if((curhead<thead-180)&&(180<=thead<360)){//target heading is in the 2nd quadrant
      //   if(thead>180){
      //     thead-=360;
      //   }
      //   zte=true;
      // }
      // if((curhead>thead+180)&&(0<=thead<180)){
      //   if(thead>180){
      //     thead-=360;
      //   }
      //   zte=true;
      // }
      std::cout<<thead<<endl;
      int loop=0;
      std::cout<<"turning"<<endl;
      com.firstset();
      com.setkonstants(0.0713,0.006,0.0346);
      if(degree<150) com.setkonstants(0.0994,0.006,0.0346);
      else if(degree<50) com.setkonstants(0.12,0.006,0.0346);
      else if(degree<30) com.setkonstants(0.18,0.006,0.0346);
      com.setexittime(200);
      if(degree>175){
        com.setexittime(700);
      }
      com.setterror(0.2);
      com.setTold(0.1);
      com.Intmax(60);
      com.setdone(false);
      com.intrange(30);
      do
      {
        double truhead=tracking();
        error=thead-truhead;
        if(error>=180){
          thead-=360;
          truhead-=360;
        }
        if(error<-180){
          thead+=360;
          truhead+=360;
        }
        cout<<thead<<" "<<error<<endl;
        com.target(thead);
        com.update(truhead);  
        error=thead-truhead;
        tpower=com.retrieveout();
        if(tpower>12.7){
          tpower=12.7;
        }
        lefts.spin(fwd,tpower,volt);
        rights.spin(reverse, tpower,volt);

        // tpower=(tpower/100)*13;
        wait(15,msec);
      }while(!com.arrived()&&time.getTime()<=700);
      cout<<error<<endl;
      predicthead=thead;
      tracker.setHeading(curhead, deg);
      lefts.setStopping(hold);
      rights.setStopping(hold);
      lefts.stop();
      rights.stop();
}
void drivtrain::sethead(){
  truhead=tracker.heading();
}
void drivtrain::drive(float d=0)
{
      time.reset();
      float ldis;
      float rdis;
      com.firstset();
      com.setkonstants(0.4,0,0.04);
      if(d<15){
        com.setkonstants(0.6,0,0.8);
      }
      com.setexittime(280);
      if(d>47){
        com.setkonstants(0.26,0,0.02);
        com.setexittime(800);
      }
      if(d>70){
        com.setkonstants(0.18,0,0);
        com.setexittime(1500);
      }
      com.setterror(2);
      com.setTold(0.7);
      com.Intmax(2000);
      com.intrange(5);
      com.setdone(false);
      com.target(d);
      lefts.setPosition(0, deg);
      rights.setPosition(0, deg);
      lefts.setStopping(hold);
      rights.setStopping(hold);
      float jumpcount;
      double rpower=100;
      double lpower = 100;
      cout<<endl;
      do
      {
        ldis=((lefts.position(deg)/360)*48/84*(4*M_PI));
        rdis=((rights.position(deg)/360)*48/84*(4*M_PI));
        com.target(d);
        com.update(ldis);
        lpower=com.retrieveout();
        com.update(rdis);
        rpower=com.retrieveout();
        cout<<lpower<<" power "<<endl;
        if(fabs(rpower)<1) rpower=0;
        lefts.spin(fwd, lpower,volt);
        rights.spin(fwd,rpower,volt);
        wait(15,msec);
      }while(!com.arrived()&&time.getTime()<=1500);
      lefts.stop();
      rights.stop();
      wait(100,msec);
}