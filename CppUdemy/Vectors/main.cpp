/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: otluix
 *
 * Created on 22 de Outubro de 2019, 22:13
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {

    const vector<int> v{0, 1, 2, 3, 4};
    auto sum = 0;
    for(auto element : v) sum += element;
    cout << "sum = " << sum;
    return 0;
}
