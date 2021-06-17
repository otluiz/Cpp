// Sobrecarga de índice de um vetor

#include <iostream>
#include <stdlib.h> // função exit()
using namespace std;

class Vetor{
private:
  int *vet, *vet_pos;
  int max;
public:
  Vetor(int max = 100){
    if(max < 0){
      cerr << "Erro: limite mínimo menor que 0." << endl;
      exit(1);
    }
    else if(max > 1000000){
      cerr << "Erro: limite máximo maior que 1.000.000." << endl;
      exit(1);
    }
    this->max = max;

    // alocar espaço
    vet = (int*)malloc(max *sizeof(int));
    vet_pos = (int*)malloc(max *sizeof(int));

    for(int i = 0; i < max; i++){ vet_pos[i] = 0; }
  }

  ~Vetor(){ delete []vet; }

  bool inserir(int e, int pos){
    if(pos >= 0 && pos < max){
      vet[pos] = e;
      vet_pos[pos] = 1; // existe elemento no vetor. 0 (zero) naõ existe
      return true;
    }
    return false;
  }

  int& operator[](int i){
    if(i < 0 || i >= max){ // menor que o mínimo ou maior que o máximo
      cerr << "Erro: acesso invalido ao vetor.\n";
      exit(1);
    }
    else if(vet_pos[i] == 0){
      cerr << "Erro: nesta posição não existe elemento.\n";
      exit(1);
    }
    return vet[i];
  }

  int tam(){
    int cont = 0;

    for(int i = 0; i < max; i++){
      if(vet_pos[i] == 1) cont++;
    }
    return cont;
  }
};

int main(int argc, char *argv[]){
  Vetor v(10);

  if(v.inserir(10, 0))
    cout << "Elemento inserido com sucesso!\n";
  else
    cout << "Erro ao inserir elemento.\n";

  if(v.inserir(11, 2))
    cout << "Elemento inserido com sucesso!\n";
  else
    cout << "Erro ao inserir elemento.\n";

  if(v.inserir(12, 10))
    cout << "Elemento inserido com sucesso!\n";
  else
    cout << "Erro ao inserir elemento.\n";

  cout << "Primeiro elemento: " << v[0] << endl;
  cout << "Segundo elemento: "  << v[1] << endl;
  cout << "Terceiro elemento: " << v[2] << endl;

  return 0;
}
