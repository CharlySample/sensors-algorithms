
/* Movement Library

Esta libreria contiene funciones , las cuales se comunican con la consola Python de FreeCAD para mover componentes.

 Compilacion:
 g++ -g -shared -fPIC Movement.cpp -o MoveModule.so -I/usr/include/python2.7 -lpython2.7 -lboost_python-2.7

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
  double kt=0.0,ct=0.0,m=1.0,raiz=0.0,positivo=0.0,negativo=0.0,a1=0.15,a2=0.2;
  public:

  double w1, v,sobres=0.0,critico=0.0, sub=0.0;
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

  void sobreamortiguado(double t)
  {
    kt=0.1248;
    ct=0.9117;
    raiz = sqrt(pow(ct,2)-4*m*kt);
    positivo = (-ct+raiz)/(2*m);
    negativo = (-ct-raiz)/(2*m);
    sobres = a1*exp(positivo*t)+a2*exp(negativo*t)*100;
  }

    void criticoamortiguado(double t)
  {
    kt=0.1248;
    ct=sqrt(kt*4);
    raiz = sqrt(pow(ct,2)-4*m*kt);
    positivo = (-ct+raiz)/(2*m);
    negativo = (-ct-raiz)/(2*m);
    critico = ((a1+a2*t)*exp(-ct*t/2*m))*100;
  }

   void subamortiguado(double t)
  {
    kt=0.1248;
    ct=0.1;
    raiz = sqrt(pow(ct,2)-4*m*kt);
    positivo = (-ct+raiz)/(2*m);
    negativo = (-ct-raiz)/(2*m);
    sub = 100*(a1*exp(-ct*t/2)*cos(sqrt((kt/m)+pow((ct/2),2))*t+0.1));
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
   .def("sobremor", &Movement::sobreamortiguado)
   .def_readwrite("ResultSA", &Movement::sobres)
   .def("criticof", &Movement::criticoamortiguado)
   .def_readwrite("ResultSB", &Movement::critico)
   .def("subamorf", &Movement::subamortiguado)
   .def_readwrite("ResultSC", &Movement::sub)
   ;
 }
