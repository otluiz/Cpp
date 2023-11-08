//////////// Sobrecarga do operador+  //////////////////////

#include <iostream>
#include <string.h>

using namespace str;

class Complexo{
public:
  int real, imag;

  Complexo operator+(Complexo& c){
    this->real = real;
    this->imag = imag;

  }
