/*
 * Queue - FIFO - Fist In, Fist Out
 * Fila de Prioridade (Priority queue) -- para remover elementos de maior prioridade
 */

/* 
 * File:   fila_prioridade.cpp
 * Author: otluix
 *
 * Created on 10 de Dezembro de 2019, 10:29
 */

#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

/*
 * FOi comentada a função main para o outro arquivo (fila_prioridade2.cpp) funcionar

int main(int argc, char** argv) {

    priority_queue<int> pq; // Entende que os maiores valores devem ser mostrado primeiro
    //priority_queue<int, vector<int>, greater<int> > pq; // altera a ordem de prioridades
    pq.push(20);
    pq.push(15);
    pq.push(50);
    
    cout << "\nElemento do topo: " << pq.top() << endl;
    
    if(pq.empty())
        cout << "\nFila vazia!!\n";
    else
        cout << "\nFila NÃO vazia!!\n";
    
    cout << "\nTamanho da fila: " << pq.size() << endl;
    cout << "\nMostrando os elementos: ";
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        ///cout << "\nRemovendo elemento..." << endl;
        pq.pop();
    }
    
    
    
    return 0;
}
 */
