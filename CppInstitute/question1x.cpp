#include <iostream>
using namespace std; 
 
int main() { 

  int y, *p, x;
  y = 0;
  p = &y;    /* atribui o endereço de y para o ponteiro p
	     p contém o endereço de y, ex: DS:FFF4 */
  cout << "p = &y = " << p << " y = "<< y << endl;
  x = 4;
  cout << "x = " << x << endl;
  (*p)++;    /* incrementa de 1 o conteúdo para onde p aponta,
	     alterando o valor de y para 1*/
  cout << "(*p)++ -> y = " << y << endl;
  x--;       /* decrementa de 1 o conteúdo de x => x = 3 */
  (*p) += x; /* adiciona x ao conteúdo para onde p aponta, 
	      alterando o valor de y para 4; y <- x = 4 */
  cout << "y = " << y << endl;
 
  return 0; 
} 

