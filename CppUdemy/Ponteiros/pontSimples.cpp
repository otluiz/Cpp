//simplePointer.cpp
#include <iostream>

using namespace std;

int main(){

  int* p = 0;
  int i = 1;
  p = &i;

  cout << "Adress of i = " << &i << endl;
  cout << "Adress of p = " << &p << endl;
  cout << "Value of p = " << p << endl;
  cout << "Value stored in p = " << *p << endl;
  cout << "Value stored in p = " << p[0] << endl;

  return 0;
}
