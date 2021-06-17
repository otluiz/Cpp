/*
Maior subsequência comum
LCS - Longest Common Subsequence
exemplo:
 s1: abcd
 s2: acd

sendo que a primeira linha e a primeira coluna são preenchidas com zeros
     A C B
     0 0 0
 A 0 1 1 1
 B 0 1 1 2
 C 0 1 2 2
 D 0 1 2 3

 Resposta: 3

 LCs(s1, s2) = acd

 s1, s2
 c[i, j] = c[i -1, j -1] + 1 se s1[i] == s2[j] // diagonal principal
 senão, c[i, j] = max(c[i, j - 1], c[i - 1, j]) 
 // c[i, j - 1] elementos à esquerda
 // c[i - 1, j] elementos à direita
 */

#include <iostream>
#include <algorithm>
using namespace std;

int get_len_lcs(string &s1, string &s2){

  int len_s1 = s1.size(), len_s2 = s2.size();

 	// matrix
	int mat[len_s1 + 1][len_s2 + 1];

	// initializes the first line and column with 0
	for(int i = 1; i <= len_s1; i++)
		mat[i][0] = 0;
	for(int i = 0; i <= len_s2; i++)
	        mat[0][i] = 0;

	for(int i = 1; i <= len_s1; i++)
	{
		for(int j = 1; j <= len_s2; j++)
		{
			if(s1[i - 1] == s2[j - 1])
				mat[i][j] = mat[i - 1][j - 1] + 1;
			else
				mat[i][j] = max(mat[i][j - 1], mat[i - 1][j]);
		}
	}

  cout << "Imprimindo a tabela: " << endl;
  for (int i = 0; i <= len_s1; i++) {
    for (int j = 0; j <= len_s2; j++)
      cout << mat[i][j] << " ";
    cout << endl;
  }

  return mat[len_s1][len_s2];
    
}


int main(int argc, char *argv[])
{
  string s1("ABCB"), s2("BDCAB");

  int len_lcs = get_len_lcs(s1, s2);

  cout << "\nLength: " << len_lcs << endl;
  
  return 0;
}
