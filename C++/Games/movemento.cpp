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

Vector operator- (Point a, Point b){

  Vector v;

  v.x = a.x - b.x;
  v.y = a.y - b.y;

  return v;
}

Point Point::AddVector(Vector v){
  Point p2;
  p2.x = x + v.x;
  p2.y = y + v.y;

  return p2;
}

int main(int argc, char *argv[])
{
  Point p; // (0, -1) PacMan
  p.x = 0;
  p.y = -1;

  Point i; // (1, 1) Inch - o bicho azul
  i.x = 1;
  i.y = 1;

  Vector v;
  // O operador '-' foi sobrescrito na fução operator
  v = p - i; // Vc = (Px - Ix, Py - Iy)
  

  cout << "Resultado: (" << v.x << ", " << v.y << ")\n";
  
  return 0;
}
