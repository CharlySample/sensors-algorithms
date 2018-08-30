 #include <iostream>
#include <armadillo>
#include <fstream>
#define ARMA_USE_LAPACK
#define ARMA_USE_BLAS
#define ARMA_DONT_USE_WRAPPER

using namespace std;
using namespace arma;
using namespace lapack;

int main ()
{

//ofstream quizz("quizz");

			mat A; //declaracion de la matriz A 2x3
				A << -10 << 4  << -5  << endr
	 			  << 18  << -2 << -5 << endr;
float T1A = 70.0;
float T2A = 70.0;
			 mat DYA;
			 mat DYB;
			 mat RPWA;
			 mat RPWB;
for(int T3A= 63; T3A<=1500; T3A+=2)
		{
			mat B;
				B << T1A <<endr
	  			  << T2A <<endr
	 			  << T3A <<endr;
		RPWA = A*B;

		T1A+=2;
		T2A+=2;

	
		
		//trans(RPWA) .print("A:");
		DYA= join_cols(DYA, trans(RPWA));
		//DYA.print("Matriz Dinamica");
		//cout << trans(RPW) << endl;
		//quizz << T1 << ", " << T2 << ", " << T3 << endl;
		}

//DYA.print("Matriz Dinamica");

float T1B = 75.0;
float T3B = 80.0;

for(int T2B= 65; T2B<=1500; T2B+=2)
		{
			mat BB;
			  BB  << T1B <<endr
	  			  << T2B <<endr
	 			  << T3B <<endr;
		  
		RPWB = A*BB;
		DYB = join_cols(DYB, trans(RPWB));
		T1B += 2;
		T3B += 2;

		
		//trans(RPWB).print("B:");
		//cout << trans(RPW) << endl;
		//quizz << T1 << ", " << T2 << ", " << T3 << endl;
		//DYB = join_cols(DYB, trans(RPWB));
		}

DYA.print("A");
DYB.print("B");
//DYA.save("DYA.dat", arma_ascii);
//DYB.save("DYB.dat", arma_ascii);

	//quizz.close();

return 0;
}