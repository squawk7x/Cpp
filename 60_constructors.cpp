// example: class constructor
#include <iostream>
using namespace std;

class Rectangle {
  int width, height;

 public:
  Rectangle();
  Rectangle(int, int);
  int area() { return (width * height); }
};

Rectangle::Rectangle() {
  width = 1;
  height = 2;
}

Rectangle::Rectangle(int a, int b) {
  width = a;
  height = b;
}

class Circle {
  double radius;

 public:
  Circle(double r) { radius = r; }
  Circle(double, int);

  double circum() { return 2 * radius * 3.14159265; }
};

Circle::Circle(double r, int c) { 
  radius = r * c; }

int main() {
  Rectangle rect;
  Rectangle rectb(4, 5);

  Circle foo(10.0);     // functional form
  Circle bar = 20.0;    // assignment init.
  Circle baz{30.0};     // uniform init.
  Circle qux = {40.0, 2};  // POD-like

  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  return 0;
}