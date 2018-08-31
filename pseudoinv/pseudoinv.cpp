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

	mat A,B; //declaracion de la matriz A 2x3
	A << 2 << .12 << 4  << endr
	  << 12.22 << 23.5 << -2.5 << endr;

	B << 2 << .23 << endr
	  << 12 << .21 << endr
	  << .123 << 41 << endr;

	  A.print("\nMatriz 2x3 original: ");

	//Procedimiento para la transpuesta manual por (izq)

	mat At = trans(A);
	mat Amanual = inv((At * A))*At;


	Amanual.print("\nPseudo inversa manual por izquierda:");

	//Procedimiento para la transpuesta auto por (izq)

	mat Aauto = pinv(A);

	Aauto.print("\nPseudo inversa auto por izquierda:");

	B.print("\nMatriz 3X2 original");

	//Procedimiento para la transpuesta manual por (derecha)

    mat Bt = trans(B);
    mat Bmanual = Bt * inv((B * Bt));

    Bmanual.print("\nPseudo inversa manual por derecha:");

    //Procedimiento para la transpuesta auto por (derecha)

    mat Bauto = pinv(B);

    Bauto.print("\nPseudo inversa manual por derecha:");

	//Amanual.print("Pseudo inversa manual por izquierda: ");
	//Bmanual.print("Pseudo inversa manual por derecha: ");
	

	

return 0;
}
