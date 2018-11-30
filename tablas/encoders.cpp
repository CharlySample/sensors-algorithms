#include <iostream>
#include <armadillo>
#include <fstream>
#define pi 3.14159

using namespace std;
using namespace arma;

class calculos
{
public:

    mat phi,phip,phipp,tabla,A,s,v,a,kheverga;
    int R = 90; // rpp
    float r = 0.006575; // radio

////////////////////////// Funcion para el desarrollo de las formulas ////////////////////////
    void desarrollo()
    {
///////////////////////// Poner en 0 la posicion 0,0 de los vectores /////////////////////////////////////
        phi(0,0)=0.0;
        phip(0,0)=0.0;
        phipp(0,0)=0.0;
        s(0,0)=0.0;
        v(0,0)=0.0;
        a(0,0)=0,0;

////////////////////////// Asignando valores al vector de tiempo y pulsos ///////////////////////
         kheverga.load("124.txt");
	 mat t(kheverga.n_rows,1);
	 mat y(kheverga.n_rows,1);
	 
	for(int i=0;i<=kheverga.n_rows-1;i++)
{
	 t(i,0) = kheverga(i,0);
         y(i,0) = kheverga(i,1);
}

t = trans(t);
y = trans(y);

///////////////////////// Ciclo for para asignar valores al vector de posicion angular///////////////////////
        for(int i=1;i<=66;i++)
            phi(i,0) = ((2*pi)/R)*y(0,i); 

///////////////////////// Ciclo for para asignar valores al vector de velocidad angular///////////////////////
        for(int i=1;i<=66;i++)
            phip(i,0) = ((2*pi)/R)*((y(0,i)-y(0,i-1))/(t(0,i)-t(0,i-1)));

///////////////////////// Ciclo for para asignar valores al vector de acceleracion angular //////////////////////
        for(int i=1;i<=66;i++)
            phipp(i,0) = (phip(i,0)-phip(i-1,0))/(t(0,i)-t(0,i-1));

//////////////////////// Ciclo for para asignar valores al vector de posicion angular ////////////////////////////////////
        for(int i=1;i<=66;i++)
            s(i,0) = ((2*pi*r)/R)*y(0,i);

//////////////////////// Ciclo for para asignar valores al vector de velocidad angular //////////////////////////////////////////
        for(int i=1;i<=66;i++)
            v(i,0) = ((2*pi*r)/R)*((y(0,i)-y(0,i-1))/(t(0,i)-t(0,i-1)));

///////////////////////////// Ciclo for para asignar valores al vector de acceleracion angular //////////////////////////////////////////
        for(int i=1;i<=66;i++)
            a(i,0) = (v(i,0)-v(i-1,0))/(t(0,i)-t(0,i-1));

/////////////////////// Union de los vectores de tiempo, pulsos, posicion, velocidad y acceleracion ///////////////////////////
            A = join_rows(A,trans(t)); // tiempo
            A = join_rows(A,trans(y)); // pulsos
            A = join_rows(A,phi); // posicion
            A = join_rows(A,phip); // velocidad
            A = join_rows(A,phipp); // acceleracion
            A = join_rows(A,s); // posicion radio
            A = join_rows(A,v); // velocidad radio
            A = join_rows(A,a); //acceleraicon radio

    }
    
};

int main()
{  
/////////////////////////Declaracion del objeto encoder del tipo calculos ////////////////////////////////////////////////////////
    calculos encoder;

//////////////////////// Valores mandados a la clase de calculo ////////////////////////////////////////////////////////////////////
    mat phi(67,1),phip(67,1),phipp(67,1),s(67,1),v(67,1),a(67,1);
    encoder.phi=phi;
    encoder.phip=phip;
    encoder.phipp=phipp;
    encoder.s=s;
    encoder.v=v;
    encoder.a=a;

//////////////////////// Iniciando la funcion desarrollo de la clase calculos ////////////////////////////////////////////////////
    encoder.desarrollo();

//////////////////////// Impresion y guardado de la matriz resultante de la suma de los vectores ///////////////////////////////////////
    encoder.A.print("matriz: ");
    encoder.A.save("tabla.txt",arma_ascii);

    

	return 0;
} 
