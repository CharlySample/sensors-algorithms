#include <iostream>
#include <armadillo>
#include <fstream>
#define pi 3.14159

using namespace std;
using namespace arma;

class calculos
{
public:

    mat phi,phip,phipp,t,y,tabla,A,s,v,a,dato;
    int R = 360; // rpp
  //  int r = 2; // radio

////////////////////////// Funcion para el desarrollo de las formulas ////////////////////////
    void desarrollo()
    {
///////////////////////// Poner en 0 la posicion 0,0 de los vectores /////////////////////////////////////
        phi(0,0)=0.0;
        phip(0,0)=0.0;
        phipp(0,0)=0.0;
        t(0,0)=0.0;
        phipp(0,0)=0.0;
        //s(0,0)=0.0;
        //v(0,0)=0.0;
        //a(0,0)=0,0;

////////////////////////// Asignando valores al vector de tiempo y pulsos ///////////////////////
         //t << 0.0 << .5 << 1.25 << 1.5 << 2.0 << 2.75 << 3.5 << 4.5 << 5.0 << 7.25 << endr;
         //y  << 0.0 << 10 << 12 << 15 << 25 << 75 << 120 << 122 << 125 << 125 << endr;
//	t = trans(t);
//	y = trans(y);

for(int i=1;i<=100;i++)
      t(i,0) = i*2;
      t = trans(t);
  //    t.print();

for(int i=0;i<=100;i++)
      dato(i,0) = i;

///////////////////////// Ciclo for para asignar valores al vector de posicion angular///////////////////////
        for(int i=0 ;i<=100;i++)
            phi(i,0) = ((2*pi)/R)*y(0,i);

///////////////////////// Ciclo for para asignar valores al vector de velocidad angular///////////////////////
        for(int i=1;i<=100;i++)
            phip(i,0) = ((2*pi)/R)*((y(0,i)/(t(0,i)-t(0,i-1))));

///////////////////////// Ciclo for para asignar valores al vector de acceleracion angular //////////////////////
        for(int i=2;i<=100;i++)
            phipp(i,0) = (phip(i,0)/(t(0,i)-t(0,i-1)));

//////////////////////// Ciclo for para asignar valores al vector de posicion angular ////////////////////////////////////
        //for(int i=1;i<=85;i++)
          //  s(i,0) = ((2*pi*r)/R)*y(0,i);

//////////////////////// Ciclo for para asignar valores al vector de velocidad angular //////////////////////////////////////////
        //for(int i=1;i<=9;i++)
          //  v(i,0) = ((2*pi*r)/R)*((y(0,i)-y(0,i-1))/(t(0,i)-t(0,i-1)));

///////////////////////////// Ciclo for para asignar valores al vector de acceleracion angular //////////////////////////////////////////
        //for(int i=1;i<=9;i++)
           // a(i,0) = (v(i,0)-v(i-1,0))/(t(0,i)-t(0,i-1));

/////////////////////// Union de los vectores de tiempo, pulsos, posicion, velocidad y acceleracion ///////////////////////////
            A = join_rows(A,dato); //dato
            A = join_rows(A,trans(y)); // pulsos
            A = join_rows(A,trans(t)); // tiempo
	          //A = join_rows(A,dato); //pulso
            A = join_rows(A,phi); // posicion
            A = join_rows(A,phip); // velocidad
            A = join_rows(A,phipp); // acceleracion
            //A = join_rows(A,s); // posicion radio
            //A = join_rows(A,v); // velocidad radio
           // A = join_rows(A,a); //acceleraicon radio

    }

};

int main()
{
/////////////////////////Declaracion del objeto encoder del tipo calculos ////////////////////////////////////////////////////////
    calculos encoder;

//////////////////////// Valores mandados a la clase de calculo ////////////////////////////////////////////////////////////////////
    mat phi(101,1),phip(101,1),phipp(101,1),t(101,1),y(101,1),a,dato(101,1);//,s(86,1),v(10,1),a(10,1);
    encoder.phi=phi;
    encoder.phip=phip;
    encoder.phipp=phipp;
    encoder.dato=dato;
    encoder.t=t;

    a.load("tabla_master.txt", arma_ascii);
    for(int i=0;i<=100;i++)
{
//    t(i,0)=a(i,2);
    y(i,0)=a(i,1);
}
//    encoder.t=trans(t);
    encoder.y=trans(y);
    //encoder.y.print( );
    //encoder.t.print();


    //cout<< y<<endl;
    //encoder.a(i,0)=a(i,0);
    //encoder.s=s;
    //encoder.v=v;
    //encoder.a=a;

//////////////////////// Iniciando la funcion desarrollo de la clase calculos ////////////////////////////////////////////////////
    encoder.desarrollo();


//  A = join_rows(A,phip); // velocidad
//A = join_rows(A,phip); // velocidad
//////////////////////// Impresion y guardado de la matriz resultante de la suma de los vectores ///////////////////////////////////////
    encoder.A.print("matriz: ");
    encoder.A.save("tabla.txt",arma_ascii);



	return 0;
}
