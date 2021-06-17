#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
  /* 
  cout << "Ordenando valores não duplicados";
  for(int k = 0; k < v.size(); k++)
    cout << v[k] << " ";
  return 0;
  */
}


int main(int argc, char *argv[])
{
  vector<int> v{2, 1, 3, 3, 5, 4, 4};
  cout << "O vetor tem os valores: \n";
  vector<int>::iterator it;
  it = v.begin();
  while(it < v.end()){
    cout << *it << endl;
    it++;
  }  
  
  vector<int>::iterator elementToStart = v.begin();
  checkNum(v, elementToStart);
  //  checkNum(v, 0); // chama a função que remove valores duplicados  
  sort(v.begin(), v.end()); // ordena os valores do vetor
  cout << "Os valores ordenados são: " << endl;
  //vector<int>::iterator it;
  it = v.begin();
  while(it < v.end()){
    cout << *it << endl;
    it++;
  }
  
  return 0;
}
