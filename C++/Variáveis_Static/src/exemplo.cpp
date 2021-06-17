#include <iostream>
using namespace std;

int gerarID(){
  static int ID = 0;
  return ID++;
}

int main(int argc, char *argv[]){
  string nome;

  while(true){
    cout << "Digite seu nome: ";
    cin >> nome;
    cout << "ID gerado para o usuário: " << nome << ": " << gerarID() << "\n\n";
  }
  return 0;
}
