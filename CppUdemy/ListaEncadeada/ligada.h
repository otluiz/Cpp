#ifndef _LISTA_H_
#define _LISTA_H_
#include <iostream>

using namespace std;

// classe No
template<class T>
class No{
private:
  T val;
  No* prox;
public:
  No(T v){ // construtor da classe
    this->val = v;
    this->prox = NULL; // somente p/ criação do Nó
  }
  T obterValor(){ return val; }
  No* obterProx(){ return prox; } // todo nó tem uma referência para o próximo
  void setProx(No* p){ prox = p; }
};

// classe Lista
template<class T>
class Lista{
private:
  No<T> *cabeca; // primeiro elemento da lista
  No<T> *cauda;  // último elemento (na prog. funcional é REST DA CAUDA DA LISTA)
public:
  Lista(){
    cabeca = NULL;
    cauda = NULL;
  }
  Lista(T v){
    // se passar elemento, então cria novo No
    cabeca = new No<T>(v);
    cauda = cabeca; // semente se tiver um elemento
  }
  virtual ~Lista(){ delete cabeca; } // destrutor da classe

  void mostrar(){
    cout << "\n Imprimindo todos os elementos... \n";
    No<T>* c = cabeca;
    if(vazia())
      cout << "A lista não possui elementos!!\n";
    else{ // possui elementos na lista
      while (c) {
	cout << c->obterValor() << endl;
	c = c->obterProx();
      }
      cout << endl;
    }
  }

  bool vazia() { return (cabeca == NULL); } // verifica se a lista está vazia
  
  void inserir_inicio(T v) {
    No<T>* novo_no = new No<T>(v);
    novo_no->setProx(cabeca);
    cabeca = novo_no; // novo primeiro elemento
  }

  void inserir_final(T v){
    No<T>* novo_no = new No<T>(v);

    if(vazia()){ // o mesmo que cabeca == NULL
      cabeca = novo_no;
      cauda = novo_no;
    }
    else{
      cauda->setProx(novo_no);
      cauda = novo_no;
    }
  }

  int tamanho(){
    if(vazia()) return 0;

    No<T>* c = cabeca;
    int tam = 0;
    do{
      c = c->obterProx();
      tam++;
    }
    while (c);
    
    return tam;
  }

  bool existe(T v){
    No<T>* c = cabeca;
    while (c) {
      if(c->obterValor() == v) return true;
      c = c->obterProx();
    }
    return false;
  }

  void remover(){ // remoção do final da lista
    if(!vazia()){
      if(cabeca->obterProx() == NULL) cabeca = NULL;
      else if(cabeca->obterProx()->obterProx() == NULL) // 2 elementos
	cabeca->setProx(NULL);
      else{ // mais de 2 elementos
	No<T>* ant_ant = cabeca;
	No<T>* ant = cabeca->obterProx();
	No<T>* corrente = cabeca->obterProx()->obterProx(); // terceiro elemento

	while (corrente) {
	  No<T>* aux = ant;
	  ant = corrente; // o ant é o último elemento
	  ant_ant = aux;  // guarda a posição do penúltimo elemento que será removido
	  corrente = corrente->obterProx();
	}
	delete ant_ant->obterProx(); // libera a memória
	ant_ant->setProx(NULL); // o penúltomo elemento é agora o último
	cauda = ant_ant; // atualiza a cauda
      }	
    }
  }
};

#endif
