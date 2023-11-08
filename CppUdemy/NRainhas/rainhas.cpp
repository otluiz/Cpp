/*
 * Soluçao do jogo das 8 rainhas em um tabuleiro, onde as rainhas
 * não se atacam. Solução de Marcos Castro prof. Curso C++
 */

#include <iostream>
#include <vector>


using namespace std;

// conta a quantidade de soluções
int sol = 0;

// função pra mostrar o tabuleiro
void mostrarTabuleiro(vector<vector<int> > &tab, int N){

  for (int  i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (tab [i] [j] == 1)
	cout << "R\t";
      else
	cout << "-\t";
    }
    cout << "\n\n";
  }
  cout << "\n\n";
}

// verifica se é seguro colocar a rainha numa determinada coluna
// isso poderia ser feito com menos código, mas assim ficou mais didático
bool seguro(vector<vector<int> > &tab, int N, int lin, int col){

  int i, j;
  // verifica se ocorre ataque na linha
  for (i = 0; i < N; ++i) { // se eu quero verificar a linha eu vario a coluna
    if (tab [lin] [i] == 1) return false;
  }

  // verifica se ocorre ataque na coluna
  for (i = 0; i < N; ++i) {// se eu quero verificar a coluna eu vario a linha
    if (tab [i] [col] == 1) return false;
  }

  // verifica se ocorre ataque na diagonal acima e abaixo
  for (i = lin, j = col; i >= 0 && j >= 0; --i, --j) {
    if (tab [i] [j] == 1) return false;
  }
  // verifica se ocorre ataque na diagonal abaixo da diagonal principal
  for (i = lin, j = col; i < N && j < N; ++i, ++j) {
    if (tab [i] [j] == 1) return false;
  }

  // verifica se ocorre ataque na diagonal secundária
  // acima e abaixo
  for (i = lin, j = col; i >= 0 && j < N; --i, --j) { // acima da diagonal secundária
    if (tab [i] [j] == 1) return false;
  }
  for (i = lin, j = col; i < N && j >= 0; ++i, --j) { // abaixo da diagonal secundária
    if (tab [i] [j] == 1) return false;
  }

  // se chegou aqui, então está seguro (não sofre ataque)
  // retorna true
  return true;
}

/*
 * função que resolve o problema
 * retorna true se conseguiu resolver e false 
 * caso contrário
 */
void executar(vector<vector<int> > & tab, int N, int col){

  if (col == N){

    cout << "Solução " << sol + 1 << ":\n\n";
    mostrarTabuleiro(tab, N);
    sol++;
  }
  
  for (int i = 0; i < N; ++i) {
    // verifica se é seguro colocar a rainha naquela coluna
    if (seguro(tab, N, i, col)){ // se a função retorna true

      // insere a rainha (marca 1)
      tab[i] [col] = 1;
      
      // chamada recursiva
      executar(tab, N, col + 1);

      // remove a rainha (backtracking)
      tab[i] [col] = 0;
    }
  }
}

int main(int argc, char *argv[])
{
  // número de rainhas
  int N = 8;

  // inserindo um tabuleiro
  vector<vector<int> > tab;

  // inserindo todas as linhas
  for (int i = 0; i < N; ++i) {
    vector<int> linha(N);
    tab.push_back(linha);
  }

  // imprime todas as soluções
  executar(tab, N, 0);

  // imprime a quantidade de soluções
  cout << "\nEncontradas " << sol << " soluções!\n";

  return 0;
}
