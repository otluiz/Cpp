#include <bits/stdc++.h>
using namespace std;

int *cellComplete(int *cells, int days) {
 for (int j = 0; j < days; ++j) {

   int copy_cells[10];
   for (int i = 1; i < 9; ++i)
     cells[i] = copy_cells[i] == copy_cells[i + 2]?0:1;

 }
 return cells;   
}

int main(int argc, char *argv[])
{
  //int arr[8] = {1,1,1,0,1,1,1,1};
  int arr2[8] = {1,0,0,0,0,1,0,0};
  cellComplete(arr2, 1);
  for (int i = 0; i < 8; ++i) {
    cout << arr2[i] << " ";
  }

  return 0;
}
