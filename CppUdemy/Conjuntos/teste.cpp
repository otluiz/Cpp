/*
 * Utilizando a ideia de conjuntos, estes não permite elementos duplicados.
 * Têm estrutura de uma árvore binária de busca.
 */

/* 
 * File:   teste.cpp
 * Author: otluix
 *
 * Created on 10 de Dezembro de 2019, 11:41
 */
#include <iostream>
#include <set>
#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //int  vet[] = {10, 20, 10, 30, 40}; // o elemento repetido vai ser omitido
    int  vet[] = {70, 20, 80, 30, 40}; // a lista é mostrada sempre ordenada
    set<int> myset(vet, vet + 5);
    
    set<int>::iterator it = myset.begin();
    
    cout << "\nMostrando os elementos: ";
    while(it !=myset.end()){
        cout << *it << " ";
        it++;
    }
    
    //myset.clear(); // remove todos os elementos
    it = myset.begin();
    myset.erase(it);
    
    if(myset.empty())
        cout << "\nConjunto vazio!!\n";
    else
        cout << "\nConjunto NÃO vazio!!\n";
    
    it = myset.begin();
    cout << "\nMostrando os elementos: ";
    while(it !=myset.end()){
        cout << *it << " ";
        it++;
    }
    
    it = myset.find(70);
    if(it == myset.end())
        cout << "\n\nO elemento 70 NÃO existe\n";
    else
        cout << "\n\nO elemento 70 exite\n";
    
    cout << "\nTamanho do conjunto: " << myset.size() << endl;
    
    return 0;
}

