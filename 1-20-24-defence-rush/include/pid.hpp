#ifndef PIND
#define PIND
#include "vex.hpp"
#include "mitimer.hpp"


class PID
{
    protected:
        float P,I,D;
        float errorcur, preverror, derror/*derivative error*/, interror;//integral error
        float terror;//tolerated error
        bool first, finished;
        float ki, kd, kp;
        float goal;
        float intmax, irange, Told;//tolerated derivative;
        double output;
        float exittime;
        float maxi, mini;

    public:
        PID();
        double retrieveout();
        void firstset();
        virtual void target(float);
        void setterror(float);
        void Intmax(float);
        void intrange(float);
        void setbuffer(float, float);//sets what error range is accepted
        void setexittime(float);//sets how much time before exitting
        void setkonstants(float,float,float);
        void setTold(float);
        void setdone(bool);
        virtual void update(float input);
        bool arrived();
        mitimer tymer;
};
#endif