// para compilar g++ demo.c -o demo -lgraph

#include <algorithm>
#include <graphics.h>
#include <vector>
using namespace std;

#define TWO_PI 44 / 7.0F
typedef pair<int, int> vertex;

void polygon(vector<vertex> vertices){

  for (int i = 0, n = vertices.size(); i < n; ++i) {
    vertex current = vertices[i], next;
    next = vertices[(i == n - 1) ? 0 : i + 1];
    int x1 = current.first, y1 = current.second;
    int x2 = next.first, y2 = next.second;
    line(x1, y1, x2, y2);
  }
}


vector<vertex> discretizeEllipse(int x, int y, int a,
				 int b, int seg){
  float angle_shift = TWO_PI / seg, phi = 0;
  vector<vertex> vertices;
  for (int i = 0; i < seg; ++i) {
    phi += angle_shift;
    vertices.push_back(vertex(x + a * cos(phi),
			      y + b * sin(phi)));
  }
  return vertices;
}

vector<vertex> discretizeEllipse(int x, int y, int a,
				 int b){
  int segments = max((int) floor (sqrt (((a + b) /2) * 20)), 8);

  return discretizeEllipse(x, y, a, b, segments);
}


int main()
{
  int gd = DETECT, gm;
  // initialize graphics library
  initgraph(&gd, &gm, NULL);

  polygon(discretizeEllipse(320, 240, 200, 100));
  polygon(discretizeEllipse(320, 240, 200, 100, 8));
  delay(5000);
  return 0;
}
