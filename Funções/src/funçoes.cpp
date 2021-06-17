/*
 * funçoes.cpp
 *
 *  Created on: 5 de set de 2019
 *      Author: otluix
 */

#include <iostream>
using namespace std;

bool par (int num);
int soma (int n1, int n2);
int soma (int n1, int n2, int n3);

int main(int argc, char **argv) {
/*
	int n;

	cout << "Digite um número: " << endl;
	cin >> n;

	if (par(n))
		cout << "O número " << n << " é par!" << endl;
	else
		cout << "O número " << n << "é impar!" << endl;
*/
	cout << soma(1, 2) << endl;
	cout << soma(1, 2, 3) << endl;

	return 0;
}

bool par (int num){
	if (num % 2 == 0)
		return true;
	return false;
}

int soma (int n1, int n2){
	return n1 + n2;
}

int soma (int n1, int n2, int n3){
	return n1 + n2 + n3;
}
