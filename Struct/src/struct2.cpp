#include <iostream>

using namespace std;

struct Pessoa {
  //char nome[100];
  int idade;
  int numero_sorte;

  Pessoa(int idade){
    //    this -> nome = nome;
    this -> idade = idade;
  }

  Pessoa(int idade, int num_sorte){
    //    this -> nome = nome;
    this -> idade = idade;
    this -> numero_sorte = num_sorte;
  }

  void setIdade(int idade){ this -> idade = idade;}
  int getIdade(){ return idade;}

  void setNumero_sorte(int num){ this -> numero_sorte = num;}
  int getNumero_sorte(){ return numero_sorte;}
};

int main(int argc, char* argv[]){
    //struct pessoa
    //p.idade = 20;

    Pessoa p(20);
    Pessoa p2(20, 123456);

    cout << p.getIdade() << endl;
    cout << p2.getIdade() << " " << p2.getNumero_sorte() << endl;

    return 0;
}





  
  
