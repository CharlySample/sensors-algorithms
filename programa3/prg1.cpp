#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
	mat A,B, C ;

  A << 2/2 << 1/2 << endr
    << 4/3 << 1/6 << endr;

  B << 34/2 << endr
    << 11/2 << endr;

   C = inv(A)*B;

	A.print("Matriz A: ");
	B.print("Matriz B: ");
	C.print("A^-1 * B: ");

	return 0;
} 
