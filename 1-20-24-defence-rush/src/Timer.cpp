#include"vex.hpp"
#include "mitimer.hpp"

using namespace vex;

mitimer::mitimer(){
    timestart=Brain.Timer.value();
}
void mitimer::reset(){
    timestart=Brain.Timer.value();
}
int mitimer::getTime() const
{
    return floor((Brain.Timer.value()-timestart)*1000);
}