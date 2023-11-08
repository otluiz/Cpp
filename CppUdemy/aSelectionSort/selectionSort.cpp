/* **************************************
 * Descrição desse algoritmo
 *
 * Este algorimo seleciona menor de todos e coloca-o na posição 0 (ou inicial).
 * Depois procura o segundo menor e coloca na posição 1 (seguinte a anterior).
 * E assim sucessivamente.
 * **********************************************
 *
 * selectionSort.cpp >>>> Selection Sort em C++ <<<<<<<<<<
 *
 *  Created on: 15/04/2016
 *      Author: otluiz
 */

#include <iostream>
#include <cstdlib>

using namespace std;

const int num = 10;

void trocaPos(int *v, int j, int min){
	int aux;
	//if ( v[j] < v[min] ){
		aux = v[min];
		v[min] = v[j];
		v[j] = aux;
	//}
	//return v[j];
}

int main(void){

	int i, j, min, v[num] = {6, 7, 8, 9, 0, 1, 2, 3, 4, 5};

	for(i = 0; i < (num-1); i++){
		min = i;
		for(j = (i+1); j < num; j++){
			if(v[j] < v[min])
				min = j;
		}
		trocaPos(v, i, min);
	}
	// imprimindo o vetor
	for(int r = 0; r < 10; r++){
		cout << "posição:" << "v["<< r <<"] --> " << v[r] << endl;
	}
	return 0;
}

