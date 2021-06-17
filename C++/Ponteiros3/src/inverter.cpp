/*
 * inverter.cpp
 *
 *  Created on: 7 de set de 2019
 *      Author: otluix
 *
 *     este programa inverte os caracteres entrados pelo usuário
 */
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char **argv) {

	char nome[100];
	int tam;
	char *p, *pini;

	cout << "Digite um nome: " << endl;
	cin >> nome;

	tam = strlen(nome); // tamanho da string
	p = &nome[tam -1];  // pega o último endereço e guarda no ponteiro p
	pini = &nome[0];    //  ||    primeiro ||        ||         ||     pini

	// loop para inverter uma string
	do{
		cout << *p;
		if (p == pini) break;
		p--;
	}while(true);

	cout << endl;

	return 0;

}




