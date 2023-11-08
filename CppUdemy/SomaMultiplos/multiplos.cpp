#include <iostream>
#include <list>
#include <vector>

using namespace std;

bool comparar(int& n1, int& n2){
  if(n1 == n2) 
    
  return false;
}

int checkNum(vector<int> &v, vector<int>::iterator &it){

  if (it == v.end() -1) // chegou ao fim do vetor
    cout << "Não encontrei duplicados..." << endl;

  if (*it == *(it + 1)){
    v.erase(it);
    return checkNum(v, it);
  }
  else{
    it++;
    return checkNum(v, it);
  }
}


int main(int argc, char *argv[])
{
  int soma3 = 0; // soma os múltiplos de 3
  int soma5 = 0; // soma os múltiplos de 5
  int somaD = 0; // soma os elementos não duplicados
  
  // definição de uma lista para armazenar os multiplos encontrados
  list<int> lst;
  vector<int> vec;

  // procura e insere na lista os multiplos de 3
  for(int i = 3; i < 100; i++){
    if(i % 3 == 0){ // teste se i é multiplo de 3
      lst.push_back(i); // insere o multiplo encontrado
      soma3 += i;
    }
  }
 
  // multiplos de 5
  for (int i = 5; i < 100; i++){
    if(i % 5 == 0){ // teste se i é multiplo de 5
      lst.push_back(i); // insere o multiplo encontrado
      soma5 += i;
    }
  }

  // ordena os elementos da lista
  cout << "ordenado os elementos da lista...\n";
  lst.sort();


  // mostrando os elementos da lista lst ordenadamente
  cout << "Mostrando os elementos da Lista ordenados\n" << endl;
  list<int>::iterator itL;
  // vector<int>::iterator elementosInicio = vec.begin();
  for(itL = lst.begin(); itL != lst.end(); itL++){
    cout << *itL << " ";
  }
  
  cout  << "soma dos elementos da lista: " << somaD << endl;
  cout << "tamanho da lista lst: " << lst.size()  << "\n";
  cout << "soma dos múltiplos de 3: " << soma3 << endl;
  cout << "soma dos múltiplos de 5: " << soma5 << endl;
  cout << "somando dos multiplos de 3 e 5: " << soma3 + soma5 << endl;
  return 0;
}
