/*
 * Este projeto Lê de um arquivo, e grava no arquivo através da classe Pessoa.
 * Foi feito um Menu para inserir e pesquisar nomes no arquivo gerado.
 * Será utilizado as funções ofstream e ifstream
 */

/* 
 * File:   arquivo.cpp
 * Author: otluix
 *
 * Created on 10 de Dezembro de 2019, 14:41
 */

#include <iostream>
#include <fstream> //
#include <cstdlib>
using namespace std;

class Pessoa{
private:
    string nome;
    int idade;
public:
    string& getNome(){ return nome; }
    int getIdadde(){ return idade; }
    void setNome(string& nome){ this->nome = nome; }
    void setIdade(int idade){ this->idade = idade; }
    
    // Sobrecarga do operador de inserção de dados '<<'
    // ostream = output stream
    friend ostream& operator << (ostream& os, const Pessoa& p){
        // escrever cada membro
        os << "\n" << p.nome << "\n";
        os << p.idade;
        return os;
    }
    
    // sobrecarga do operador de extração de dados
    // istream => input stream
    friend istream& operator >> (istream& is, Pessoa& p){
        // ler cada membro
        is >> p.nome >> p.idade;
        return is;
    }
};
/*
 * 
 */

char menu(){
    
    char resp;
    cout << "Digite 1 para inserir pessoas\n";
    cout << "Digite 2 para listar as pessoas\n";
    cout << "Digite 0 para sair\n";
    cout << "Opção: ";
    cin >> resp;
    return resp;
    
}


int main(int argc, char** argv) {

    char resp;
    
    while(true){
        
        resp = menu();
        if(resp == '1'){
            Pessoa pessoa;
            string nome;
            int idade;
            
            // app => append (adiciona ao final do arquivo)
            ofstream ofs("arquivo.txt", fstream::app);
            cout << "\nDigite o nome da pessoa: ";
            cin >> nome;
            cout << "\nDigite a idade da pessoa: ";
            cin >> idade;
            
            // 'Setar' o nome e a idade para as funções que irão incluir na classe
            pessoa.setNome(nome);
            pessoa.setIdade(idade);
            
            ofs << pessoa;
            ofs.close();
            
        }
        else if(resp == '2'){
            Pessoa p;
            ifstream ifs("arquivo.txt");
                        
            cout << "\nListando pessoas...\n\n" ;
            
            //verifica se o arquivo exite para ser lidp
            if(ifs.good()){
                // eof => end of file => enquanto não chegar ao final do arquivo
                while(!ifs.eof()){
                    ifs >> p; // faz a extração dos dados
                    
                    // mostra os dados
                    cout << "Nome: " << p.getNome() << endl;
                    cout << "Idade: " << p.getIdadde() << "\n\n";
                }
                ifs.close();
            }
        }
        else if(resp == '0'){
            cout << "\nBye!! Visite: www.geeksbr.com ;^)\n";
            break;
        }
        else{
            cout << "\nOpção inválida. Tente novamente....\n\n";
        }
        
    }
    
    return 0;
}

