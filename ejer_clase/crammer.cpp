#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;


int main()
{
	mat A,B,C,D, X, E;
	double u,w,x,y;

	A << 1.5 << .5 << .5 << .5 <<endr
	  << 3.14159/4  << .5 << -.5 << -.5 <<endr
	  << 255 << -2 << -.5 << 8 << endr
	  << 100  << 10 << 4 << -8 <<endr;

	B << .5 << 1.5 << .5 << .5 <<endr
	  << .5 << 3.14159/4  << -.5 << -.5 <<endr
	  << 1.5 << 255 << -.5 << 8 << endr
	  << -5 << 100  << 4 << -8 <<endr;

	C << .5 << .5 << 1.5 << .5 <<endr
	  << .5 << .5 << 3.14159/4  << -.5 <<endr
	  << 1.5 << -2 << 255 << 8 << endr
	  << -5 << 10 << 100  << -8 <<endr;

 	D << .5 << .5 << .5 << 1.5  <<endr
	  << .5 << .5 << -.5 << 3.14159/4  <<endr
	  << 1.5 << -2 << -.5 << 255 << endr
	  << -5 << 10 << 4 << 100  <<endr;

	E << .5 << .5 << .5 << .5 <<endr
	  << .5 << .5 << -.5 << -.5 <<endr
	  << 1.5 << -2 << -.5 << 8 << endr
	  << -5 << 10 << 4 << -8 <<endr;



	X << -43.8665 <<endr
	  << 46.1519 << endr
	  << -47.9278 << endr
	  << 48.6424 << endr;

    u = det(A)/det(E);
    w = det(B)/det(E);
    x = det(C)/det(E);
    y = det(D)/det(E);

    cout << u << endl << w << endl << x << endl << y << endl;


	return 0;
}