##
## Classe Perceptron para classificar dados simples
##

#include <iostream>
using namespace std;

class Perceptron{
public:
  float[] weights;

  //Constructor
  Perceptron(){
    for(int i; i < weights.lenght; ++i){
      weights[i] = random(-1, 1);
    }
  }
};


int main(int argc, char* argv[]){
 
  Percptron p[2];
}
