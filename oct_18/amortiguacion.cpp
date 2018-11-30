#include <armadillo>
#include <iostream>
#include <master>
#include <cmath>

using namespace std;
using namespace arma;

int main()
{
    mat a,b,c,k;
    double ka,kb,kc,kt,ct,raiz;
    //long double xt=0.0;
    double a1 = 0.015,a2=0.015;
    long double positivo = 0.0,negativo=0.0,xt=0.0;
    int m=1;
    resorte o1;
    ofstream fp("crack.txt");

//kt = 0.1248;
//ct = 0.9117;
//  kt = 0.12;
//  ct = 0.1;
kt = 2.15;
ct = 0.35;
  //  raiz = pow(ct,2)-4*m*kt;
    //cout << raiz << endl;
    //ct = sqrt((kt*4));
   raiz = pow(ct,2)-4*m*kt;
    positivo = (-ct+raiz)/(2*m);
    negativo = (-ct-raiz)/(2*m);

    cout << raiz << endl;


   if(raiz > 0)
    {
      cout << "sobreamortiguado" << endl << endl;

      for(float t=0.1;t<=45;t+=0.1)
      {
      xt = a1*exp(positivo*t)+a2*exp(negativo*t);
      cout << xt << "\t" << t << endl;
      fp << xt << "\t" << t << endl;
    }
    }

    else if(raiz == 0)
    {
      cout << "criticamente amortiguado" << endl << endl;

      for(float t=0.1;t<=45;t+=0.1)
      {
      xt = (a1+a2*t)*exp(-ct*t/2);
      cout << xt << "\t" << t << endl;
      fp << xt << "\t" << t << endl;
    }

    }

    else if(raiz < 0)
    {
      cout << "subamortiguado" << endl << endl;

      for(float t=0.1;t<=45;t+=0.1)
      {
      xt = a1*exp(-ct*t/2)*cos(sqrt((kt/m)+pow((ct/2),2))*t+0.1);
      cout << xt << "\t" << t << endl;
      fp << xt << "\t" << t << endl;
      }

    }

    fp.close();
  return 0;
}
