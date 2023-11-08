/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: otluix
 *
 * Created on 22 de Outubro de 2019, 22:28
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int fibonacci(int n){
    if (n < 2) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
/*
 * 
 */
int main(int argc, char** argv) {

    int num = 0;
    cout << "Entre o um número: " << endl;
    cin >> num;
    cout << "O número de fibonacci para " << num << " é: " << fibonacci(num); 
    return 0;
}

