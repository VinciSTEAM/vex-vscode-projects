#ifndef HAX_H_
#define HAX_H_

#include "vex.hpp"
#include "vector"
#include "iostream"

double La=0;
double Ra=0;
double Ba=0;//back arc
double lD =0;
double rD=0;//right tracker to tracking center distance
double bD =0;//back tracker to tracking center distance
double g0=0;
double head0=0;//previous heading
double curhead=0;//current heading
double px=0;
double py=0;
double x=0;
double y=0;
double gor=0;
using namespace std;
vector<double> prevcoordy (py);
vector<double> prevcoord (px,py);
void odomtrack()
{
  
}
void odom()
{
  odomtrack();
  curhead=(La-Ra)/(lD+rD)*180/M_PI;//tracks heading
  prevcoordy.at(0)=2*sin(curhead/2)*(Ra/curhead+rD);
  prevcoord.at(0)=2*sin(head0/2)*(Ba/curhead+bD);
  prevcoord.at(1)=2*sin(head0/2)*(Ra/curhead+rD);
  head0=curhead;
  cout << "coordinates:(";
  for(int i=0; i<2;i++)
  {
    if(i<1)
    {
      cout << prevcoord.at(i)<<", ";
    }
    else
    {
      cout << prevcoord.at(i);
    }
  }
  cout<<"); "<< "heading: "<<curhead<<endl;
  head0=curhead;
}
#endif