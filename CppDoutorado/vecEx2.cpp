//vecEx2.cpp
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

//using namespace std; 
 
int main() { 

  int nrows = 3, ncols = 2;
  vector<vector<int> > v;
  v.resize(nrows);
  for(int i = 0; i < nrows; i++){
    v[i].resize(ncols);
    for(int j = 0; j < ncols; j++)
      v[i][j] = (i + 1)*(j + 1);
  }

  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < v[i].size(); j++)
      cout << "v[" << i << "][" << j << "] = "
	   << v[i][j] << " ";
    cout << endl;
    
  }
 
  return 0; 
} 

