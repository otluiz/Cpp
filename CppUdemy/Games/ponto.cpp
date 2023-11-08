/*
 * Definição de um ponto que será a coordenada de um vetor
 * P' = (Px + Vx, Py + Vy)
 * Vc = (Px - Ix, Py - Iy) 
 */

#include <iostream>
using namespace std;

class Vector{
public:
  float x, y;
};

class Point{
public:
  Point AddVector (Vector v);
  float x, y;
};


Point Point::AddVector(Vector v){
  Point p2;
  p2.x = x + v.x;
  p2.y = y + v.y;

  return p2;
}

int main(int argc, char *argv[])
{
  Point p; // (0, -1) PacMan
  p.x = 1;
  p.y = 0;


  Vector v; // (2, 3) 
  v.x = 2;
  v.y = 3;

  Point p2 = p.AddVector(v);

  cout << "Resultado: (" << p2.x << ", " << p2.y << ")\n";
  
  return 0;
}
