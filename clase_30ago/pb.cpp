#include <iostream>
#include <armadillo>
//#define ARMA_USE_LAPACK
//#define ARMA_USE_BLAS
//#define ARMA_DONT_USE_WRAPPER

using namespace std;
using namespace arma;
using namespace lapack;

int main ()
{

	mat A,B,C; //declaracion de la matriz A 2x3

	A << -10 << 4 << -5  << endr
	  << 18 << -2 << -5 << endr;

	B << 700  <<endr
	  << 5000 <<endr;

	  A.print("\nMatriz 2x3 original: ");

//Procedimiento para la transpuesta manual por (derecha)

    mat At = trans(A);
    mat Amanual = At * inv((A * At));

    Amanual.print("\nPseudo inversa manual por derecha:");

    C = Amanual*B;

	C.print("Temperaturas manual: ");

	C = pinv(A)*B;

	C.print("Temperaturas auto: ");	

return 0;
}
