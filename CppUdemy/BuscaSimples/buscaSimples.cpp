#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
#define TAM 10

using namespace std;

void imprime_vetor(int vetor[TAM]){

 // auxiliar contador
 int cont;
 
 for(cont = 0; cont < TAM; cont ++)
      { cout << vetor[cont] << " - " ; }
}

int busca_simples (int vetor[TAM], int valorProcurado, int *posicaoEncontrada){

   // auxiliar contador
   int cont;

   // Verifica se o valor foi encontrado
   bool valorFoiEncontrado;
  
   //Procura na lista em buscca do valor
    for(cont = 0; cont < TAM; cont++){
      if(vetor[cont] == valorProcurado){
	valorFoiEncontrado = true;
	*posicaoEncontrada = cont;
      }
    }

    if (valorFoiEncontrado){ return 1; }
    else{ return -1; }

}

int main(){

    int vetor[TAM] = {1, 23, 44, 56, 63, 72, 84, 90, 98};
    int valorProcurado;
    int posicao, posicaoEncontrada;
    int cont;  // auxiliar contador

    imprime_vetor(vetor);

    printf("Qual o valor desejado?");
    scanf("%d", &valorProcurado);

    if (busca_simples(vetor, valorProcurado, &posicaoEncontrada) == 1){
      cout << "O valor foi encontrado na posição: " << posicaoEncontrada << endl;
    }else{
      cout << "Valor não encontrado!!" << endl;
    }

    return 0;
}
