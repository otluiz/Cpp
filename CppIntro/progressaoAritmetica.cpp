#include <iostream>
using namespace std;

void progressaoAritmetica(int primeiroTermo, int razao, int quantidadeTermos) {
    int termoAtual = primeiroTermo;
    
    for (int i = 0; i < quantidadeTermos; i++) {
        cout << termoAtual << " ";
        termoAtual += razao;
    }
    
    cout << endl;
}

int main() {
  int p, r, q;
  cout << "Introduza o primeiro termo da progressão: " << "\n";
  cin >> p;

  cout << "Introduza a razão da progressão: " << "\n";
  cin >> r;

  cout << "Introduza quantidade de termos da progressão: " << "\n";
  cin >> q;
  
    int primeiroTermo = p;
    int razao = r;
    int quantidadeTermos = q;
    
    cout << "Progressão Aritmética sem utilizar vetores: ";
    progressaoAritmetica(primeiroTermo, razao, quantidadeTermos);
    
    return 0;
}
