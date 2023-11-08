/*
 * main.cpp
 *
 *  Created on: 5 de set de 2019
 *      Author: otluix
 */
#include <iostream>
#include "modulo_math.h"

using namespace std;

int main(int argc, char **argv) {

	int num = 55;
	//cout << "digite um número: " << endl;
	//cin >> num;
	cout << "Fatorial de " << num << ": " << fatorial(num)<< endl;
	cout << "Fibonacci de " << num << ": " << fibonacci(num) << endl;

	return 0;
}




