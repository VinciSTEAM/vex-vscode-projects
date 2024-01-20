#ifndef train_t_
#define train_t_

#include "vex.hpp"
#include "iostream"
#include "pid.hpp"

using namespace vex;
using namespace std;

class drivtrain
{
  protected:
    float error;
    float i;
    float d;
    float pe;
    float tpower;
    double thead;
    float truhead;
    PID com;
    // void drive(float);
    // void turn(float);

  public:

    float curhead;
    float predicthead;
    void drive(float);
    void pid(double);
    void tpid(float);
    void sethead();
    float tracking();
    void dri();
    friend class PID;
    friend class mitimer;
    mitimer time;
};
#endif