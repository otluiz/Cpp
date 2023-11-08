// remove if exemplo
#include <iostream>
#include <algorithm>

using namespace std;

bool IsOdd (int i) { return ((i % 2) == 1); }

int main(int argc, char *argv[])
{
  int meuInsts[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  // bounds of range
  int *pbegin = meuInsts;
  int *pend = meuInsts+sizeof(meuInsts)/sizeof(int);

  pend = std::remove_if (pbegin, pend, IsOdd);   // 2 4 6 8 ? ? ? ? ?
                                                 // ^       ^
  std::cout << "the range contains:";
  for (int* p=pbegin; p!=pend; ++p)
    std::cout << ' ' << *p;
  std::cout << '\n'; 

    
  return 0;
}
