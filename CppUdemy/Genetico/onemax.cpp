/**
 * Implementação de algorítimo genético para solução do problema Onemax
 * em que a solução final sera um gene com todos os locus em 1
 */

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
using namespace std;

int tam_genes = 100;
int tam_pop = 50;
int tam_torneios = 20;
int geracoes = 500;
double prob_mut = 0.2;
double prob_cruz = 0.7;

// população
vector<vector<int> > populacao;

void inicializaPopulacao(){
  for (int i = 0; i < tam_pop; i++) {

    vector<int> individuo;

    for (int j = 0; j < tam_genes; j++) {
      int num = rand() % 2;   // escolhe um número entre 0 e 1
      individuo.push_back(num); // insere no vetor do individuo
    }
    populacao.push_back(individuo); // insere no vetor da população
  }
}


void mostrarPopulacao()
{
        for(int i = 0; i < tam_pop; i++)
        {
                for(int j = 0; j < tam_genes; j++)
                        cout << populacao[i][j] << " ";
                cout << endl;
        }
}


int obterPontuacao(vector<int> individuo){

  int soma = 0;

  for (int i = 0; i < tam_genes ; i++ )
    soma += individuo[i];
  return soma;
}


// realiza a mutação de alguns genes
void mutacao(vector<int> & individuo){
  
  // escolhe um gene aleatório no intervalo [0, tam_genes - 1]
  int gene = rand() % tam_genes;

  if (individuo[gene] == 0)
    individuo[gene] = 1;
  else
    individuo[gene] = 0;
}


// realiza o cruzamento dos genes
void cruzamento(int indice_pai1, int indice_pai2, vector<int>& filho){

  int ponto = rand() % tam_genes;

  for (int i = 0; i <= ponto; i++)
    filho.push_back(populacao[indice_pai1][i]);

  for (int i = ponto + 1; i < tam_genes; i++)
    filho.push_back(populacao[indice_pai2][i]);
}


// retorna o índice do melhor individuo da população
int obterMelhor(){
  int indice_melhor = 0;
  int score_melhor = obterPontuacao(populacao[0]);

  for (int i = 0; i < tam_pop; i++) {

    int  score = obterPontuacao(populacao[i]);
    if (score > score_melhor){
      indice_melhor = i;
      score_melhor = score;
    }
  }
  return indice_melhor;
}

int main(int argc, char *argv[]){

  srand (time(NULL));

  inicializaPopulacao();

  for (int i = 0; i < geracoes; ++i) {
    for (int j = 0; j < tam_torneios; ++j) {

      // cacula a probabilidade de cruzamento
      double prob = ((double) rand() / ((double)RAND_MAX + 1) );

      if (prob < prob_cruz){

	// escolhe dois pais para fazer o cruzamento
	int indice_pai1 = rand() % tam_pop;
	int indice_pai2;


	// garante que os índices dos pais não são iguais
	do {
	  indice_pai2 = rand() % tam_pop;
	}
	while ( indice_pai1 == indice_pai2 );

	vector<int> filho;

	// aplica o cruzamento de 1 ponto
	cruzamento (indice_pai1, indice_pai2, filho);

	// calcula a probabilidade de mutação
	prob = ((double) rand() / ((double)RAND_MAX + 1) );

	if (prob < prob_mut)
	  mutacao(filho);

	int score_pai = obterPontuacao(populacao[indice_pai1]);
	int score_filho = obterPontuacao(filho);

	if (score_filho > score_pai){
	  
	  for(int k = 0 ; k < tam_genes; ++k )
	    populacao[indice_pai1][k] = filho[k];
	}
      }
    }

    cout << "Geracao " << i + 1 << endl;
    cout << "Melhor: ";

    int indice_melhor = obterMelhor();
    int score_melhor = obterPontuacao(populacao[indice_melhor]);

    for (int j = 0; j < tam_genes; ++j)
      cout << populacao[indice_melhor][j] << " ";

    cout << "\nPontuação: " << score_melhor << "\n\n";

    if (score_melhor == tam_genes )
      break;
  }
  return 0;
}

