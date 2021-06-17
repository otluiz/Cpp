/*
 * Implementação do algoritmo de Krusal de Árvore geradora mínima em Grafos Cíclicos
 * 
 * O algoritmo de Kruskal serve para detectar ciclos, iremos utilizar o algoritmo
 * Union-Find que detecta ciclos em grafos não direcionados.
 */

/* 
 * File:   kruskal.cpp
 * Author: otluix
 *
 * Created on 11 de Dezembro de 2019, 11:53
 */
#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <string.h> // memset
#include <cstdlib>

using namespace std;

class Aresta{
    
    int vertice1, vertice2, peso;
    
public:
    Aresta(int v1, int v2, int peso){
        vertice1 = v1;
        vertice2 = v2;
        this->peso = peso;
    }
    
    int obterVertice1(){ return vertice1; }
    int obterVertice2(){ return vertice2; }
    int obterPeso(){ return peso; }
    
    // sobrescrita do operador "<" (do menor para o maior)
    bool operator < (const Aresta& aresta2) const { return (peso < aresta2.peso); }
};

class Grafo{
    
    int V; // número de vértices de um grafo
    vector<Aresta> arestas; // vetor de arestas
    
public:
    Grafo(int V) { this->V = V; }
    
    // função que adiciona uma aresta
    void adicionarAresta(int v1, int v2, int peso){
        Aresta aresta(v1, v2, peso);
        arestas.push_back(aresta);
    }
    
    // função que busca o subconjunto de um elemento "i"
    int buscar(int subset[], int i){
        
        if(subset[i] == -1) return i;
        return buscar(subset, subset[i]);
    }
    
    // função para unir dois subconjuntos em um único subconjunto
    void unir(int subset[], int v1, int v2){
        
        int v1_set = buscar(subset, v1);
        int v2_set = buscar(subset, v2);
        subset[v1_set] = v2_set;
    }
    
    // função que roda o algoritmo de Kruskal
    void kruskal(){
        
        vector<Aresta> arvore;
        int size_arestas = arestas.size();
        
        // ordena as arestas pelo menos peso
        sort(arestas.begin(), arestas.end());
        
        // aloca memória para criar "V" subconjuntos
        int * subset = new int[V];
        
        // inicializa todos os subconjuntos como conjuntos de um único elemento
        memset(subset, -1, sizeof(int) * V);
        
        for(int i = 0; i < size_arestas; i++){
            
            int v1 = buscar(subset, arestas[i].obterVertice1());
            int v2 = buscar(subset, arestas[i].obterVertice2());
            
            if(v1 != v2){
                // se forem diferentes é porque NÃO forma ciclo, insere no vetor
                arvore.push_back(arestas[i]);
                unir(subset, v1, v2); // faz a união 
            }
        }
        
        int size_arvore = arvore.size();
        
        // mostra as arestas selecionadas com seus respectivos pesos
        for(int i  =  0; i < size_arvore; i++){
            
            char v1 = 'A' + arvore[i].obterVertice1();
            char v2 = 'A' + arvore[i].obterVertice2();
            cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].obterPeso() << endl;
        }
                
                
    }
};

/*
 * 
 */
int main(int argc, char** argv) {

    Grafo g(7); // grafo
    
    // adiciona as arestas
    g.adicionarAresta(0, 1, 7);  // A -> B
    g.adicionarAresta(0, 3, 5);  // A -> D
    g.adicionarAresta(1, 2, 8);  // B -> C
    g.adicionarAresta(1, 4, 7);  // B -> E
    g.adicionarAresta(1, 3, 9);  // B -> D
    g.adicionarAresta(2, 4, 5);  // C -> E
    g.adicionarAresta(3, 4, 15); // D -> E
    g.adicionarAresta(3, 5, 6);  // D -> F
    g.adicionarAresta(4, 5, 8);  // E -> F
    g.adicionarAresta(4, 6, 9);  // E -> G
    g.adicionarAresta(5, 6, 11); // F -> G
    
    g.kruskal(); // roda o algoritmo de Kruskal
    
    return 0;
}

/**
 *  (A)           (C)
 *   |  \        /  |
 *   |   7      8   |
 *   |    \    /    |
 *   5      (B)     5
 *   |     /   \    |
 *   |   9      7   |
 *   |  /         \ |
 *   (D) ---15 ----(E)
 *      \         / | 
 *       6       /  |
 *        \     8   |
 *         \   /    |
 *          (F)     9
 *             \    | 
 *             11   |
 *               \  |
 *                (G)
 */              

