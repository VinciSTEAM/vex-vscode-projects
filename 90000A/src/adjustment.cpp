#include "adjustment.h"

#include <iostream>
void testTurn() {

}

// int main() {
//     std::cout << __cplusplus;
//     auto constraints = squiggles::Constraints(2.0, 2.0, 1.0);
//     auto model = std::make_shared<squiggles::TankModel>(0.4, constraints);
//     auto spline = squiggles::SplineGenerator(constraints, model, 0.1);
//     auto path = spline.generate({squiggles::ControlVector(squiggles::Pose(0, 0, 0), 0.0, 0.0), 
//     squiggles::ControlVector(squiggles::Pose(0, 2, 0), 0.0, 0.0)});
//     std::vector<squiggles::ProfilePoint>::iterator ptr;
//     for ( ptr = path.begin(); ptr < path.end(); ptr ++) 
//     {
//       std::cout << ptr -> to_string();
//     }
// }