
#include <iostream>
#include <string.h>
#define MAX 10

using namespace std;

class Carro{
public:
  char nome[100];
  char cor[20];
  char placa[20];
  float preco;
};

// ordenação utilizando o algoritmo bubble sort
void ordena(Carro carros[], int tam){
  int i, j;
  Carro aux;

  for(i = tam; i >= 0; i--){

    for(j = 1; j <= i; j++){

	if(strcmp(carros[j - 1].nome, carros[j].nome) == 1){
	  aux = carros[j - 1];
	  carros[j - 1] = carros[j];
	  carros[j] = aux;
	}
      }
  }


}

int main (int argc, char* argv[]){

  Carro carros[MAX];
  int i = 0;

  while(true){
    char resp;
    cout << "Digite o nome do carro: ";
    cin >> carros[i].nome;
    cout << "Digite o nome do preço: ";
    cin >> carros[i].preco;
    cout << "Você deseja continuar? <S>sim ou <N>não: ";
    cin >> resp;
    if(resp != 's')
      break;
    cout << endl;
    i++;
  }
  cout << endl;
  cout << "Exibindo todos os carros...\n\n";
  cout << endl;
  
  for(int j = 0; j <= i; j++){
    cout << "Nome do carro: " << carros[j].nome << endl;
    cout << "Preço do carro: " << carros[j].preco << "\n\n";
    cout << endl;
  }

  ordena(carros, i); // ordena o vetor de carros
  cout << "Exibindo todos os carros ordenados pelo nome...\n\n";
  cout << endl;
  
  for(int j = 0; j <= i; j++){
    cout << "Nome do carro: " << carros[j].nome << endl;
    cout << "Preço do carro: " << carros[j].preco << "\n\n";
    cout << endl;
  }
  
    return 0;
}
