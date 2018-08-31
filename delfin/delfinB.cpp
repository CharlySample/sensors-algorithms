#include <iostream>
#include <armadillo>
#include <fstream>
#define pi 3.14159

using namespace std;
using namespace arma;

int main()
{

	double l1=1.0,l2=.5,l3=.25,s1,s12,s123,c1,c12,c123;

	mat A,B, C;


	B << .45 << endr
      << .45 << endr;

    float phi2=-pi/8;
    float phi3=-pi/8;

    ofstream fp("delfinc.txt");

    for(float phi1=-pi/4;phi1<=pi/4;phi1+=pi/180)
    {
    	s1=sin(phi1);
	   	s12=sin(phi1+phi2);
	   	s123=sin(phi1+phi2+phi3);
		c1=cos(phi1);
		c12=cos(phi1+phi2);
		c123=cos(phi1+phi2+phi3);

    	A << (-l1*s1)-(l2*s12)-(l3*s123) << (-l2*s12)-(l3*s123) << -l3*s123 <<endr
    	  << (l1*c1)+(l2*c12)+l3*c123 << (l2*c12)+(l3*c123) << l3*c123 <<endr;

		C =pinv(A)*B;

    	phi2+=pi/360;
    	phi3+=pi/360;

    	fp << trans(C);
    	cout << trans(C);

    }

     fp.close();

	return 0;
} 
