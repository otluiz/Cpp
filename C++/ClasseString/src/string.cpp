#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){

  string str = "othon luiz";

  cout << "String: " << str << endl;
  cout << "Tamanho: " << str.length() << endl;
  cout << str.at(1) << endl;
  // cout << str.back() << endl;
  // cout << str.front() << endl;
  str.append(" teixeira");
  str.insert(str.size()," de Oliveira") << "Nome completo: " << str << endl;

  return 0;

}
