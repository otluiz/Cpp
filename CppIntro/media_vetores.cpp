#include <iostream>
#include <vector>

using namespace std;

double calcular_media(const vector<double>& valores) {
    double soma = 0.0;
    for (double valor : valores) {
        soma += valor;
    }
    double media = soma / valores.size();
    return media;
}

int main() {
    vector<double> notas = {7.5, 8.0, 6.5, 9.0};
    double media_notas = calcular_media(notas);
    cout << media_notas << endl;  // Saída: 7.75

    return 0;
}
