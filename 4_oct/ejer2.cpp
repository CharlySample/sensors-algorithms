#include <iostream>
#include <armadillo>
#include <cmath>
#define pi 3.14159

using namespace std;
using namespace arma;

int main()
{
  float epsilon=0.0001;
  long double x=-3.0, y=0.0,x2=0.0,x3=0.0,y2=0.0,y3=0.0;
  int i=0;
  mat A,B,C,Z;
  double error=100;

 // cout << "\nValor phi1 inicial: ";
//  cin >> phi1;

 // cout << "\n\nValor phi2 inicial: ";
 // cin >> phi2;

cout << "valor inicial x: " << x << "\tvalor inicial y: " << y << endl;

  cout << "\n";

  while(error > .000001)
  {
    A << x << y  << endr;
    A = trans(A);

    x2 = pow(x,2);
    x3 = pow(x,3);
    y2 = pow(y,2);
    y3 = pow(y,3);

    B << (3*x2*y) - y2 << x3-(2*y*x) << endr
       << 3*x+(2*x*y2) << 2*x2*y << endr
       << -2*x*y2 << 3*y2-(2*x2*y) << endr;

    B = pinv(B);

 C << x3*y-y2*x -35 << endr
     << x3+(x2*y2) -0.73 << endr
     << y3-x2*y2 -8.1 << endr;

     Z = A - (B*C);

     error = abs(sqrt(pow((Z(0,0) - A(0,0)),2)+pow((Z(1,0) - A(1,0)),2)));

     x = Z(0,0);
     y = Z(1,0);
     i++;

      cout << "Valor x: " << x << " \tValor y: " << y << " \tIteracion numero: " << i <<
"\tError: " <<
error << endl;
      //cout << "Error en interaccion " << i << ": " << error << endl;
  }

cout << "\nIteracciones: " << i << "\n\n";


cout << "Valor final x: " << x << "\nValor final y: " << y << endl;

  return 0;
}