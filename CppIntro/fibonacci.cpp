/* 
 Algoritmo Fibonnaci - ChatGPT
*/
#include <iostream>
using namespace std;

int main() {
    int n, first_term = 0, second_term = 1, next_term, counter = 1;

    cout << "Digite o número de termos da sequência de Fibonacci: ";
    cin >> n;

    cout << "Sequência de Fibonacci até o " << n << "º termo: ";

    while (counter <= n) {
        if (counter == 1) {
            cout << first_term << " ";
        } else if (counter == 2) {
            cout << second_term << " ";
        } else {
            next_term = first_term + second_term;
            first_term = second_term;
            second_term = next_term;
            cout << next_term << " ";
        }
        counter++;
    }

    cout << endl;
    return 0;
}

