/*
 * vetores.cpp
 *
 *  Created on: 6 de set de 2019
 *      Author: otluix
 */
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

	int i = 0;
	char nome[] = {'o', 't', 'h', 'o', 'n','\0'};
	char nomes[]= "Othon";
	/*
	 *
	 *	while(nome[i]){

		cout << nome[i++] << endl;
		}
	 */

	do{
		cout << nomes[i] << "\n";  //O \n é para imprimir uma letra/linha
	}
	while(nomes[i++]);

	return 0;
}




