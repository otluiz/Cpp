// ordenar de forma decrescente
#include <iostream>
#include <array>
using namespace std;

void contagem(float flutuante[], int tam){
  bool ordem;
  for (int i = 0; i < tam; i++){
    if (flutuante[i] < flutuante[i+1]){
      ordem = false;
      break;
    }else{
      ordem = true;
    } 
  }
  if (ordem) { cout << "Está em ordem" << endl;}
}


int main(){
  float flutua [] = {3.2, 1.5, 4.7, 2.8, 5.1};
  int size = sizeof(flutua) / sizeof(flutua[0]);
  contagem(flutua,size);

  return 0;
}
