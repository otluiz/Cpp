/*
 * teste.cpp
 *
 *  Created on: 2 de out de 2019
 *      Author: otluix
 */

#include <iostream>
#include <vector>

using namespace std;

class Pilha{
private:
	int* vet;
	int max_tam;
	int topo;

public:
	Pilha(){
		vet = new int[100];
		max_tam = 99;
		topo = -1; //terá que incrementar antes de usar a pila ex: ++topo
	}
	~Pilha(){
		delete[] vet;
	}
	void empilhar(int e){
		if(topo == max_tam) cout << "Pilha cheia. Sorry." << endl;
		else vet[++topo] = e; //e.vet[++topo];}  vai ser zero no 1º elemento
	}
	void desemplihar(){
		if(topo == -1) cout << "Pilha vazia. Sorry!" << endl;
		else topo --;
	}

	int getTopo() {
		if(topo != -1) return vet[topo];
		else return -1;
	}

	int vazia(){ return (topo == -1); }
};


int main(int argc, char* argv[]){
	Pilha p;

	p.empilhar(10);
	p.empilhar(11);
	p.empilhar(12);
	p.desemplihar();

	cout << "Pilha vazia: " << p.vazia() << endl;
	cout << "Topo: " << p.getTopo() << endl;
	//p.desemplihar();

	return 0;
}


