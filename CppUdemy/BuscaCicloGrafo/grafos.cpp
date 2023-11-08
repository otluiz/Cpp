/*
 * Este algoritmo busca por arestas que formam ciclos, em um grafo
 * A filosofia que está por trás é a Union-Find, ou seja através de uma função
 * de busca (find) para descobrir se dois vértices têm uma aresta entre eles
 * e se esta há outras arestas para aqueles vértices que formariam ciclo. 
 */

/* 
 * File:   grafos.cpp
 * Author: otluix
 *
 * Created on 11 de Dezembro de 2019, 09:58
 */

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

/*
 *  UNION - FIND
 */

// função que busca o subconjunto de um elemento "v"
int buscar(int subset[], int v){
    
    if(subset[v] == -1) return v; // se = -1 não há aresta
    return buscar(subset, subset[v]); // continua com uma busca recursiva
}

// função para unir dois subconjuntos como conjuntos de um único elemento
void unir(int subset[], int v1, int v2){
    
    int v1_set = buscar(subset, v1);
    int v2_set = buscar(subset, v2);
    subset[v1_set] = v2_set; // une uma aresta a outra
}

int tem_ciclo(int grafo[3][3]){
    
    int * subset = (int*)malloc(3 * sizeof(int));
    
    // inicializa todos os subconjuntos como conjuntos de um único elemento
    memset(subset, -1, sizeof(int) * 3);
    
    for(int i = 0; i < 3; i++){
        
        for(int j = i; j < 3; j++){
            
            if(grafo[i][j] == 1){
                int v1 = buscar(subset, i);
                int v2 = buscar(subset, j);
                
                if(v1 == v2) return 1;
                else unir(subset, v1, v2);
            }
        }
    }
    
    return 0;
}


int main(int argc, char** argv) {

    int grafo[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    
    grafo[0][1] = 1;
    grafo[1][0] = 1;
    grafo[1][2] = 1;
    grafo[2][1] = 1;
    grafo[0][2] = 1;
    grafo[2][0] = 1;
           
    if(tem_ciclo(grafo)) cout << "O grafo tem ciclo";
    else cout << "O grafo NÃO tem ciclo";
    
    
    return 0;
}

