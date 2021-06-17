/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: otluix
 *
 * Created on 24 de Outubro de 2019, 18:51
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    ifstream in("entrada.txt");
    char c;
    
    while(true){
        // A função fail() teste se ainda tem algum caracter para ser lido
        in >> c;
        if(in.fail()) break; // se encontrar falta de caracter falha e sai
        cout << c;
    }
    return 0;
}

