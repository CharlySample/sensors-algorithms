#include <iostream>
#define ARMA_USE_LAPACK
#define ARMA_USE_BLAS
#define ARMA_DONT_USE_WRAPPER
#define ARMA_DONT_PRINT_ERRORS
#include <armadillo>

using namespace std;
using namespace arma;
using namespace lapack;

int main()
{
  mat A;

   A << (2) << (23.2131) <<endr
     << (.4) << (22) <<endr;

cout << inv(A) << endl;



return 0;
}
