/* 
 * File:   kadame.cpp
 * Author: otluix
 *
 * Created on 11 de Dezembro de 2019, 14:39
 */

/*
 * Algoritmo Kadane -- ou soma máxima é o maior valor que se pode conseguir 
 * somando-se os números contíguos de uma sequência de número, positivos e negativos
 * Também conhecido como "Maximum Sum Subarray Problem"
 * Jay Kadane - 1977
 * 
 * Ex: seja o vetor A = {-2 ,5 ,-1 ,2 ,-3 }
 *  o subvetor B = { 5,-1 ,2 } => Soma Máxima = 6. 
 *  B possui soma máxima contígua pois entre os números 5 e 2
 *  contém o "-1" entre eles, de forma contígua.
 *  
 *  inicializando os totalizadores
 *  max_atual = 0, max_total = -1
 *  
 *  para i = 0 até i < tam_vet
 *  {
 *      max_atual = max_atual + vet[i]
 *      se max_atual < 0
 *          max_atual = 0
 * 
 *      se max_atual > max_total
 *          max_total = max_atual
 *  }
 *  imprima max_total
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void kadane(vector<int>& vet){
    
    int max_atual = 0, max_total = -1;
    int tam_vet = vet.size();
    
    for (int i = 0; i < tam_vet; i++){
        
        max_atual = max_atual + vet[i];
        
        if(max_atual < 0) max_atual = 0;
        if(max_atual > max_total) max_total = max_atual;
    }
    //imprima max_total
    cout << "Soma máxima: " << max_total << endl;
}


/*
 * 
 */
int main(int argc, char** argv) {

    vector<int> vet{2, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1};
    
    kadane(vet); // chama o a função Kadane
    
    return 0;
}

