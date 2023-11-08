#include <iostream>
#include "ligada.h"

int main(int argc, char *argv[])
{
  Lista<string> l;

  l.inserir_final("python");
  l.inserir_final("C++");
  l.inserir_final("ruby");
  l.inserir_inicio("haskell");

  l.mostrar();

  if(l.vazia()) cout << "Lista vazia..\n";
  else "Lista NÃO vazia..\n";

  cout << "\nRemovendo elementos do final...\n";

  l.remover();
  l.mostrar();

  cout << "Tamanho da lista: " << l.tamanho() << endl;
  
  return 0;
}
