#include <iostream>
#include <armadillo>
#include "master.hpp"

using namespace std;
using namespace arma;

int main()
{
								mat k;
								mat kt;
								resorte o1;

								k << 0.45 << 0.4  << endr;

								kt = o1.serie(k);

								kt+= 0.7;

								cout << kt << endl;

								return 0;
}
