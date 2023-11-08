#include <iostream>
using namespace std;

void fibonacci(int n) {
    if (n <= 0) {
        return; // Não faz nada para n <= 0
    } else if (n == 1) {
        cout << 0 << " "; // Imprime o primeiro termo
    } else if (n == 2) {
        cout << 0 << " " << 1 << " "; // Imprime o primeiro e o segundo termo
    } else {
        int pri_termo = 0;
        int seg_termo = 1;
        cout << pri_termo << " " << seg_termo << " "; // Imprime o primeiro e o segundo termo

        for (int i = 3; i <= n; i++) {
            int prox_termo = pri_termo + seg_termo;
            cout << prox_termo << " "; // Imprime o próximo termo
            pri_termo = seg_termo;
            seg_termo = prox_termo;
        }
    }
}

int main() {
    int n;
    cout << "Digite o número de termos da sequência de Fibonacci: ";
    cin >> n;
    cout << "Sequência de Fibonacci até o " << n << "º termo: ";
    fibonacci(n);
    cout << endl;
    return 0;
}
