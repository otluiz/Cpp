/*
 * Grafos -> DFS (busca em profundidade)
 */

/* 
 * File:   grafo_lista.cpp
 * Author: otluix
 *
 * Created on 10 de Dezembro de 2019, 17:35
 */
#include <iostream>
#include <list>
#include <algorithm>
#include <stack>

using namespace std;

class Grafo{
    int V; // número de vértices
    list<int> *adj; // ponteiro para um array contendo as listas de adjacências
public:
    Grafo(int V); // construtor
    void adicionarAresta(int v1, int v2); // adiciona uma aresta ao grafo

    // faz uma DFS a partir de um vértice
    void dfs(int v);
};

Grafo::Grafo(int V){
    this->V = V; // atribui o número de vértices
    adj = new list<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2){
    // adiciona vértice v2 à lista de vértices adjacentes de v1
    adj[v1].push_back(v2);
}

void Grafo::dfs(int v){
    stack<int> pilha; // estrutura de dados auxiliar
    bool visitados[V]; // vetor de visitados
    
    // marca todos como não visitados, a medida que visita marca como true
    for(int i = 0; i  < V; i++){ visitados[i] = false; }
    
    while(true){
        if(!visitados[v]){
            cout << "Visitando vértice " << v << " ...\n";
            visitados[v] = true; // marca como visitado
            pilha.push(v); // insere "v" na pilha
        }
        bool achou = false;
        list<int>::iterator it;
        
        // busca por um vizinho não visitado
        for(it = adj[v].begin(); it != adj[v].end(); it++){
            if(!visitados[*it]){
                achou = true;
                break;
            }
        }
        
        if(achou) v = *it; // atualiza o "v"
        else{
            // se todos os vizinhos estão visitados ou não existem vizinhos
            // remove da pilha
            pilha.pop();
            
            // se a pilha ficar vazia, então terminou a busca
            if(pilha.empty()) break;
            
            // se chegou aqui, é porque pode pegar elemento do topo
            v = pilha.top();
        }
    }
}


int main(int argc, char** argv) {
    // criando um grafo de 8 vértices
    int V = 8;
    
    Grafo grafo(V);
   
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 2);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(1, 4);
    grafo.adicionarAresta(2, 5);
    grafo.adicionarAresta(2, 6);
    grafo.adicionarAresta(6, 7);
 
    grafo.dfs(0); // chama a função para o grafo desde a raiz
    
    return 0;
}

/* Estrutura do Grafo implementada acima
 *              (0)
 *            /     \
 *         (1)       (2)
 *         / \       / \
 *       (3)  (4)  (5)  (6)
 *                        \
 *                        (7)
 */