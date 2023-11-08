/*
 * insertionSort.cpp
 *
 *  Created on: 15/04/2016
 *      Author: otluiz
 */
#include <iostream>
#include <cstdlib>
using namespace std;

const int TAM = 20;

void insertion(int v[], int n){
	int i, j, chave;
	for(i = 1; i <= (n-1); i++){
			chave = v[i];
			j = i -1;
			while((j >= 0) && (chave < v[j])){
				v[j+1] = v[j];
				j = j - 1;
			}
			v[j+1] = chave;
		}
}


int main(void){

	int v[] = {6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5};
	cout << "{6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5}" << endl;
	insertion(v, TAM);

	// imprimindo o vetor
	for(int r = 0; r < TAM; r++){
		cout << "posição:" << "v["<< r <<"] --> " << v[r] << endl;
	}

}
