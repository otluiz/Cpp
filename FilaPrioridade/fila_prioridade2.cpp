/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fila_prioridade2.cpp
 * Author: otluix
 *
 * Created on 10 de Dezembro de 2019, 11:12
 */
#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

class Pessoa{
private:
    string nome;
    int idade;
    
public:
    Pessoa(string nome, int idade){
        this->nome = nome;
        this->idade = idade;
    }
    string getNome() { return nome; }
    int getIdade() { return idade; }
};
struct CompIdade{
    bool operator()(Pessoa& p1, Pessoa&  p2){
        return p1.getIdade() < p2.getIdade();
    }
};
/*
 * 
 */
int main(int argc, char** argv) {

    /*
     * A struct CompIdade será usada como prioridade na Fila de Prioriadade
     * Enão, assim a ordenação se dará pela maior idade
     */
    priority_queue<Pessoa, vector<Pessoa>, CompIdade> pq;
    
    Pessoa p1("João", 40), p2("Maria", 55), p3("Pedro", 60);
    
    pq.push(p1);
    pq.push(p2);
    pq.push(p3);
    
    Pessoa pessoa = pq.top();
    
    cout << "Nome: " << pessoa.getNome() << endl;
    cout << "Idade: " << pessoa.getIdade() << endl;
    
    return 0;
}

