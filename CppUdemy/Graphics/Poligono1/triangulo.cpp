// para compilar g++ demo.c -o demo -lgraph

#include <algorithm>
#include <graphics.h>
#include <vector>
using namespace std;


typedef pair<int, int> vertex;

void polygon(vector<vertex>& vertices){

  for (int i = 0, n = vertices.size(); i < n; ++i) {

    vertex current = vertices[i], next;
    next = vertices[(i == n - 1) ? 0 : i + 1];
    int x1 = current.first, y1 = current.second;
    int x2 = next.first, y2 = next.second;
    line(x1, y1, x2, y2);
  }
}

// Driver code
int main(int argc, char *argv[])
{
  int gd = DETECT, gm;

  // initialize graphics library
  initgraph(&gd, &gm, NULL);

  vector<vertex> vertices;
  vertices.push_back(vertex(340, 150));
  vertices.push_back(vertex(220, 250));
  vertices.push_back(vertex(340, 350));

  polygon(vertices);
  delay(5000);
}
