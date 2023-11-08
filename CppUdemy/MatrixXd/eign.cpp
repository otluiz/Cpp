// A i single example for Eign
//******************************************************
//*** g++ -I /usr/local/include/eigen3 eign.cpp -o eign
//*****************************************************

#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using namespace std;

int main(){

  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  cout << m << endl;
  return (0);
}
