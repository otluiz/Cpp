/*
 * Grafo é uma entidade composta de duas partes:
 *  Vétices (nós)
 *  Arestas (linhas)
 * 
 * Os nós são as "bolinhas" - entidades que você quer modelar
 * 
 * As arestas são as relações dessas entidades.
/* 
 * Ex: Uma pessoa pode ser um vértice, as amizades são as arestas
 
 *                    1680 km
 *  (São Paulo )<--------------->( Buenos Aires )
 * 
 * A Matriz de Adjacência é a primeira forma de representar um grafo que iremos
 * ter como contado. 
 * ex: 
 *   a b c d
 * a 0 0 1 0
 * b 0 0 0 1
 * c 1 1 0 1
 * d 0 1 1 0                                                           
 *                      
 *  -  Se tiver ligação é 1 (um)
 *  -  Se não tiver ligação é 0 (zero)
 * 
 * File:   grafo_matriz.cpp
 * Author: otluix
 *
 * Created on 10 de Dezembro de 2019, 16:58
 */
#include <iostream>
#include <cstdlib>

using namespace std;



int grafo[5][5] = {
//   a b c d e
    {0,0,1,0,0}, // a
    {0,0,1,0,0}, // b
    {1,1,0,1,1}, // c
    {0,0,1,0,0}, // d
    {0,0,1,1,0}  // e
};

bool tem_ligacao(int v1, int v2){
    if (grafo[v1][v2]) 
        return true;
    return false;        
}
/*
 * 

int main(int argc, char** argv) {

    cout << tem_ligacao(0, 2) << endl;
    
    return 0;
}

 */