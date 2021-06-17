#include <iostream>
#include <string.h>
using namespace std;

typedef struct Universidade{ string nome: };t_universidade;
typedef struct Aluno{
  string nome;
  t_universidade universidade;
}t_aluno;

int main(int argc, char *argv[]){
  t_aluno aluno = {"Marcos", {"UFPE"}};
  t_aluno * ptr_aluno;

  ptr_aluno = &aluno;

  cout << "Aluno: " << ptr_aluno->nome << endl;
  cout << "Universidade: " << ptr_aluno->universidade.nome << endl;

  return 0;

}
