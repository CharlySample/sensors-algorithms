#include <iostream>
#include <armadillo>
#include <fstream>
#define pi 3.14159

using namespace std;
using namespace arma;

class calculos
{
public:

    mat phi,phip,phipp,t,y,tabla,A;
    int R = 50;
////////////////////////// Funcion para el desarrollo de las formulas ////////////////////////
    void desarrollo()
    {
        phi(0,0)=0.0;
        phip(0,0)=0.0;
        phipp(0,0)=0.0;
////////////////////////// Asignando valores al vector de tiempo y pulsos ///////////////////////
         t << 0.0 << .5 << 1.25 << 1.5 << 2.0 << 2.75 << 3.5 << 4.5 << 5.0 << 7.25 << endr;
         y  << 0.0 << 10 << 12 << 15 << 25 << 75 << 120 << 122 << 125 << 125 << endr;


///////////////////////// Ciclo for para asignar valores al vector de posicion angular///////////////////////
        for(int i=1;i<=9;i++)
            phi(i,0) = ((2*pi)/R)*y(0,i); 

///////////////////////// Ciclo for para asignar valores al vector de velocidad angular///////////////////////
        for(int i=1;i<=9;i++)
            phip(i,0) = ((2*pi)/R)*((y(0,i)-y(0,i-1))/(t(0,i)-t(0,i-1)));

///////////////////////// Ciclo for para asignar valores al vector de acceleracion angular //////////////////////
        for(int i=1;i<=9;i++)
            phipp(i,0) = (phip(i,0)-phip(i-1,0))/(t(0,i)-t(0,i-1));

/////////////////////// Union de los vectores de tiempo, pulsos, posicion, velocidad y acceleracion ///////////////////////////
            A = join_rows(A,trans(t));
            A = join_rows(A,trans(y));
            A = join_rows(A,phi);
            A = join_rows(A,phip);
            A = join_rows(A,phipp);

    }
    
};

int main()
{  
/////////////////////////Declaracion del objeto encoder del tipo calculos ////////////////////////////////////////////////////////
    calculos encoder;

//////////////////////// Valores mandados a la clase de calculo ////////////////////////////////////////////////////////////////////
    mat phi(10,1),phip(10,1),phipp(10,1);
    encoder.phi=phi;
    encoder.phip=phip;
    encoder.phipp=phipp;
//////////////////////// Iniciando la funcion desarrollo de la clase calculos ////////////////////////////////////////////////////
    encoder.desarrollo();

//////////////////////// Impresion y guardado de la matriz resultante de la suma de los vectores ///////////////////////////////////////
    encoder.A.print("matriz: ");
    encoder.A.save("tabla.txt",arma_ascii);

	return 0;
} 
