#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

#define ARMA_USE_LAPACK
#define ARMA_USE_BLAS

int main()
{
	mat A,B,C,D;

	A << .5 << .5 << .5 << .5 <<endr
	  << .5 << .5 << -.5 << -.5 <<endr
	  << 1.5 << -2 << -.5 << 8 << endr
	  << -5 << 10 << 4 << -8 <<endr;

	B << 1.5 << endr
	  << 0.7853975 << endr
	  << 255 << endr
	  << 100 << endr;

    C = inv(A);

	D = solve(A,B);

	A.print("Matriz A: ");
	B.print("Matriz B: ");
	C.print("Matriz inversa de A: ");
	cout << endl << "Determinante de A^-1: " <<det(C) << endl << endl;
	D.print("Matriz resultado: ");


	return 0;
}