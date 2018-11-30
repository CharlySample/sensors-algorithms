#include <iostream>
#include <cmath>
#include <fstream>
#include <armadillo>

using namespace arma;
using namespace std;

int main() {
long double th=0.0,vel=0.0,pi=3.141592654;
mat a,b,c;
//ofstream fp("carlos.txt");
c.load("carlos.txt",arma_ascii);
  for(int i = 0;i<=360;i+=1)
{
  th = c(i,1);
  //th = th*(pi/180);
  //if(th < 11)
  //vel = 0;
  //else
  vel = 10.219556+2157.628113*th-262954.615377*pow(th,2)+10421912.785740*pow(th,3);


  cout << vel << ", " << th << ", " << i << endl;
  b << vel << th << endr;
  a = join_cols(a,b);
}
a.save("evaluacion.txt",arma_ascii);
//fp.close();
  return 0;
}
