#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// Declaracion de variables.,
    float y = 0.0;

    // Primer ciclo for para imprimir numero.
	for (float x = -10.0; x < 10.0; x+=0.0001)
	{
		y = exp(x) * sin(x);
		//cout << y << endl;
	}



	return 0;
}