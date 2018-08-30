#include <iostream>
#include <armadillo>
#include <fstream>

using namespace std;
using namespace arma;
using namespace lapack;

int main ()
{

	mat A,B,C,D,E,F,H,Z; //declaracion de la matriz A 2x3

	A << -10 << 4 << -5  << endr
	  << 18 << -2 << -5 << endr;



	int t2=70,t1=70;

	for(int t3 = 63 ; t3<= 1500 ; t3+=2)
	{

		B << t1 << endr
	  	  << t2 << endr
	      << t3 << endr;

		C = A * B;

	    //cout << trans(C) << endl;

		t1+=2;
    	t2+=2;

		D = join_cols(D, trans(C));
    }

   // D.print("primer matriz:");
   // D.save("D.dat",arma_ascii);


   float t3b=80;
   float t1b=75;

	for(int t2b = 65 ; t2b<= 1500 ; t2b+=2)
	{
		B << t1b << endr
	      << t2b << endr
	      << t3b << endr;

		F = A * B;

		E = join_cols(E, trans(F));

		t3b+=2;
		t1b+=2;
    }

    //H = join_rows(D,E);

    D.print("primer matriz:");
    E.print("segunda matriz: ");
    D.save("D.dat",arma_ascii);
    E.save("E.dat",arma_ascii);




	  //A.print("\nMatriz 2x3 original: ");

	//Procedimiento para la transpuesta manual por (izq)

	//mat At = trans(A);
	//mat Amanual = inv((At * A))*At;

	//C = Amanual*B;

	//C.print("Temperaturas manual: ");

	//C = pinv(A)*B;

	//C.print("Temperaturas auto: ");
	
return 0;
}
