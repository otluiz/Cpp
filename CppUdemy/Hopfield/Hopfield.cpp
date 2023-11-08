//
// Hopfield netword
// from: Othon Oliveira
//

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

class neuron{

protected:
  int activation;
  friend class network;

public:
  int weightv[4];
  neuron(){};
  neuron(int *j);
  int act(int, int*);
};

class network{
  
public:
  neuron nrn[4];
  int output[4];
  int theshold(int);
  void activation(int j[4]);
  network(int*, int*, int*, int*);
};

int main (int argc, char* argv[]){

  int pattn1 [] = {1,0,1,0};
  int wt1[] = {0, -3, 3, -3};
  int wt2[] = {-3, 0, -3, 3};
  int wt3[] = {3, -3, 0, -3};
  int wt4[] = {-3, 3, -3, 0};

  cout <<"\n This program is for a Hopfield Nerwork wit a single layer of";
  cout <<"\n Fully interconnected neurons. The network should recall the";
  cout <<"\n Patterns 1010 an 0101 correctly.\n";

  //crate the network by calling its contructor
  // The constructor call neuron contructor as many times as the number of
  // neurons in the nerwork
  network h1(wt1, wt2, wt3, wt4);

  // Present a pattern to the network and get the activation of the neurons
  h1.activation(pattn1);
  
  return 0;
}
