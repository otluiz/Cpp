#include <functional>
#include <iostream>
using namespace std;


float plus(float a, float b) { return a + b; }

int main(int argc, char *argv[])
{
  auto f1 = std::bind(std::plus( 100.f, 200.f));

  cout << f1() << "\n"; // << f2() << "\n"
  return 0;
}
