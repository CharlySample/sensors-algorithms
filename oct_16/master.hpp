// Cabecera con varias funciones.
#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

// Integracion por metodo del trapecio.
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
        }

        return s;
}

// classe para la obtencion de kt o ct (problemas de resorte amortiguador.)
class resorte
{
private:
double kt=0.0, arriba=1.0,abajo=0.0,producto=1.0;
int n=0;
public:
///////////////////////////////Funcion para resolver resorte,etc en serie////////////////////////////////////////////
double serie(mat k)
{
        n = k.n_cols-1;

        for(int j=0; j<=n; j++)
        {
                arriba *= k(0,j);

                for(int i=0; i<=n; i++)
                {
                        if(i!=j)
                                producto *= k(0,i);
                }
                abajo += producto;
                producto=1.0;
        }

        kt = arriba/abajo;

        return kt;
}
////////////////////////////////////////// Funcion para resolver resorte etc en paralelo//////////////////////////////////////////
double paralelo(mat k)
{
        n = k.n_cols-1;
// Sumatoria del vector k
        for(int j=0; j<=n; j++)
                kt +=k(0,j);

        return kt;
}

};
