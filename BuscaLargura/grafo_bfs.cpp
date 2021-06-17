/*
 * Grafos -> Breadth-First Search - BFS (busca em lagura)
 * visitar: https://pt.wikipedia.org/wiki/Busca_em_largura
 */

/* 
 * File:   grafo_lista.cpp
 * Author: otluix
 *
 * Created on 10 de Dezembro de 2019, 17:35
 */
#include <iostream>
#include <list>
#include <queue> // fila  para usar a BFS

using namespace std;

class Grafo{
    int V; // número de vértices
    list<int> *adj; // ponteiro para um array contendo as listas de adjacências
public:
    Grafo(int V); // construtor
    void adicionarAresta(int v1, int v2); // adiciona uma aresta ao grafo

    // faz uma BFS a partir de um vértice
    void bfs(int v);
};

Grafo::Grafo(int V){
    this->V = V; // atribui o número de vértices
    adj = new list<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2){
    // adiciona vértice v2 à lista de vértices adjacentes de v1
    adj[v1].push_back(v2);
}

void Grafo::bfs(int v){
    queue<int> fila; // estrutura de dados auxiliar
    bool visitados[V]; // vetor de visitados
    
    // marca todos como não visitados, a medida que visita marca como true
    for(int i = 0; i  < V; i++){ visitados[i] = false; }
    
    cout << "Visitando vértice " << v << " ...\n";
    visitados[v] = true; // marca com visitado
    
    while(true){
        list<int>::iterator it;
        // busca por um vizinho não visitado
        for(it = adj[v].begin(); it != adj[v].end(); it++){
            if(!visitados[*it]){
                cout << "Visitando vértice " << *it << " ...\n";
                visitados[*it] = true; // marca como visitado
                fila.push(*it); // insere na fila
            }
        }
        
        if(!fila.empty()){
            v = fila.front();
            fila.pop();
        }
        else break;
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
 
    grafo.bfs(0); // chama a função para o grafo desde a raiz
    
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