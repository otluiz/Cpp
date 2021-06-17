/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: otluix
 *
 * Created on 16 de Outubro de 2019, 14:08
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * Operador Ternário ?:
 * <condição> ? <operação 1> : <operação 2>;
 */
int main(int argc, char** argv) {

    int num = 10;
    /*
     
    if(num > 10) cout << "Número maior que 10" << endl;
    else cout << "Número menor ou igual a 10" << endl;
     */
    
    // Operador ternário é mais compacto
    num > 10 ? cout << "É maior" : cout << "É menor ou igual"  << "\n\n";
    return 0;
}

