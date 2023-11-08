#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int kadane(vector<int> &vet, int i = 0, int max_atual = 0, int max_total = -1)
{
  int tam_vet = vet.size();

  while (i < tam_vet) {
    max_atual = max_atual + vet[i];
    if (max_atual < 0)
      return kadane(vet, ++i, max_atual = 0, max_total);
    if (max_atual > max_total)
      return kadane(vet, ++i, max_atual, max_total = max_atual);
  }
  
  return max_total;
}

int main(int argc, char *argv[])
{
  vector<int> vet(5);
  // vetor: -2, 5, -1, 2, -3
  vet[0] = -2;
  vet[1] = 5;
  vet[2] = -1;
  vet[3] = 2;
  vet[4] = -3;

  cout << "Soma máxima: " << kadane(vet) << endl;
  
  return 0;
}

