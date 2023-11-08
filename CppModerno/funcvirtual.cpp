#include <iostream>
using namespace std; 

class Mae{
public:
  virtual void mensagem(){ cout << "eu soi a mãe" << '\n';}
};

class Filha : public Mae{
public:
  void mensagem(){ cout << "eu soi a filha" << '\n';}
};

class Neta : public Filha {
public:
  void mensagem(){ cout << "eu soi a neta" << '\n';}
};

void responde(Mae *m){ m->mensagem(); }

int main() { 

  Mae m;
  Filha f;
  Neta n;

  m.mensagem();
  f.mensagem();
  n.mensagem();

  cout << "-----------------------" << '\n';

  responde( &m ); 
  responde( &f );
  responde( &n );
  
  return 0; 
} 
