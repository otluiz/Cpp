/*
 * Abrir um arquivo de saída e escreve nele
 */

/* 
 * File:   main.cpp
 * Author: otluix
 *
 * Created on 24 de Outubro de 2019, 18:46
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    ofstream output("saida.txt");
    output << "Aprendendo C++\n";
    output << "www.geeks.com.br\n";
    
    return 0;
}

