#ifndef PATHPLANNER_H_
#define PATHPLANNER_H_
#include <iostream>
#include <vector>
#include "geometry.h"
class PathPlanner{

private:
    

public:
    std::vector<std::vector<double>> heading;
    std::vector<Point> inject(std::vector<Point>, int);
    std::vector<Point> smoother(std::vector<Point>, double, double, double);
    std::vector<Point> nodeOnlyWayPoints(std::vector<Point>);

};

#endif