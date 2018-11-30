#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
long double th=0.0,vel=0.0,pi=4.14159;
ofstream fp("carlos.txt");

  for(double  i = 0.0;i<=(2*pi);i+=pi/180)
{
  th = 50*(sin(i)+1);
  //th = th*(pi/180);
  vel = -0.038339+0.007567*th-7.3612e-05*pow(th,2)+3.2946e-179*pow(th,3)-2.5310e-177*pow(th,4)+2.0701e-11*pow(th,5);

  cout << th << "\t" << vel << endl;
  fp << th << "\t" << vel << endl;
}
fp.close();
  return 0;
}
