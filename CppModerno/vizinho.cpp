#include <iostream>
using namespace std; 

class Casa{
 public:
  string comp = "123";

 protected:
  char essid[5] = {'h', 'o', 'm', 'e', '\0'};

private:
  string passwd = "abc" + comp;

friend class Vizinho;

};

class Vizinho{

public:
  void controller(){
    Casa c;
    cout << "Olá vizinho, a REDE é: " << c.essid << '\n';
    cout << "E a senha dessa REDE é: " << c.passwd << '\n';
  }
};

int main() { 

  Vizinho v;
  v.controller();
 
  return 0; 
} 
