/*
 * Definição de um ponto que será a coordenada de um vetor
 * P' = (Px + Vx, Py + Vy)
 * Vc = (Px - Ix, Py - Iy)
 * |V|^2= Vx^2 + Vy^2 => |V|= sqrt(Vx^2 + Vy^2)
 * 2V = (Vx * 2, Vy * 2) -> dobra a velocidade
 * V/2 = (Vx/2 , Vy/2)   -> reduz a metade a velocidade
 */

#include <iostream>
#include <math.h>
using namespace std;

class Vector{
public:
  Vector() {}
  Vector(float X, float Y) {

    x = X;
    y = Y;
  }
  
  float Length() const;
  float LengthSqr() const;

  Vector operator* (float s) const; // overload em '*'
  Vector operator/ (float s) const; // overload em '/'

  float x, y;
  
};

class Point{
public:
  Point AddVector (Vector v);
  float x, y;
};

Vector Vector::operator* (float s) const{

  Vector scaled;
  scaled.x = x * s;
  scaled.y = y * s;
  
  return scaled;
}

Vector Vector::operator/ (float s) const{

  Vector scaled;

  scaled.x = x / s;
  scaled.y = y / s;
  
  return scaled;
}


float Vector::Length() const{
  float length;
  length = sqrt(x*x + y*y);  // |V|= sqrt(Vx^2 + Vy^2)

  return length;
}

float Vector::LengthSqr() const{
  float length;
  length = (x*x + y*y);  // |V|= (Vx^2 + Vy^2)

  return length;
}


/*
Vector operator- (Point a, Point b){
  Vector v;
  v.x = a.x - b.x;
  v.y = a.y - b.y;

  return v;
}
*/

Point Point::AddVector(Vector v){
  Point p2;
  p2.x = x + v.x;
  p2.y = y + v.y;

  return p2;
}

// MAIN -----------------------------------------------------


int main(int argc, char *argv[])
{
  Vector v(3, 4);

  cout << "PacMan's initial speed: " << v.Length() << "\n";

  Vector doubled;

  doubled = v * 2; // 2V = (Vx * 2, Vy * 2) -> dobra a velocidade

  cout << "Pacman's doubled speed: " << doubled.Length() << "\n";

  Vector halved;

  halved = v / 2; // V/2 = (Vx/2 , Vy/2) -> reduz a metade a veloc.

  cout << "Pacman's halved speed: " << halved.Length() << "\n";
  
  return 0;
}
