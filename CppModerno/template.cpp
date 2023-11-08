#include <iostream>


using namespace std; 

template <class T>
class Stack{
  public:
  void pilha( T array, int max ){
      int i = {0};

      while ( i < max ){
	cout << "Os elementos do array são: " << array[i] << '\n';
	++i;
    }
  }
};

int main() { 

  Stack <const int *> s;
  //char marray[] = {'A', 'B', 'C', 'D', 'e', 'f'};
  //string marray[] = {"Avião", "Bola", "Casa", "Dado", "Escola", "Faculdade"};
  int marray[] = {1, 1, 2, 3, 5, 8, 11, 19};
  int max = sizeof (marray) / sizeof (marray[0]);
  int * pmarray = marray;
  s.pilha ( marray, max );

  
  return 0; 
} 
