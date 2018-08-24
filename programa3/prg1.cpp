#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
	mat A,B ;
	double c;

  A << 0.732 << 1.4142 << endr
    << 10.87 << 3.028 << endr;

  B << 25 << endr
  	<< 0.75 << endr;

	cout << inv(A)*B << endl;

	return 0;
} 