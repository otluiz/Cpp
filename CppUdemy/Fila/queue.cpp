/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queue.cpp
 * Author: otluix
 *
 * Created on 10 de Dezembro de 2019, 09:55
 */

#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    queue<int> fila;
    // inserirndo na fila
    fila.push(10);
    fila.push(20);
    fila.push(30);
    // fila: 10 20 30
    
    // mostrando o último elemento
    cout << "\nÚltimo elemento: " << fila.back() << endl;
    
    if(fila.empty()) 
        cout << "\nFIla vazia!!\n";
    else 
        cout << "\nFila Nâo vazia!!\n";
    
    cout << endl;
    
    cout << "\nPrimeiro elemento: " << fila.front() << endl;
    cout << "\nMostrando todos os elementos: ";
    while(!fila.empty()){
       int e = fila.front();
       cout << e << " ";
       fila.pop(); // remove elemento do início
    }
    

    // inserindo novamente
    int i = 10;
    while(i < 51){
        fila.push(i);
        i = i + 10;
    }
    
    cout << "\nTamanho da fila: " << fila.size() << endl;
    cout << endl;    
    
    return 0;
}

