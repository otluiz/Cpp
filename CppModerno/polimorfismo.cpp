#include <iostream>
using namespace std; 

class Pessoa{

public:
  int num(){
    return 10;
  }

  int num( int rg ){
    return 123456;
  }
};

class Turma : public Pessoa{

public:
  int num(){
    return 50;
  }

  int num( int num){
    return num;
  }
};


int main() { 

  Pessoa p;
  Turma t;

  cout << "num() de Pesso é: " << p.num() << '\n';
  cout << "num( int num) de Pessoa é: " << p.num(256) << '\n';
  cout << "num() de Turma é: " << t.num() << '\n';
  cout << "num( int num) de Turma é: " << p.num(128) << '\n';
 
  return 0; 
} 
