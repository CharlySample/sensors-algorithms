// Este programa corresponde al ejercicio de sensores del dia 14 de agosto del 2018.
#include <iostream>
#include <cmath>

//Libreria estandar
using namespace std;

int main()
{
	// Declaracion de la variable a utilizar.
    float y = 0.0;

    // Iniciacion del ciclo for requerido para realizar las operaciones necesarias.
	for (float x = 0.0; x <= 20.0; x+=0.1)
	{
		// Operacion propuesta. 
		y = 5 + 10*(x) - 2*pow((x),2) + 3*(pow(x,3)) - 4*(pow(x,4));

		//Impresion ciclica del valor de y.
		cout << y << endl;
	}
	return 0;
}