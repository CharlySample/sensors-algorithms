#include <iostream>
#include <armadillo>
#include <cmath>
#define pi 3.14159

using namespace std;
using namespace arma;

int main()
{
  float epsilon=0.0001;
  long double phi1=3.0, phi2=-2.0,phi3=1.0,phi4=-2.0,phi12=0.0,phi13=0.0;
  long double phi22=0.0,phi23=0.0,phi32=0.0,phi33=0.0,phi42=0.0,phi43=0.0;
  int i=0;
  mat A,B,C,Z;
  double error=100,error1=100;

 // cout << "\nValor phi1 inicial: ";
//  cin >> phi1;

 // cout << "\n\nValor phi2 inicial: ";
 // cin >> phi2;

cout << "valor inicial phi1: " << phi1 << "\tvalor inicial phi2: " << phi2 << "\tvalorinicial phi3: " << phi3 << "\tvalor inicial phi4: " << phi4 << endl;

  cout << "\n";

  while(error > .000001 or error1 > .000001)
  {
    A << phi1 << phi2  << phi3 << phi4 << endr;
    A = trans(A);

    phi12 = pow(phi1,2);
    phi13 = pow(phi1,3);
    phi22 = pow(phi2,2);
    phi23 = pow(phi2,3);
    phi32 = pow(phi3,2);
    phi33 = pow(phi3,3);
    phi42 = pow(phi4,2);
    phi43 = pow(phi4,3);

    B << -3*phi12 << 4*phi2 << 2 << 1 << endr
      << -2 << phi2*phi3 << 3*phi2-4 << 4*phi4 << endr
      << 3 << -20*phi2 << 10*phi3 << 3*phi42 << endr
      << 4*phi1 << -10*phi2 << 4*phi4 << 6*phi4 << endr;

    B = inv(B);

 C << -phi13 + 2*phi22+2*phi3+phi4 - 5 << endr
   << -2*phi1+3*phi2*phi3-4*phi3+2*phi42+1 << endr
   << 3*phi1-10*phi22+5*phi32+phi43-10 << endr
   << 2*phi12-5*phi22+4*phi3*phi4+phi42-9 << endr;

     Z = A - (B*C);

     error = abs(sqrt(pow((Z(0,0) - A(0,0)),2)+pow((Z(1,0) - A(1,0)),2)));
     error1 = abs(sqrt(pow((Z(2,0) - A(2,0)),2)+pow((Z(3,0) - A(3,0)),2)));

     phi1 = Z(0,0);
     phi2 = Z(1,0);
     phi3 = Z(2,0);
     phi4 = Z(3,0);
     i++;

      cout << "Valor phi1: " << phi1 << " \tValor phi2: " << phi2 << "\rValor phi3: " << phi3  <<  "\tValor phi4: " << phi4 <<" \tIteracion numero: " << i <<
"\tError: " <<
error << endl;
      //cout << "Error en interaccion " << i << ": " << error << endl;
  }

cout << "\nIteracciones: " << i << "\n\n";


cout << "Valor final phi1: " << phi1 << "\nValor final phi2: " << phi2 << "\tValor final phi3: " << phi3 << "\tValor final phi4: "<< phi4 << endl;

  return 0;
}