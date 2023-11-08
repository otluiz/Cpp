 /* pilha.h */

 /* Created on: 2 de out de 2019 */
 /* Author: otluix */


#ifndef PILHA_H_
#define PILHA_H_

class Pilha{
private:
	int* vet;
	int max_tam;
	int topo;

public:
	Pilha();
	~Pilha();
	void empilhar(int e);
	void desempilhar();
	int getTopo();
	int vazia();
};



#endif /* PILHA_H_ */
