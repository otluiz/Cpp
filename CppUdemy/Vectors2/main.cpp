#include <iostream>
#include <vector>

using namespace std;

/*
 * TESTAR INÚMERAS MANEIRAS DE SE UTILIZAR A CLASSE VECTOR
*/

int main(int argc, char  *argv[]){
  // vector<int> v{10, 20, 30}; maneira 1
  vector<int> v;
  v.push_back(30);
  v.push_back(40);
  v.push_back(50);

  // O iterador "it" é para percorrer o vetor e listar seus componentes
  // O vetor v é inicializado: v.begin() e é percorrido até final: v.end()
  vector<int>::iterator it;
  it = v.begin();
  while(it < v.end()){
    cout << *it << endl;
    it++;
  }
  return 0;
}
