/*
 * teste.cpp
 *
 *  Created on: 2 de out de 2019
 *      Author: otluix
 */

#include <iostream>
#include "pilha.h"


using namespace std;

int main(int argc, char* argv[]){
	Pilha p;

	p.empilhar(10);
	p.empilhar(11);
	p.empilhar(12);
	p.desempilhar(); // sai o 12 >> fica o 11 no topo
	p.desempilhar(); // sai o 11 >> fica o 10 no topo
	//	p.desempilhar(); 
	cout << "Pilha vazia: " << p.vazia() << endl;
	cout << "Topo: " << p.getTopo() << endl;
	//p.desemplihar();

	return 0;
}


