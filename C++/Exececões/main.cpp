/* 
 * File:   main.cpp
 * Author: otluix
 *
 * Created on 24 de Outubro de 2019, 19:04
 */

#include <cstdlib>
#include <iostream>

using namespace std;

double divisao(double n1, double n2){
    if(n2 == 0) throw "Divisão por zero!!\n";
    return n1 / n2;
}

int fat(int n){
    if(n < 0) throw "Número negativo!!";
    if(n < 2) return 1;
    return n * fat(n -1);
}

/*
 * Utilizamos as funções Try - Catch - Throw
 */
int main(int argc, char** argv) {

    try{
        cout << "Fatorial de 5: " << fat(5) << endl;
        //cout << "Fatorial de -5: " << fat(-5) << endl;
        cout << "Dividindo 10/0 = " << divisao(10,0) << endl;
    }
    catch(const char* erro){
        cerr << "Erro: " << erro << endl;
    }
    catch(...){
        cerr << "Erro inesperado.\n";
    }
    
    
    return 0;
}

