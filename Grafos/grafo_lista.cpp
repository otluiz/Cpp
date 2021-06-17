/*
 * Grafos -> Lista de adjacência
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
//#include <cstdlib>

using namespace std;

class Grafo{
    int V; // número de vértices
    list<int> *adj; // ponteiro para um array contendo as listas de adjacências
public:
    Grafo(int V); // construtor
    void adicionarAresta(int v1, int v2); // adiciona uma aresta ao grafo
    
 /*
  * obtém o grau de saída de um dado vértice
  * grau de saída é o número de arcos que saem de v
  */ 
    int obterGrauDeSaida(int v);
    
    bool existeVizinho(int v1, int v2); // verifica se v2 é vizinho de v1
};

Grafo::Grafo(int V){
    this->V = V; // atribui o número de vértices
    adj = new list<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2){
    // adiciona vértice v2 à lista de vértices adjacentes de v1
    adj[v1].push_back(v2);
}

int Grafo::obterGrauDeSaida(int v){ return adj[v].size(); }

bool Grafo::existeVizinho(int v1, int v2){
    if(find(adj[v1].begin(), adj[v2].end(), v2) != adj[v1].end())
        return true;
    return false;
}

int main(int argc, char** argv) {
    // criando um grafo de 4 vértices
    Grafo grafo(4);
   
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 3);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(3, 1);
    grafo.adicionarAresta(3, 2);
    
    // mostrando os graus de saída
    cout << "Grau de saída do vértice 1: " << grafo.obterGrauDeSaida(1);
    cout << "\nGrau de saída do vértice 3: " << grafo.obterGrauDeSaida(3);
    
    // verifica se existe vizinhos
    if(grafo.existeVizinho(0, 1))
        cout << "\n\n\1 é vizinho do 0";
    else
        cout << "\n\n1 NÃO é vizinho do 0";
    
    if(grafo.existeVizinho(0, 2))
        cout << "\n\n2 é vizinho do 0";
    else
        cout << "\n\n2 NÃO é vizinho do 0";
    
    return 0;
}

