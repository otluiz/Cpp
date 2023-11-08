/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   meuMain.cpp
 * Author: otluix
 *
 * Created on 16 de Outubro de 2019, 11:01
 */

#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

void showMessage(const char* str)
    {cout << str << endl;}

/*
 * 
 */
int main(int argc, char** argv) {

    string str = "Othon";
    //str.insert(str.size(), "Oliveira");
    
    cout << "Nome: " << str << endl;
    //str.append(" Oliveira");
    /*str.clear();
    if(str.empty()) 
        cout << "String vazia" << endl;
    else 
        cout << "String NÃO vazia!!" << endl;
    showMessage(str.c_str());
     */
    //str.replace(0, 2, "Oliveira");
    //cout << "Novo valor de str: " << str << endl;
    
    size_t achou = str.find("Oth");
    if(achou != string::npos) cout << "Achou a substring!!" << endl;
    else cout << "Substring não foi encontrada!!" << endl;
    
    /*
     * Utilizando a função getline() que reconhece os espaços em branco
     */
    //string meu_str;
    //cout << "Digite seu nome: " ;
    //getline(cin, meu_str);
    //cout << "Nome digitado: " << meu_str << endl;
    
    str += " Oliveira"; // funciona como a função append()
    cout << "Nome completo: " << str << endl;
    return 0;
}

