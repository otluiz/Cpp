#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

void imprime_vetor(int vetor[TAM], int topo){

  int cont = 0;
  cout << "\n";
 
  while(cont < TAM){
    cout << vetor[cont] << " - ";
    cont++;
  }

  cout << "Topo" << topo << endl;
}

bool pilha_vazia(int topo){
  if (topo == -1) {return true;}
  else{return false;}
}

bool pilha_cheia(int topo){
  if (topo == TAM - 1) {return true;}
  else {return false;}
}

int pilha_tamanho(int topo){
  return topo + 1;
}

int pilha_get(int pilha[TAM], int *topo){
  if (pilha_vazia(*topo)){
    cout << "A pilha está vazia" << endl;
    return 0;
  }
  else{
    return pilha[*topo];
  }
}

void pilha_push(int pilha[TAM], int valor, int *topo){
 // Caso não possa mais colocar
  if (pilha_cheia(*topo)){
    cout << "Pilha cheia!" << endl;
  }else{
    *topo = *topo + 1;
    pilha[*topo] = valor;
  }
}

void pilha_pop(int pilha[TAM], int *topo){

  if (pilha_vazia(*topo)) {
    cout << "Pilha vazia" << endl;
  }
  else{
    cout << "Valor Removido:" << pilha[*topo] << endl;
    pilha[*topo] = 0;
    *topo = *topo - 1;
  }
}

void pilha_construtor(int pilha[TAM], int *topo){

  //Coloca o topo negativo para indicar pilha vazia
  *topo = -1;
  
  //contador auxiliar
  int cont;

  for(cont = 0; cont < TAM; cont++){
    pilha[cont] = 0;
  }
  
}

int main(){

  int pilha[TAM];
 
  int topo = -1, valorRetirado;  // topo da pilha

  pilha_construtor(pilha, &topo);
  
  imprime_vetor(pilha, topo);

  // if (pilha_vazia(topo)){cout << "Pilha está vazia";}
  
  pilha_push(pilha, 5, &topo);
  imprime_vetor(pilha, topo);

  cout << "ùltimo valor da pilha= " << pilha_get(pilha, &topo) << endl;
  cout << "tamanho da pilha= "<< pilha_tamanho(topo) << endl;
  
  pilha_push(pilha, 7, &topo);
  pilha_push(pilha, 13, &topo);
  pilha_push(pilha, 14, &topo);
  pilha_push(pilha, 15, &topo);
  pilha_push(pilha, 16, &topo);
  pilha_push(pilha, 17, &topo);
  pilha_push(pilha, 18, &topo);
  pilha_push(pilha, 19, &topo);
  pilha_push(pilha, 20, &topo);


  imprime_vetor(pilha, topo);

  pilha_pop(pilha, &topo);
  imprime_vetor(pilha, topo);

}
