#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
	mat A,B, C ;

  A << 0.732 << 1.4142 << endr
    << 10.87 << 3.028 << endr;

  B << 25 << endr
    << 0.75 << endr;

   C = inv(A)*B;

	A.print("Matriz A: ");
	B.print("Matriz B: ");
	C.print("A^-1 * B: ");

	return 0;
} 
