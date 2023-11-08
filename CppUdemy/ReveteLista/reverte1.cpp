// reverte os elementos de uma lista
#include <iostream>
#include <list>
using namespace std;

int main(int argc, char *argv[])
{
  list<int> mylist;

  for (int i = 1; i < 10; ++i) mylist.push_back(i);
  
  cout << "mylist contém:" << "\n";
  for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
    cout << ' ' << *it;
  cout << "\n";

  cout << "invertendo mylist"  << "\n";
  cout << "mylist contém:";
  //(it* -1);
  for (list<int>::iterator  it = mylist.end(); it != mylist.begin(); --it)
    cout << ' ' << *it;

  cout << "\n";

  return 0;
}
