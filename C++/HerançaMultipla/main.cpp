/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: otluix
 *
 * Created on 16 de Outubro de 2019, 14:42
 */

#include <cstdlib>
#include <iostream>
using namespace std;

class Pai1{
public:
    void foo() { cout << "Oi, sou o Pai-1" << endl; }
};

class Pai2{
public:
    void foo(){ cout << "Oi, sou o Pai-2" << endl; }
};

class Filha : public Pai1, public Pai2{
    
};
/*
 * 
 */
int main(int argc, char** argv) {

    Filha f;
    f.Pai1::foo();
    f.Pai2::foo();
    
    return 0;
}

