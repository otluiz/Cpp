#include <iostream>
#include <list>
#include <vector>
using namespace std;

bool eh_impar (const int& val) { return (val % 2) == 1; }

bool eh_par (const int& val) { return (val % 2) == 0; }

bool eh_igual(list<int> lista)
  {
    vector<int> v;
    for (int const &c: lista)
      v.push_back(c);
    vector<int>::iterator start = v.begin();
    vector<int>::iterator end = v.end();
    //list<int>::iterator end = lista.end();
    //list<int>::iterator it = lista.begin();
    auto it = start + 1;
    //    it++;
    if (*start == *it) {
      return true;      
    }
    return false;  
  }

int main(int argc, char *argv[])
{
  list<int> mylist{1, 2, 4, 3, 5, 3, 6, 6, 8, 7, 55, 56, 44, 2, 5, 7};

  cout<< "Mostrando elementos da lista: " << endl;
  for (auto it = mylist.begin(); it != mylist.end(); ++it) {
    cout << *it << " ";
  }

  cout << "\nRemovendo só elementos ímpares..." << endl;
  mylist.remove_if(eh_impar);
  for (auto it = mylist.begin(); it != mylist.end(); ++it)
    cout << ' ' << *it;
  cout << endl;

  mylist = {1, 2, 4, 5, 3, 6, 8, 7, 55, 56, 44, 2, 5, 7};
  
  cout << "\nRemovendo só elementos pares..." << endl;
  mylist.remove_if(eh_par);
  for (auto it = mylist.begin(); it != mylist.end(); ++it)
    cout << ' ' << *it;
  cout << endl;

  mylist = {1, 2, 4, 5, 3, 6, 8, 7, 55, 56, 44, 2, 5, 7};

  cout <<"\nRemovendo só os elementos duplicados..." << endl;
  mylist.remove_if(mylist);
  for (auto it = mylist.begin(); it != mylist.end(); ++it)
    cout << *it << " ";
  cout << endl;
  
  
  return 0;
}
