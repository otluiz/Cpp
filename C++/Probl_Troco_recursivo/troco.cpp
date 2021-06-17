#include <iostream>
#include <list>

using namespace std;

int num_moedas(list<int>& moedas, int troco, int qtd_moedas = 0)
{
  //int tam_moedas = moedas.size();
  list<int>::iterator it = moedas.begin();
  while (it != moedas.end()) {
    int aux_moedas = troco /(int) moedas.begin();
    num_moedas(moedas, troco -= aux_moedas * *it, qtd_moedas += aux_moedas);
  }
  return qtd_moedas;
}



int main(int argc, char *argv[])
{
  list<int> moedas{1, 2, 5, 10, 20}; // moedas infinitas para dar troco
  list<int>::iterator it;
  int troco = 26;

  /*
  cout << "\nMostrando as moedas para troco: \n" ;
  for (auto it = lista.begin(); it != lista.end(); ++it)
    cout << *it << " ";
  */

  cout << "Número de moedas: " num_moedas(moedas, troco) <<  endl;
  return 0;
}

