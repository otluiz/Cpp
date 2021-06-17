/*
 * main.cpp
 *
 *  Created on: 7 de set de 2019
 *      Author: otluix
 */
#include <iostream>
using namespace std;

int main(int argc, char **argv) {

	int array[] = {1,2,3,4,5};
	int *parray = &array[0]; //armazena o 1º endereço de memória de array

	//cout << &array[0] << endl;
	cout << array[1] << endl; // mostrará o 2º elemento de 'array'
	cout << *(parray +1) << endl; // mostrará o 2º elemento apontado por 'array'


	return 0;
}




