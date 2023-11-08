/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   teste.cpp
 * Author: otluix
 *
 * Created on 25 de Outubro de 2019, 10:55
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Trabalhando com a Classe Vector 
 */
class Ponto{
public:
    int x, y;
    
    Ponto(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int main(int argc, char** argv) {

    vector<Ponto*> vet;
    vector<Ponto*>::iterator it;
    
    Ponto* p1 = new Ponto(1, 2);
    Ponto* p2 = new Ponto(3, 4);
    
    vet.push_back(p1);
    vet.push_back(p2);
    
    for(it = vet.begin(); it != vet.end(); it++)
        cout << "(" << (*it)->x << ", " << (*it)->y << ")\n";
    
    
    /*
     * 6º trecho de código; trocando elementos entre vetores
     * 
     * 
    vector<int> a(2, 20);
    vector<int> b(3, 10);
    
    a.swap(b); // troca elementos entre os vetores
    
    for(unsigned int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    for(unsigned int i = 0; i < b.size(); i++)
        cout << b[i] << endl;
    */
    
    /*
     * 5º trecho de código, apagando elementos em posições definidas 
     * 
     vector<int> v(3);
    
    v[0]= 10;
    v[1]= 20;
    v[3]= 30;
    v.erase(v.end() - 1); // apaga o último elemento do vetor
    */
    
    
    /* 
     * 4º trecho de código comentado 
     * 
     * Iterator -> Um instrumento para percorrer o vetor
     * 
     
    vector<int>::iterator it = v.begin();
    // v.insert(it, 50); insere na primeira posição do vetor
    v.insert(it + 1, 40); // insere na segunda posição do vetor, no lugar do 20 (v[1]= 20)
    v.insert(it + 2, 50);
    for(unsigned int i = 0; i < v.size(); i++) 
        cout << v[i] << endl;
    */
    // cout << v.at(1) << endl;
    
  /*
   * 3º trecho de código comentado
   *    
    v[0] = 1;
    v[1] = 2;
    
    cout << v.back() << endl;
    cout << v.front() << endl;
  */  
  
  /*
   * 2º trecho comentado
   * a função push_back(n) insere n sempre no finalo do vetor
   *  
    v.push_back(1); cout << "Inseri 1" << endl;
    v.push_back(2); cout << "Inseri 2" << endl;
    v.push_back(3); cout << "Inseri 3" << endl;
    
    while(!v.empty()) v.pop_back(); // vai esvaziar o vetor até parar
    
    if(v.empty()) cout << "Vetor vazio!!\n";
    else cout << "Vetor NÃO vazio!!\n";
  */
    
  /* 
   * 1º trecho comentado
   * 
    if(v.empty()) cout << "vetor vazio!!\n";
    else cout << "vetor NÃO vazio!! \n";
    
    v.push_back(10); // insere um elemento no vetor que estava vazio.
    
    if(v.empty()) cout << "vetor vazio!!\n";
    else cout << "vetor NÃO vazio!! \n";
  */ 
        
    return 0;
}

