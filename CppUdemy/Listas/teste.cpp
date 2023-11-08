/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   teste.cpp
 * Author: otluix
 *
 * Created on 25 de Outubro de 2019, 15:55
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool pares(const int& n) 
    {return (n % 2 == 0);}

bool comparar_tamanho(const string& s1, const string& s2){
    if(s1.length() < s2.length()) return true;
}

/*
 * 
 */
int main(int argc, char** argv) {

    list<int> L1; // lista de inteiros vazia
    list<int> L2(3, 10); // três inteiros com valor = 10
    list<int> ::iterator it;
    //list<int> ::iterator it2;
    list<int> ::iterator it3;
    list<int> ::iterator it4;
    //list<int> ::iterator it5;
    
    // inserindo elementos em L1 - push_back e push_front
    L1.push_back(10);  // L1: 10
    L1.push_front(20); // L1: 20, 10
    L1.push_back(30);  // L1: 20, 10, 30
    L1.push_back(50);  // L1: 20, 10. 30, 50
    L1.push_front(90);  // L1: 90, 20, 10. 30, 50
    
    cout << "Mostrando os elementos de L1\n";
    for(it = L1.begin(); it != L1.end(); it++)
        cout << *it << endl;
    
    cout << "Mostrando os elementos de L2\n";
    for(it = L2.begin(); it != L2.end(); it++)
        cout << *it << endl;
    
    // Acessando o primeiro elemento e o último de L1 - front e back
    cout << "\nPrimeiro elemento de L1 (com a função front)\n" << L1.front() << endl;
    cout << "\nÚltimo elemento de L1 (com a função back)\n" << L1.back() << endl;
    
    cout << "\nTamanho de L1:" << L1.size() << endl;
    cout << "\nMostrando os elementos de L1: " << endl;
    // Mostrando a lista L1
    for(it = L1.begin(); it != L1.end(); it++)
        cout << *it << " " ;
    
    // L1: 20, 10, 30
    // Removendo o primeiro elemento de L1
    cout << "\nRemovendo o elemento da frente de L1: " << endl;
    L1.pop_front(); // remove o 20
    // Mostrando a lista L1
    for(it = L1.begin(); it != L1.end(); it++)
        cout << *it << " " ;
    
    cout << "\nRemovendo o elemento da cauda de L1: " << endl;
    
    // Removendo o último elemento de L1
    L1.pop_back();
    // Mostrando a lista L1
    for(it = L1.begin(); it != L1.end(); it++)
        cout << *it << " " ;
    
    
    cout << "\nMostrando os elementos de L1 :\n";
    for(it = L1.begin(); it != L1.end(); it++)
        cout << *it << endl;
    
    // Removendo todos os elementos de L2
    while(!L2.empty()) L2.pop_front();
    
    cout << "\nNovo tamanho de L2: " << L2.size() << endl;
    
    // Atribuindo novos elementos a L2
    int vet[] = {1, 2, 3, 4, 5};
    L2.assign(vet, vet + 5);
    
    cout << "\nMostrando novos elementos de L2:\n";
    for(it = L2.begin(); it != L2.end(); it++)
            cout << *it << endl;
    
    // Inserindo um elemento em L2 - função insert
    L2.insert(L2.begin(), 100);
    cout << "\nMostrando novamente os elementos de L2: \n";
    for(it = L2.begin(); it != L2.end(); it++)
        cout << *it << endl;
    
    
    // Inserindo um elemento na 2ª posição
    //L2.insert(L2.begin() + 1, 100); // Não se pode fazer isso numa Lista, se fosse num vetor poderia
    it = L2.begin();
    it++;
    L2.insert(it, 200);
    cout << "\nInserindo o valor " << "200" << " na 2ª posição de L2: \n";
    for(it = L2.begin(); it != L2.end(); it++)
        cout << *it << endl;
    
    // Inserindo o valor 50 duas vezes na primeira posição
    L2.insert(L2.begin(), 2, 50);
    cout << "\nElementos de L2: \n";
    for(it = L2.begin(); it != L2.end(); it++)
        cout << *it << endl;
    
    // Apagando os dois primeiros elementos da L2
    list<int>::iterator it2 = L2.begin();
    it2++;
    it2++;
    L2.erase(L2.begin(), it2);
    cout << "\nElementos de L2 após remover os dois primeiros: \n";
    for(it = L2.begin(); it != L2.end(); it++)
        cout << *it << endl;
    
    
    cout << "\nCriando duas novas listas: Lista-1 {10, 10} e Lista-2 {20, 20}\n";
    // Função splice - transfere elementos de uma lista para outra
    list<int> lista1(2, 10), lista2(2, 20);
    it = lista1.begin();
    cout << "\nMovendo os elementos da Lista-2 para a Lista-1";
    
    lista1.splice(it, lista2);
    cout << "\nElementos da Lista 1: \n";
    // Mostrando como ficou lista1
    for(it = lista1.begin(); it != lista1.end(); it++)
        cout << *it << endl;
    
    cout << "\nTamanho da Lista 2: " << lista2.size() << endl;
    
    // remover todos os elementos iguais a um valor
    // função remove()
    lista1.remove(20);
    cout << "\nElementos da Lista 1 após remover o elemento 20: \n";
    // Mostrando como ficou lista1
    for(it = lista1.begin(); it != lista1.end(); it++)
        cout << *it << endl;
    
    // função remove_if
    // remove se ocorrer determinada condição
    int vet2[] = {6, 8, 10, 5, 20, 21};
    list<int> lista3(vet2, vet2 + 6);
    cout << "\nCriando a Lista-3: \n";
    for(it2 = lista3.begin(); it2 != lista3.end(); it2++)
        cout << *it2 << " ";
    
    
    // Removendo todos os elementos pares da lista3
    lista3.remove_if(pares);
    
    cout << "\nElementos de Lista-3 após remover os pares usando a função: remove_if: \n";
    for(it3 = lista3.begin(); it3 != lista3.end(); it3++)
        cout << *it3 << " ";
    
    cout << "\n Criando Lista-4: ";
    int vet3[] = {17, 60, 5, 30, 50};
    // Mostrando a lista desordenada
    list<int> lista4(vet3, vet3 + 5);
    for(it4 = lista4.begin(); it4 != lista4.end(); it4++)
        cout << *it << " ";
    // Ordenando crescentemente
    lista4.sort();
    cout << "\n\n";
    cout << "\nElementos da Lista-4 ordenados: ";
    for(it4 = lista4.begin(); it4 != lista4.end(); it4++)
        cout << *it4 << " ";
    
    // ordenando strings
    list<string> lista5;
    list<string>::iterator it5;
    lista5.push_back("python");
    lista5.push_back("c++");
    lista5.push_back("ruby");
    lista5.push_back("haskell");
    //lista5.sort();
    cout << "\n\nElementos da Lista-5 ordenados\n";
    for(it5 = lista5.begin(); it5 != lista5.end(); it5++)
        cout << *it5 << " ";
            
    // ordenado usando algum critério
    // pelo tamanho da string, lista5.sort() foi comentado;
    lista5.sort(comparar_tamanho);
    cout << "\n\nElementos da Lista-5 ordenados pelo tamanho\n";
    for(it5 = lista5.begin(); it5 != lista5.end(); it5++)
        cout << *it5 << " - tamanho: " << (*it5).length() << endl;
    
    return 0;
}

