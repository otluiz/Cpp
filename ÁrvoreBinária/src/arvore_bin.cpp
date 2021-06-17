#include <iostream>
using namespace std;

class No{
private:
  No *esq, *dir;
  int chave;

public:
  No(int chave){
    this->chave = chave;
    esq = NULL;
    dir = NULL;
  }
  int getChave(){ return chave; } // retorna o valor do nó (chave)
  No* getEsq(){ return esq; } // retorna o nó à esquerda
  No* getDir(){ return dir; } // retorna o nó à direita
  void setEsq(No *no){ esq = no; }
  void setDir(No *no){ dir = no; }
}; // fim da classe nó

class Arvore{
private:
  No *raiz;
public:
  Arvore() { raiz = NULL; } // se a árvore estiver vazia

  void inserir(int chave){
    if(raiz == NULL) raiz = new No(chave); // coloca o 1º nó na árvore
    else inserirAux(raiz, chave);
  }

  void inserirAux(No *no, int chave){
    if(chave < no->getChave()){ // se for menor, então, insere à esqueda
      if(no->getEsq() == NULL){ // verifica se à esqueda é nulo
	No *novo_no = new No(chave); 
	no->setEsq(novo_no); // 'seta' o novo_no à esquerda
      }
      else { inserirAux(no->getEsq(), chave); } // senão, continua percorrendo recursivamente
    }
    else if(chave > no->getChave()){ // se fora maior, então, insere à direita
      if(no->getDir() == NULL){ // verifica se à direita é nulo
	No *novo_no = new No(chave);
	no->setDir(novo_no); // 'seta' o novo nó à direita
      }
      else { inserirAux(no->getDir(), chave); } // senão, continua percorrendo recursivamente
    }
  }
    No* getRaiz() { return raiz; }

    void emOrdem(No* no){ // função para percorrer a árvore começãndo do nó
      if(no != NULL){  // mais à esquerda, seguindo um percuros pré-determinado
	emOrdem(no->getEsq());
	cout << no->getChave() << " ";
	emOrdem(no->getDir());
      }
    }    
};

  int main(int argc, char *argv[]){
    Arvore arv;

    arv.inserir(8);
    arv.inserir(10);
    arv.inserir(14);
    arv.inserir(13);
    arv.inserir(1);
    arv.inserir(6);
    arv.inserir(4);
    arv.inserir(7);
    
    // percorre em ordem iniciando da raiz
    cout << "Percorrendo em ordem...\n\n";
    arv.emOrdem(arv.getRaiz());

    cout << "\n" << endl;
    return 0;
}
