/*
 * Este algoritmo troca o elemento com seu vizinho (borbulhando), caso o elemento seja maior que este vizinho (se for em ordem
 * crescente).
 * E assim sucessivamente, "empurrando" o maior elemento até a última posição da sequência.
 * Na próxima iteração repetirá o procedimento sem a participação do último elemento.
 *
 * bubleSort.cpp >>>>> Implementação em C++ <<<<<<
 *
 *  Created on: 15/04/2016
 *      Author: otluiz
 */

#include <iostream>
#include <cstdlib>

using namespace std;

const int num = 20;

void trocaPos(int *v, int j){
	int aux;
	if ( v[j] > v[j+1] ){
		aux = v[j+1];
		v[j+1] = v[j];
		v[j] = aux;
	}
	//return v[j];
}



int main(void){

	int i, v[num] = {6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5};
	cout << "Vetor v[10] = [6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5]" << endl;
	//cin  >> num;

	//trocaPos(v, 3);
	//cout << v[3] << endl;

	for (i = num -1; i >= 1; i--){

		for(int j = 0; j < i; j++){
			trocaPos(v, j);

		}
	}
	// imprimindo o vetor
	for(int r = 0; r < 20; r++){
		cout << "posição:" << "v["<< r <<"] --> " << v[r] << endl;
	}
	return 0;
}
