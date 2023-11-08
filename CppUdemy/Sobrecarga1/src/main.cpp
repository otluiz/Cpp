//////////// Sobrecarga do operador+  //////////////////////

#include <iostream>
#include <string.h>
using namespace std;

void showMessage(const char* str)
{ cout << str << endl; }

int main(int argc, char* argv[])
{
  string str = "Marcos";

  cout << "String: " << str << endl;
  // cout << "Tamanho: " << str.length() << endl;
  // cout << str.at(1) << endl; //// retira a segunda letra da string Marcos Castro

  //str.append(" castr"); ////////////// adiciona ao final da string "str" o nome " castro"
  //  str.push_back('o');   ////////////// adiciona a letra 'o' ao final da string 'castr'

  // insert(0, "castro");
  str.insert(str.size(), " castro"); //// insere a partir de size()
  // str.erase(7, str.size());     //// vai apagar a partir da posição 7
  
  cout << "Nome completo: " << str << endl;
  // str.erase(0, str.size());
  //str.clear();
  // if(str.empty())
  //   cout << "String vazia!!" << endl;
  // else
  //   cout << "String não vazia!!" << endl;
  // //showMessage(str.c_str());
  // str.replace(0, 2, "castro");
  //cout << "Nova string: " << str << endl;

  size_t achou = str.find("Mar");
  if(achou != string::npos)
    cout << "Achou a substring!!" << endl;
  else
    cout << "Substrin não encontrada" << endl;

  // string my_str;
  // cout << "Digite seu nome: ";
  // getline(cin, my_str);
  // cout << "Nome digitado: " << my_str << endl;

  str += " castro";
  return 0;
}
