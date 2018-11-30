#include <iostream>
#include <cmath>
#include <fstream>
#include <armadillo>

using namespace arma;
using namespace std;

int main() {
long double th=0.0,vel=0.0,pi=3.141592654,pos=0.0;
int t=0;
mat a,b;


  for(double  i = 0.0;i<=(100.0);i+=0.1)
{
  th = 200*sin(cos(sin(sin(i))))-80;
 
  vel = -0.00372482*pow(th,0)+0.000516511*pow(th,1)-6.23058e-06*pow(th,2)-9.5486e-19*pow(th,3)-1.39134e-182*pow(th,4)+8.12813e-12*pow(th,5)-6.94322e-14*pow(th,6)-6.25561e-181*pow(th,7)+1.07329e-18*pow(th,8);
  pos = -94.3733+109743*vel-3.2053e+07*pow(vel,2)+3.00976e+09*pow(vel,3)+6.9389e-178*pow(vel,4)+1.38968e-181*pow(vel,5)-7.84814e+14*pow(vel,6);


if(th > 15)
{
  cout << th << ", " << vel << ", " << t << ", " << pos << endl;
  b << th << vel << t << pos << endr;
  a = join_cols(a,b);
  t+=2;
}

}
a.save("5c.txt",arma_ascii);

  return 0;
}
