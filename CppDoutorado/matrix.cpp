#include <iostream>
///usr/include/eigen3/Eigen/...
#include <Eigen/Dense> 

using namespace std;
using namespace Eigen;

int main() {

  Matrix <float, 3,3> matrixA;
  matrixA.setZero();

  cout << matrixA << endl;

  cout<<"Estamos mudando a matriz"<< endl;

  matrixA(0,0)=2;
  matrixA(0,1)=3;
  matrixA(2,1)=5;

  cout <<matrixA<<endl;

return 0;
}
