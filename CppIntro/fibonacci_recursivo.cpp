#include <iostream>
#include <vector>

int fibonacci(int n, std::vector<int>& memo) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        if (memo[n] == -1) {
            memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
        }
        return memo[n];
    }
}

int main() {
    int n;

    std::cout << "Digite o número de termos da sequência de Fibonacci: ";
    std::cin >> n;

    std::vector<int> memo(n + 1, -1); // Inicializa o vetor de memoização com -1

    std::cout << "Sequência de Fibonacci até o " << n << "º termo: ";

    for (int i = 1; i <= n; ++i) {
        std::cout << fibonacci(i, memo) << " ";
    }

    std::cout << std::endl;
    return 0;
}
