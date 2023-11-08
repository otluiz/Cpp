#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Assuming n-ésimo disk is bottom disk (count down)
void hanoi(int n, char sourcePole,
	   char destinationPole, char auxiliaryPole)
{
  // Base case (termination condition)
  if (n == 0) return;

  // Move first n-1 disks from source pole
  // to auxiliary pole using destination as
  // temporay pole
  hanoi(n - 1, sourcePole, auxiliaryPole, destinationPole);

  // Move the remaning disl from source pole
  // to destination pole
  cout << "Move the disk "<< n << " from " <<
    sourcePole <<" to "<< destinationPole << endl;

  // Move the n-1 disks from auxiliary (now source) 
  // pole to destination pole using source pole as 
  // temporary (auxiliary) pole
  hanoi(n - 1, auxiliaryPole, destinationPole, sourcePole);
}
  
  // Drive code
  int main(int argc, char *argv[])
  {
    cout << "---------------------------" << endl;
    cout << "*****  Torre de Hanoi *****" << endl;
    cout << "4 discos, 3 pinos: A, B , C" << endl;
    cout << "---------------------------" << endl;
    hanoi(4, 'A', 'B', 'C');
    return 0;
  }

	
