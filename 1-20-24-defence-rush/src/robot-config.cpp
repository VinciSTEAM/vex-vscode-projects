
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
#include "vex.hpp"

using namespace vex;

brain Brain;

controller control = controller(primary);
motor l1 = motor(PORT1, ratio6_1,true);
motor l2=motor(PORT2,ratio6_1, false);
motor l3=motor(PORT5,ratio6_1,true);
motor r1 = motor(PORT6,ratio6_1,false);
motor r2 = motor(PORT7,ratio6_1,true);
motor r3 = motor(PORT19, ratio6_1,false);
motor_group rights = motor_group(r1, r2, r3);
motor_group lefts = motor_group(l1,l2,l3);

motor wing = motor(PORT10,ratio18_1,false);
motor intake = motor(PORT9,ratio6_1,false);
motor catap = motor(PORT14, ratio36_1,true);

inertial tracker=inertial(PORT21);

void vexcodeInit(){

}