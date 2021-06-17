// /*
//  * pilha.cpp
//  *
//  *  Created on: 2 de out de 2019
//  *      Author: otluix
//  */

#include <iostream>
#include <vector>
#include "pilha.h"

using namespace std;

Pilha::Pilha(){
		vet = new int[100];
		max_tam = 99;
		topo = -1; //terá que incrementar antes de usar a pila ex: ++topo
}
Pilha::~Pilha(){
		delete[] vet;
}
void Pilha::empilhar(int e){
		if(topo == max_tam) cout << "Pilha cheia. Sorry." << endl;
		else vet[++topo] = e; //e.vet[++topo];}  vai ser zero no 1º elemento
}
void Pilha::desempilhar(){
		if(topo == -1) cout << "Pilha vazia. Sorry!" << endl;
		else topo --;
}

int Pilha::getTopo() {
		if(topo != -1) return vet[topo];
		else return -1;
}

int Pilha::vazia(){ return (topo == -1); }


