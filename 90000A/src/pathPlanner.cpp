#include <iostream>
#include <vector>
#include <cmath>
#include "pathPlanner.h"
#include "geometry.h"
#include "calc.h"


// linear injection
std::vector<Point> PathPlanner::inject(std::vector<Point> original_path, int numToInject)
{
    std::vector<Point> updated_path(original_path.size() + numToInject * (original_path.size() - 1));
    int index = 0;
    for (int i = 0; i < original_path.size(); i ++)
    {
        updated_path[index] = original_path[i];
        index ++;
        for (int j = 1; j < numToInject + 1; j ++)
        {   
            double x_cordinate = j * (original_path[i + 1]._x - original_path[i]._x)/(numToInject + 1) + original_path[i]._x;
            double y_cordinate = j * (original_path[i + 1]._y - original_path[i]._y)/(numToInject + 1) + original_path[i]._y;
            updated_path[index] = Point(x_cordinate, y_cordinate);
            index ++;
        }   
    }
    updated_path[index] = original_path.back();
    return updated_path;
}

	/**
	 * Optimization algorithm, which optimizes the data points in path to create a smooth trajectory.
	 * This optimization uses gradient descent. While unlikely, it is possible for this algorithm to never
	 * converge. If this happens, try increasing the tolerance level.
	 * 
	 * BigO: N^x, where X is the number of of times the while loop iterates before tolerance is met. 
	 * 
	 * @param path
	 * @param weight_data
	 * @param weight_smooth
	 * @param tolerance
	 * @return
	 */
    
    std::vector<Point> smoother(std::vector<Point> path, double weight_data, double weight_smooth, double tolerance)
    {
        std::vector<Point> updated_path;
        updated_path.assign(path.begin(), path.end());
        double change = tolerance;
        while (change > tolerance)
        {
            change = 0.0;
            for (int i = 1; i < path.size() - 1; i ++) 
            {
                double aux_x = updated_path[i]._x;
                updated_path[i]._x += weight_data * (path[i]._x - updated_path[i]._x) + weight_smooth * (updated_path[i - 1]._x + updated_path[i + 1]._x - 2.0 * updated_path[i]._x);
                change += fabs(aux_x - updated_path[i]._x);
                double aux_y = updated_path[i]._y;
                updated_path[i]._y += weight_data * (path[i]._y - updated_path[i]._y) + weight_smooth * (updated_path[i - 1]._y + updated_path[i + 1]._y - 2.0 * updated_path[i]._y);
                change += fabs(aux_y - updated_path[i]._y);
            }
        }
        return updated_path;
    }

    std::vector<Point> nodeOnlyWayPoints(std::vector<Point> path)
    {
        std::vector<Point> updated_path;
        updated_path.push_back(path.front());
        for (int i = 1; i < path.size() - 1; i ++)
        {
            double direction1 = atan2(path[i]._y - path[i-1]._y, path[i]._x - path[i-1]._x);
            double direction2 = atan2(path[i+1]._y - path[i]._y, path[i+1]._x - path[i]._x);
            if (fabs(direction1 - direction2) >= 0.01)
            {
                updated_path.push_back(path[i]);
            }
        }
        return updated_path;
    }

/**
	 * Returns Velocity as a double array. The First Column vector is time, based on the time step, the second vector 
	 * is the velocity magnitude.
	 * 
	 * BigO: order N
	 * @param smoothPath
	 * @param timeStep
	 * @return
	 */
/*
    std::vector<std::vector<double>> velocity(std::vector<Point> smoothPath, double timeStep)
    {
        std::vector<double> dxdt = std::vector<double>(smoothPath.size());
        std::vector<double> dydt = std::vector<double>(smoothPath.size());
        std::vector<std::vector<double>> vel(smoothPath.size());

        dxdt[0] = 0;
        dydt[0] = 0;
        vel[0].push_back(0);
        vel[0].push_back(0);
        heading[0].push_back(0);
        heading[0].push_back(0);
        for (int i = 1; i < smoothPath.size(); i ++) 
        {
            dxdt[i] = (smoothPath[i]._x - smoothPath[i-1]._x)/timeStep;
            dydt[i] = (smoothPath[i]._y - smoothPath[i-1]._y)/timeStep;
            vel[i].push_back(vel[i-1][0] + timeStep);
            heading[i].push_back(heading[i-1][0] + timeStep);
            vel[i].push_back(sqrt(pow(dxdt[i], 2) + pow(dydt[i], 2)));
        }
        return vel;

    }
*/
	/**
	 * optimize velocity by minimizing the error distance at the end of travel
	 * when this function converges, the fixed velocity vector will be smooth, start
	 * and end with 0 velocity, and travel the same final distance as the original
	 * un-smoothed velocity profile
	 * 
	 * This Algorithm may never converge. If this happens, reduce tolerance. 
	 * 
	 * @param smoothVelocity
	 * @param origVelocity
	 * @param tolerance
	 * @return
	 */

/*
    std::vector<std::vector<double>> velocityFix(std::vector<std::vector<double>> smoothVelocity, std::vector<std::vector<double>> originalVelocity, double tolerance)
    {
        std::vector<double> difference = errorSum(originalVelocity, smoothVelocity);
        std::vector<std::vector<double>> fixVel(smoothVelocity.size());
        for (int i = 0; i < smoothVelocity.size(); i ++)
        {
            fixVel[i] = smoothVelocity[i];
        }
        double increase = 0.0;
        while (fabs(difference.back()) > tolerance)
        {

        }

    }

    std::vector<double> errorSum(std::vector<std::vector<double>> smoothVelocity, std::vector<std::vector<double>> originalVelocity)
    {
        std::vector<double> smoothLocation(smoothVelocity.size());
        std::vector<double> originalLocation(originalLocation.size());
        std::vector<double> difference(smoothVelocity.size());

        double timeStep = origVelocity[1][0]-origVelocity[0][0];
		originalLocation[0] = origVelocity[0][1];
		smoothLocation[0] = smoothVelocity[0][1];
		//calculate difference
		for (int i = 1; i < originalVelocity.size(); i++)
		{
			originalLocation[i] = originalVelocity[i][1]*timeStep + originalLocation[i-1];
			smoothLocation[i] = smoothVelocity[i][1]*timeStep + smoothLocation[i-1];
			difference[i] = smoothLocation[i] - originalLocation[i];
		}
		return difference;
	}
    */

   