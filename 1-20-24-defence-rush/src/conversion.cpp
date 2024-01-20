#include "conversions.hpp"
#include "vex.hpp"

int sign(double x){
    return (x>0)-(x<0);
}
int sign(float x){
    return (x>0)-(x<0);
}
float degrad(double deg){
    return deg*M_PI/180;
}
float raddeg(double deg){
    return deg*M_PI/180;
}