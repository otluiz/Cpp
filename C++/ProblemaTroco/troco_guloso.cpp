/*
 * quantidade de moedas "infinita"
 * M = {1, 2, 5, 10, 20} (moedas disponíveis)
 * N = 26 (troco)
 * 
 * Combinações:
 * {1, 5 ,5, 5, 10} -> 5 moedas (array de moedas possíveis_1 total: 26)
 * {1, 5, 10, 10} -> 4 moedas (array de moedas possíveis_2 total: 26)
 * {1, 5, 20} -> 3 moedas (array de moedas possíveis_3 total: 26)
 * 
 * N = 8 (troco)
 * M = {1, 4, 6} (meu array de moedas possíveis) 
 * 
 * início:
 * maior = 6
 * 8 - 6 = 2
 * maior = 4
 * maior = 1
 * 2 - 1 = 1
 * 1 - 1 = 1
 * troco: {1, 1, 6} -> total de moedas: 3 // veja que a estratégia gulosa não 
 *                                           foi a melhor
 * 
 * outra opção:
 * troco: {4, 4} -> total de moedas: 2 // melhor opção
 */

/* 
 * File:   troco_guloso.cpp
 * Author: otluix
 *
 * Created on 15 de Dezembro de 2019, 21:23
 */

#include <cstdlib>
#include <iostream>
#include <vector>
 
using namespace std;

/*
 *  Exemplo: 
 *  M = {1, 2, 5, 10, 20} Array de moedas
 *  qtd_moedas = qtd_moedas + aux_moedas
 *  troco = 26 -- Vamodar dar esse troco?
 * 
 *  aux_moedas = 26 / 20 = 1
 *  troco = 26 -1 * 20 = 26 - 20 = 6
 *  qtd_moedas = 1  (qtd_moedas = qtd_moedas + aux_moedas)
 * 
 *  aux_moedas = 6 / 10 = 0
 *  troco = troco - 0 = 6
 *  qtd_moedas = 1 + 0 = 1 (qtd_moedas = qtd_moedas + aux_moedas)
 * 
 *  aux_moedas = 6 / 5
 *  troco = 6 - 1 * 5 = 1
 *  qtd_moedas = 1 + 1 = 2 (qtd_moedas = qtd_moedas + aux_moedas) 
 *  
 *  aux_moedas = 1 / 2 = 0
 *  troco = 1
 *  qtd_moedas = 2  (qtd_moedas = qtd_moedas + aux_moedas)
 * 
 *  aux_moedas = 1 / 1 = 1
 *  troco = 1 - 1 * 1 = 0
 *  qtd_moedas = 2 + 1 = 3  (qtd_moedas = qtd_moedas + aux_moedas)
 */

int num_moedas(vector<int> &moedas, int troco){
    
    int qtd_moedas = 0;
    int tam_moedas = moedas.size();
    
    for(int i = tam_moedas - 1; i >= 0; i-- ){
        
        int aux_moedas = troco / moedas[i];
        troco -= aux_moedas * moedas[i];
        qtd_moedas += aux_moedas;
    }
    
    return qtd_moedas;
}

int main(int argc, char** argv) {

    vector<int> moedas;
    int troco;
    
    troco = 26;
    moedas.push_back(1);
    moedas.push_back(2);
    moedas.push_back(5);
    moedas.push_back(10);
    moedas.push_back(20);
    
    cout << "Número de moedas: " << num_moedas(moedas, troco);
           
    
    return 0;
}

