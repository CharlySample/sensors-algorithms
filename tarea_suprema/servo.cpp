#include <iostream>
#include <armadillo>
#include <fstream>
#define PI 3.14159
#define R 360

using namespace std;
using namespace arma;

int main() {
  mat A,p(101,1),C,D,E;
  double th=0.0,th1=0.0;
  float alfus=0.0195,error=0.0;
  float ref = 2*PI;
  int w=0;
  double vel=0.0;
  ofstream myfile;

  myfile.open ("servo.txt");

  A.load("fi_s.txt",arma_ascii);

  for(int i = 0;i<=100;i++)
  {
    p(i , 0) = A(i , 1);
  }
int i=0;
    while(w==0 )
    {

    error = (ref-(((2*PI)/(R))*i));
    th1 = th + alfus*error;
    th = th1;
    vel = -0.139447+0.020435*th1-0.00028415*th1*th1+0.0000012592*th1*th1*th1;

    cout << th1 << endl;
    cout << vel << endl;
    myfile << th1 << endl;

  if (error > -0.1 and error < 0.1)
  w=1;
i++;
  }
  myfile.close();
  return 0;
}
