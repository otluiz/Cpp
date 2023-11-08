/*
 * Sequência de Fibonacci até o n-ésimo temo,
 * foi criado uma função que faz os cálculos.
 * O enésimo termo é escolhido pelo usário.
 */
#include <iostream>
using namespace std;

int fibonacci(int n){
  if (n == 1) { return 0; } // retorna o primeiro termo
  else if (n == 2) { return 1; } // retorna o segundo termo
  else {
     int pri_termo = 0, seg_termo = 1, prox_termo;
     // cáculo dos próximos termos (prox_termo)
      for (int i = 3; i <= n; i++){
	prox_termo = pri_termo + seg_termo;
	pri_termo = seg_termo;
	seg_termo = prox_termo;
      }
    return prox_termo; // retorna o próximo termo
  }
}

int main() {
  
  int n;  
  cout << "Digite o número de termos da sequência de Fibonacci: ";
  cin >> n;
  cout << "O " << n << "º termo: ";
  
  cout << fibonacci(n) << "\n"; // chama a função fibonacci e passa n

  return 0; 
} 
