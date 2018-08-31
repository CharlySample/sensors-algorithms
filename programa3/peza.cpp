#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
	//mat A,B, C ;

	float pi =3.14159;

	float l1=1.0,l2=1.0, s1,s12,c1,c12;

	mat A,B, C ;


	B << pi/2 << endr
      << pi/2 << endr;

    for(float phi1=-pi/4;phi1<=pi/4;phi1+=pi/4)
    {
    	A << -l1*s1-l2*s12 << -l2*s12 << endr
    	  << l1*c1+l2*c12 << l2*c12 << endr;

    	s1=sin(phi1);
	   	s12=sin(phi1+phi2);
		c1=cos(phi1);
		c12=cos(phi1+phi2);

		C =A*B;

    	phi2+=pi/180;

    	C.print("\nMatriz C: ");

    }

	A.print("Matriz A: ");
	B.print("Matriz B: ");
	//C.print("Matriz C: ");

	return 0;
} 
