#include <iostream>
#include <vector>
using namespace std;

void inverterVetor(vector<int>& vetor) {
  vector<int> pilha; // declarei um novo vetor chamado pilha

    // Empilhamento dos elementos do vetor
    for (int i = 0; i < vetor.size(); ++i) {
      pilha.push_back(vetor[i]); //empilho os números
    }

    // Desempilhamento para reverter a ordem dos números
    for (int i = 0; i < vetor.size(); ++i) {
        vetor[i] = pilha.back();
        pilha.pop_back(); // desempilho os números (invertendo a ordem)
    }
}

int main() {
    vector<int> vetor = {1, 2, 3, 4, 5};

    cout << "Vetor original: ";
    for (int i = 0; i < vetor.size(); ++i) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    inverterVetor(vetor);

    cout << "Vetor invertido: ";
    for (int i = 0; i < vetor.size(); ++i) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    return 0;
}
