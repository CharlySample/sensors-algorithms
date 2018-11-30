// Cabecera para realizar integracion por metodo del trapecio.
#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

mat integracion(mat t,mat v)
{
        double acu=0.0,a=0.0,b=0.0,c=0.0;
        int n=0,p=0;

        mat s(v.n_rows,1);

        a = t(0,0);
        s(0,0) = 0;

        for(int i = 1; i<=v.n_rows-1; i++)
        {
                b = t(i,0);
                c = v(i,0);
                n = b-a;
                s(i,0) = ((b-a)/(2*n))*(v(0,0)+(2*acu)+c);
                acu += c;
                //p++;
        }

        return s;
}
