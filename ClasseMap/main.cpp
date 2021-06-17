/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: otluix
 *
 * Created on 9 de Dezembro de 2019, 23:46
 */
#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

/*
 * A classe Map associa uma chave a um valor
 */
int main(int argc, char** argv) {

    map<int, string> mapa;
    
    mapa[1] = "joão";
    mapa[2] = "maria";
    mapa[3] = "pedro";
    
    // alterando o valor associado a um chave
    mapa.at(1) = "carol";
    
    // mapa.clear();
    
    if(mapa.empty()) 
        cout << "Mapa vazio!!\n" << endl;
    else
        cout << "Mapa não vazio!!\n" << endl;
    
    if(mapa.count(4) > 0) 
        cout << "4 é elemento do Mapa!!\n" << endl;
    else
        cout << "4 não é elemento do Mapa!!\n" << endl;
   
    // mostrando todos os elementos
    map<int, string>::iterator it;
    for(it = mapa.begin(); it != mapa.end(); it++){
        cout << "A chave " << it->first << " => "  << it->second << endl;
    }
    
    it = mapa.find(2); // procura o elemento cuja chave é '2'
    mapa.erase(it); // exclui o elemento passado ao iterador
    
    cout << endl;
    
    // verificando se uma chave existe
    if(mapa.find(2) == mapa.end())
        cout << "\nChave 2 Não existe!\n";
    else
        cout << "\nChave 2 existe!\n\n";
    
    
    it = mapa.begin();
    mapa.insert(pair<int, string>(2, "maria")); //insere novamente a chave 2
   
    mapa[4] = "Othon"; // insere uma chave que não existe, o map adiciona
     
    for(it = mapa.begin(); it != mapa.end(); it++){
        cout << "A chave " << it->first << " => "  << it->second << endl;
    }
    
    // utilizando multimap
    multimap<int, string> mm;
    
    mm.insert(pair<int, string>(1, "python 2"));
    mm.insert(pair<int, string>(1, "python 3"));
    mm.insert(pair<int, string>(2, "C"));
    mm.insert(pair<int, string>(2, "C++"));
    mm.insert(pair<int, string>(3, "ruby"));
    
    multimap<int, string>::iterator it2 = mm.begin();
    
    cout << endl;
    
    while(it2 != mm.end()){
        cout << it2->first << " => " << it2->second << endl;
        it2++;
    }
   
    
    return 0;
}

