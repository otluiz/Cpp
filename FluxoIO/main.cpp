/*
 * Abrir um arquivo para entrada
 * ler o conteúdo desse arquivo
 */

/* 
 * File:   main.cpp
 * Author: otluix
 *
 * Created on 24 de Outubro de 2019, 18:32
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    ifstream in ("entrada.txt"); // um objeto in do tipo ifstream
    
    string texto; // acumula a quantida de caracteres necessário
    char c = in.get(); // vai ler um caracter da entrada
    texto.push_back(c); // vai acumulando cada caracter na string 'texto'
    
    cout << "\nMostrando cada caracter: \n";
    while(in.good()){
        cout << c;
        c = in.get();
        texto.push_back(c);
    }
    return 0;
}

