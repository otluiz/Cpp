#include <stdio.h>
#include <iostream>
using namespace std;


void getArraySize ( int arr[], int len )
{ printf("Comprimento array com 'sizeof': %d\n", len); }

void getArrayElements( int arr[], size_t len) {
  for (size_t i = 0; i < len; ++i) // size_t para indexar
    cout << arr[i] << " ";
  cout << "\nContando o array com 'size_t': " << len << "\n";
}
  

int main(int argc, char *argv[])
{
  int arr[] = {1,2,3,4,5,6};
  int len = sizeof arr /sizeof *arr; // will return the size of array
 
  getArraySize( arr, len );
  getArrayElements( arr, len );



  cout << endl;
  return 0;
}
