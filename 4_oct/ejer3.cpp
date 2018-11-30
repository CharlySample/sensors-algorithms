#include <iostream>
#include <armadillo>
#include <cmath>
#define pi 3.14159

using namespace std;
using namespace arma;

int main()
{
  float epsilon=0.0001;
  long double w=3.0, th=2.0,w2=0.0,w3=0.0,th2=0.0,th3=0.0;
  int i=0;
  mat A,B,C,Z;
  double error=100;

 // cout << "\nValor phi1 inicial: ";
//  cin >> phi1;

 // cout << "\n\nValor phi2 inicial: ";
 // cin >> phi2;

cout << "valor inicial w: " << w << "\tvalor inicial th: " << th << endl;

  cout << "\n";

  while(error > .000001)
  {
    A << w << th  << endr;
    A = trans(A);

    w2 = pow(w,2);
    w3 = pow(w,3);
    th2 = pow(th,2);
    th3 = pow(th,3);

    B << cos(th)+6.1 << w*sin(th) << endr
       << -2*th*w << 2*sqrt(2)*th-w2 << endr
       << -2*w << (3*th2)/4 << endr;

    B = pinv(B);

 C << w*cos(th)+6.1*w-sqrt(63.98) << endr
     << sqrt(2)*th2-th*w2-3.25 << endr
     << th3/4 - w2 -15.3 << endr;

     Z = A - (B*C);

     error = abs(sqrt(pow((Z(0,0) - A(0,0)),2)+pow((Z(1,0) - A(1,0)),2)));

     w = Z(0,0);
     th = Z(1,0);
     i++;

      cout << "Valor w: " << w << " \tValor th: " << th << " \tIteracion numero: " << i <<
"\tError: " <<
error << endl;
      //cout << "Error en interaccion " << i << ": " << error << endl;
  }

cout << "\nIteracciones: " << i << "\n\n";


cout << "Valor final w: " << w << "\nValor final th: " << th << endl;

  return 0;
}