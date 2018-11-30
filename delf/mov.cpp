#include <iostream>
#include <armadillo>
#define pi 3.14159

using namespace std;
using namespace arma;

int main()
{
	double l1=1.373,l2=0.7,l3=0.520,s1,s12,s123,c1,c12,c123;

	mat A,B, C, dummy;

		double phi1 = 0;
    double phi2=0;
    double phi3= 0;

    for(int i=0;i<=100;i++)
    {
    	s1=sin(phi1);
	   	s12=sin(phi1+phi2);
	   	s123=sin(phi1+phi2+phi3);
		  c1=cos(phi1);
		  c12=cos(phi1+phi2);
		  c123=cos(phi1+phi2+phi3);

    	A << (-l1*s1)-(l2*s12)-(l3*s123) << (-l2*s12)-(l3*s123) << -l3*s123 <<endr
    	  << (l1*c1)+(l2*c12)+l3*c123 << (l2*c12)+(l3*c123) << l3*c123 <<endr;

			C << 0.1 << endr << 0.1 << endr;

	    B =pinv(A)*C;

			phi1 = B(0,0);
			phi2 = B(1,0);
			phi3 = B(2,0);

			dummy = join_cols(dummy,trans(B));

    	//cout << trans(B) << endl;
  }

		//cout << dummy << endl;
    dummy.save("mover.txt",raw_ascii);
    dummy.save("mo.txt",arma_ascii);

		mat yup;

		yup.load("mover.txt",raw_ascii);

		cout << yup << endl;

	//A.print("Matriz A: ");
	//B.print("Matriz B: ");
	//C.print("Matriz C: ");

	return 0;
}
