#include <iostream>
#include <armadillo>
#include <cmath>
#define pi 3.14159

using namespace std;
using namespace arma;

int main()
{
  float epsilon=0.0001;
  double phi1=pi/2, phi2=pi/8;
  double l1=1.0,l2=1.0;
  int i=0;
  mat A,B,C,Z;
  double error=100;

 // cout << "\nValor phi1 inicial: ";
//  cin >> phi1;

 // cout << "\n\nValor phi2 inicial: ";
 // cin >> phi2;

cout << "valor inicial phi1: " << phi1 << "\tvalor inicial phi2: " << phi2 << endl;

  cout << "\n";

  while(error > .0001)
  {
    A << phi1 << phi2 << endr;
    A = trans(A);

    B << -l1*sin(phi1)-l2*sin(phi1+phi2) << -l2*sin(phi1+phi2) << endr
       << l1*cos(phi1) + l2*cos(phi1+phi2) << l2*cos(phi1+phi2) << endr;

 B = inv(B);

 C << l1*cos(phi1)+l2*cos(phi1+phi2) - 2<< endr
     << l2*sin(phi1) + l2*sin(phi1+phi2) << endr;

     Z = A - B*C;

     error = abs(sqrt(pow((Z(0,0) - A(0,0)),2)+pow((Z(1,0) - A(1,0)),2)));

     phi1 = Z(0,0);
     phi2 = Z(1,0);
i++;

      cout << "Valor phi 1: " << phi1 << " \tValor phi 2: " << phi2 << " \tIteracion numero: " << i << 
"\tError: " << 
error << endl;
      //cout << "Error en interaccion " << i << ": " << error << endl;
  }

cout << "\nIteracciones: " << i << "\n\n";


cout << "Valor final phi1: " << phi1 << "\nValor final phi2: " << phi2 << endl;



  return 0;
}
