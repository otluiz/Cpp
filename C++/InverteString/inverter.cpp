#include <iostream>
#include <string.h>
#define TAM 100

using namespace std;


int main(int argc, char *argv[])
{
  char nome[TAM]; // vetor de 100 caracteres para armazenar uma string
  int tamstr;     // guardará o tamanho da string
  char *p;        // ponteiro para percorrer a string
  char *pini;     // ponteiro para o início da string

  cout << "Digite uma string para inverter: " << endl;
  cin >> nome;

  tamstr = strlen(nome); // tamstr recebe o tamnho da string nome
  p = &nome[tamstr - 1]; // p recebe o endereço da última caracter de  nome
  pini = &nome[0];    ///// pini recebe o endereço do primeir0 caracter de nome

  do{
    cout << *p;// << endl;
    if (p == pini) break; // se o ponteiro p apontar para o início pára
    p--; // caso p não chegue ao inicio aidna vai subtraindo seu índice -1
  }while (true); // continua fazendo os passos anteriores

  cout << endl; 
      
  return 0;
}
