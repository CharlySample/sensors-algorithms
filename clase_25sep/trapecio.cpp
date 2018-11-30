#include <iostream>
#include <armadillo>
#include "integracion.hpp"
#include <fstream>

using namespace std;
using namespace arma;

int main()
{
        mat t,a,s,impria(10,2),impriv(10,2),impris(10,2);
      //  ofstream fp("tabla.txt");

        t << 2 << 5  << 12 << 15 << 17 << 20 << 23 << 25 << 27 << 28 <<  endr;
        t = trans(t);

        a << 7 << 14.5 << 13 << 2.5 << 0 << 3 << 15 << 18 << 20 << 22 << endr;
        a= trans(a);

        s = integracion(t,a);

        //s.print();

        for(int i=0;i<=9;i++)
        {
        impriv(i,0) = t(i,0);
        impriv(i,1) = s(i,0);
        impria(i,0) = t(i,0);
        impria(i,1) = a(i,0);
      }

      s = integracion(t,s);

      for(int i=0;i<=9;i++)
      {
      impris(i,0) = t(i,0);
      impris(i,1) = s(i,0);
    }



      impriv.print();

    impriv.save("tabla.txt",arma_ascii);
    impria.save("tabla1.txt",arma_ascii);
    impris.save("tabla2.txt",arma_ascii);

        //fp << t(i,0) << "," << s(i,0) << endl;

    //    fp.close();
        return 0;
}
