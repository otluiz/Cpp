/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: otluix
 *
 * Created on 16 de Outubro de 2019, 12:30
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int quad(int num = 1) { return num * num; }

/*
 * 
 */
int main(int argc, char** argv) {

    int num = 10;
    /*
     Caso não for passado nenhum parâmtro a função quad() utilizará o 1 declarado
     * como se fosse um parâmetro opcional
     */
    
    cout << "Quadrado: " << quad() << endl;
    cout << "Quadrado: " << quad(num) << endl;
    
    return 0;
}

