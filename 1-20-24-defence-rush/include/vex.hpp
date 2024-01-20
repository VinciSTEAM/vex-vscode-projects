/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#ifndef OREX
#define OREX
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "v5.h"
#include "v5_vcs.h"


using namespace vex;

extern brain Brain;

extern controller control;

extern motor intake;
extern motor catap;
extern motor wing;

extern motor l1;
extern motor l2;
extern motor l3;
extern motor r1;
extern motor r2;
extern motor r3;
extern motor_group lefts;//left drive
extern motor_group rights;//right drive
extern inertial tracker;

void vexcodeInit(void);

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

#endif