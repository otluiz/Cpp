#include <iostream>
#include <stdio.h>
using namespace std;


void cellCompete( int *arr, int days )
{
    int num = 0;
    size_t arr_size = sizeof(&arr); // pega o tamanho apontado pelo endereço de arr

    for( unsigned int i = 0; i < arr_size; i++ ) // outra forma, agora um inteiro sem sinal "unsigned"
        num = ( num << 1 ) | arr[i];

    for( int i = 0; i < days; i++ ) {
        num = num << 1;
        num = ( ( ( num << 1 ) ^ ( num >> 1 ) ) >> 1 ) & 0xFF;
    }

    for( size_t i = 0; i < arr_size; i++ ) // outra forma de controlar o array, agora a variável "i"
      arr[i] = ( (num >> 7) - i ) & 0x01;
}

int main()
{
  int arr[8] = { 1, 0, 0, 0, 0, 1, 0, 0};
  cellCompete( arr, 1 );

  //   arr_size = sizeof(&arr) / sizeof(&arr[0]); // aqui pode utilizar sizeof(&arr....)
    for( unsigned int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i )
      cout << arr[i] << " ";

    cout << endl;

    // testando o conteúdo indicado por "<<" e ">>"
    int num;
    for( unsigned int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i ) {
        num = num << 1;
        num = ( ( ( num << 1 ) ^ ( num >> 1 ) ) >> 1 ) & 0xFF;
    }
    cout << num << endl;
    
}
