/*
 * Implementando um algoritmo a partir do seu psudocodigo
 * O presente algoritmo será recursivo e implementa o problema
 * do troco a partir de um nota (cédula)
 recursivechange(money, coins)
 if (money = 0): return 0
 MinNumCoins <- infinite
 for i from 1 to |coins|:
 if money >= coin(i):
   NumCoins <- Recursivechange(money - coin(i), coins)
    if NumCoins + 1 < MinNumCoins:
      MinNumCoins <- NumCoins + 1
      return MinNumCoins
 
*/

#include <iostream>
#include <limits>

using namespace std;

recursiveChange(int money, int &coins){
  if (money == 0) return 0;
  if (money > coins){
    numCoins = recursiveChange( money - coins, coins){
      if (numCoins + 1 < minNumCoins)
	minNumCoins = numCoins + 1;
    }
  }
  return minNumCoins; //int minNumCoins;
}

int main(int argc, char *argv[])
{
  int coins [6] = { 50, 20, 10, 5, 1 };
  int minNumCoins = numeric_limits<int>::max();

recursiveChange(100, coins);

  return 0;
}
