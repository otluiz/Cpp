/* Problema da Mochila 0/1 (Knaspack Problem)
 * 
 * * * Elementos - cada elemento possui um valor (v) e um peso (w).
 * * * Objetivo: maximizar o valor dos elementos colocados na mochila
 * * * Essa mochila tem um capacidade máxima: W
 * 
 * * Exemplo:
 *   elemento:  (peso, valor)
 *   elemento1: (2, 4)
 *   elemento2: (4, 8)
 *   elemento3: (3, 6)
 * 
 * * Um conjunto S de n elementos, cada elemento possui um peso wi e um valor/benefício bi,
 * * onde i = 1, 2, 3,..., n
 * 
 * * * Força bruta -> fazer todas as combinações: 2^n (problema exponencial)
 * * se n = 2 -> 2² = 4 combinações
 * * se n = 3 -> 2³ = 8 combinações
 * * se n = 4 -> 2⁴ = 16 combinações
 * * se n = 10 -> 2¹⁰ = 1024 combinações
 * 
 * * Análise assintótica por força bruta: O(2^n)
 * 
 * * * * * SOLUÇÃO * * * * *
 * * Fómula recursiva para os subproblemas:
 * * * V[k, w] =
 *               V[k - 1, w] se wk > w
 *               max { V[k - 1, w], V[k - 1, w - wk] + bk }, caso contrário
 * 
 * * * V[n + 1][W + 1]
 * para w = 0 até W
 *      V[0, w] = 0 // inicializa com zeros a primeira linha
 * para i = 1 até n
 *      V[i, 0] = 0 // inicializa com zeros a primeira coluna
 * 
 * para i = 1 até n
 *      para w = 1 até W
 *          se wt[i - 1] <= w
 *              se b[i - 1] + V[i - 1, w - wt[i - 1]] > V[i - 1, w]
 *                  V[i, w] = b[i -1] + V[i - 1, w - wt[i - 1]]
 *              senão
 *                  V[i, w] = V[i - 1, w]
 *          senão
 *              V[i, w] = V[i - 1, w]
 *
 */

/* 
 * File:   mochila.cpp
 * Author: otluix
 *
 * Created on 11 de Dezembro de 2019, 16:44
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int knapsack(int W, int wt[], int b[], int n){
    
    // tabela que será preenchida
    int V[n + 1][W + 1];
    
    // inicializando a primeira linha e a primeira coluna com 0
    for(int w = 0; w <= W; w++){ V[0][w] = 0; }
    for(int i = 1; i <= n; i++){ V[i][0] = 0; }
    
    for(int i = 1; i <= n; i++){
        
        for(int w = 1; w <= W; w++){
            
            // elemento pode fazer parte da solução
            if(wt[i - 1] <= w){
                
                // max...
                if((b[i - 1] + V[i - 1][w - wt[i - 1]]) > V[i - 1][w])
                    V[i][w] = b[i - 1] + V[i - 1][w - wt[i - 1]];
                else
                    V[i][w] = V[i - 1][w];
            }
            else
                V[i][w] = V[i - 1][w]; // w1 > w
        }
    }
    // retorna o valor máximo
    return V[n][W];
}

int main(int argc, char** argv) {

    // capacidade máxima da mochila: W
    int W = 20;
    
    // número de elementos
    int n = 5;
    
    // vetor com os valores (benefício) de cada elemento
    int b[] = {3, 5, 8, 4, 10};
    
    // vetor com os pesos de cada elemento
    int wt[] = {2, 4, 5, 3, 9};
    
    // obter o máximo valor que pode ser colocado na mochila
    int max_valor = knapsack(W, wt, b, n);
    
    cout << "Valor máximo: " << max_valor << endl;
    
    
    return 0;
}

