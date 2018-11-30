
/* Movement Library

   Esta libreria contiene funciones , las cuales se comunican con la consola Python de FreeCAD para mover componentes.

   Compilacion:
   g++ -g -shared -fPIC master.cpp -o MoveModule.so -I/usr/include/python2.7 -lpython2.7 -lboost_python-2.7

 */

#include <boost/python.hpp>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <armadillo>
#include <iostream>
#include <cmath>
#define pi 3.14159

using namespace arma;
using namespace std;

class Movement
{
private:
double raiz=0.0,positivo=0.0,negativo=0.0,ctejemplo=0.0;
public:

double w1, v,xt=0.0;
/* ENGRANE -> ENGRANE
   La funcion recibe el angulo intantaneo del engran conductor "w0", el radio del engran conductor "r0", el radio del engran conducido "r1" y un valor booleano
   "direction". Este valor debera ser 0 para situaciones en que deben girar en el mismo sentido, y 1 para cuando giran en sentidos contrarios
   Regresa la posicion instantanea "w1" del engran conducido */

void gearToGear(double w0, double r0, double r1, bool direction)
{
        w1 = r0*w0/r1;
        if(direction==1)
                w1*=-1;
}

void resorte_amortiguador(double t,double kt, double ct,double m, double a1, double a2)
{
        raiz = pow(ct,2)-4*m*kt;

        if(ct > sqrt(kt*4))
        {
        positivo = (-ct+raiz)/(2*m);
        negativo = (-ct-raiz)/(2*m);
        }

        if(raiz > 0)
        {
                cout << "sobreamortiguado" << endl << endl;
                xt = a1*exp(positivo*t)+a2*exp(negativo*t);
        }

        else if(raiz == 0)
        {
          cout << "criticamente amortiguado" << endl << endl;
          xt = (a1+a2*t)*exp(-ct*t/2*m);
        }

        else if(raiz < 0)
        {
          cout << "subamortiguado" << endl << endl;
          xt = a1*exp(-ct*t/2*m)*cos(sqrt((kt/m)+pow((ct/2*m),2))*t+0.1);
        }

}

// Funcion Oscilante
void oscilar(double w,double z)
{
        v = z*sin(w);
}

};

BOOST_PYTHON_MODULE(MoveModule)
{
        using namespace boost::python;

        class_<Movement>("pMovement")

        .def("GearToGear", &Movement::gearToGear)
        .def_readwrite("ResultW", &Movement::w1)
        .def("Oscilar", &Movement::oscilar)
        .def_readwrite("ResultV", &Movement::v)
        .def("resorteamortiguador", &Movement::resorte_amortiguador)
        .def_readwrite("ResultXT", &Movement::xt)
        ;
}
