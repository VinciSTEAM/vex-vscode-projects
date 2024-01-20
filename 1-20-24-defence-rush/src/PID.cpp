#include "vex.hpp"
#include "pid.hpp"
double speed;
using namespace std;
PID::PID() : first(true), finished(false), intmax(20), irange(50), exittime(50){
    tymer.reset();
}
void PID::firstset(){
    this->first = true;
}
// void PID::target(float starget){goal=starget;}
void PID::setbuffer(float max, float min){
    maxi=max;mini=min;
}
void PID::setterror(float terror){this->terror=terror;}
void PID::setkonstants(float kp, float ki, float kd)
{
    this->kp=kp;
    this->ki=ki;
    this->kd=kd;
}
void PID::setexittime(float exit){exittime=exit;}
void PID::target(float target){goal=target;}
void PID::intrange(float range){irange=range;}
bool PID::arrived(){return finished;}
void PID::setTold(float told){Told=told;}
void PID::setdone(bool done){finished=done;}
void PID::Intmax(float imax){intmax=imax;}
double PID::retrieveout(){return output;}

void PID::update(float input){
    tymer.reset();
    //bool stagechange=false;
    output=0;
    errorcur=goal-input;
    P=errorcur*kp;
    if(first){
        first=false;
        preverror=errorcur;
        interror=0;
    }
    if(fabs(P)>=irange){
        interror=0;
    }
    else{
        interror+=errorcur;
        if(fabs(interror)> intmax){
            interror=signbit(interror)*intmax;
        }
    }
    if(signbit(interror)!=signbit(errorcur)||fabs(errorcur)<=terror){//overshoot or within tolerated error range
        interror=0;
    }
    I=interror*ki;
    derror=errorcur-preverror;
    preverror=errorcur;
    D=derror*kd;
    if(fabs(errorcur)<=terror&&D<=Told){//in the tolerated error range while being at a low enough velocity
        if(tymer.getTime()>=exittime){
            finished=true;
        }
    }
    else{
        tymer.reset();
        finished=false;
    }
    output=P+I+D;
        // if(stagechange==false&& output<70)
        // {
        //     stage1(output);
        // }
        // else if(stagechange==false&&output>70){
        //     stagechange=true;
        // }
        // else if(stagechange==true&&output<60){

        // }
}