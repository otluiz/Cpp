/*
 * calculadora.cpp
 *
 *  Created on: 5 de set de 2019
 *      Author: otluix
 */

#include <iostream>
using namespace std;

int main(int argc, char **argv) {

	int num1, num2, resultado;
	float div;
	char op; //operação matemática

	cout << "Digite um numero: " << endl;
	cin >> num1;

	cout << "Digite outro numero" << endl;
	cin >> num2;

	cout << "Escolha a operação: " << endl;
	cin >> op;

	switch (op) {
		case '+':
			resultado = num1 + num2;
			cout << "Soma = " << resultado << endl;
			break;
		case '-':
					resultado = num1 - num2;
					cout << "Diferença = " << resultado << endl;
					break;
		case '*':
					resultado = num1 * num2;
					cout << "Produto = " << resultado << endl;
					break;
		case '/':
			if (num2 != 0){
					div = (float) num1 / num2;
					cout << "Divisão = " << div << endl;
					break;
			}
			else{
					cout << "Divisão por zero não pode!!" << endl;
					break;
			}
		default:
			cout << "operação inexistente" << endl;
			break;
	}
}



