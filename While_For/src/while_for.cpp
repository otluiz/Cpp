/*
 * while_for.cpp
 *
 *  Created on: 5 de set de 2019
 *      Author: otluix
 */
#include <iostream>
using namespace std;

int main(int argc, char **argv) {

	int n = 1, i = 1, j = 100, soma = 0;
	/*
	while (n <= 100){
		if (n % 2 != 0){
			n++;
			continue;
		}
		cout << n << endl;
		n++;

	}
	*/

	for (; i < 100; i++, j--){ // foi omitida a primeira parte do for
		soma = i + j;
		cout << i << " " << j << " " << "Soma  = " << soma << endl;
	}
	return 0;
}




