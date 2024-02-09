#include <iostream>
using namespace std;

struct product {
    double weight;
    double price;
};

product cheese;

struct fruits {
    int pcs;
    double price;
} apple, banana, melon;

struct {
    int cl;
    double price;
} coke, fanta, sprite;

class Rectangle {
    int width, height;

public:
    // Functional Form
    Rectangle();
    Rectangle(int, int);
    Rectangle(double, double);
    Rectangle(int, double);
    int area() {
        return (width * height);
    }
};

Rectangle::Rectangle() {
    width = 1;
    height = 2;
}

Rectangle::Rectangle(int a, int b) {
    width = a;
    height = b;
}

Rectangle::Rectangle(double c, double d) : width(c) {
    height = d;
}

Rectangle::Rectangle(int a, double d) : width(a), height(d) {
}

// classes and uniform initialization

class Circle {
    double radius;

public:
    Circle(double r) {
        radius = r;
    }
    double circum() {
        return 2 * radius * 3.14159265;
    }
    double area() {
        return radius * radius * 3.14159265;
    }
};

class Cylinder {
    Circle base;
    double height;

public:
    Cylinder(double r, double h) : base(r), height(h) {
    }
    double volume() {
        return base.area() * height;
    }
};

int main() {
    // Rectangle rect(); NOT compiling
    Rectangle recta;
    Rectangle rectb(3, 4);
    Rectangle rect{};
    cout << "recta area: " << recta.area() << endl;
    cout << "rectb area: " << rectb.area() << endl;

    Circle bar = 20.0;   // assignment init.
    Circle foo(10.0);    // functional form
    Circle baz{30.0};    // uniform init.
    Circle qux = {40.0}; // POD-like
    cout << "foo's circumference: " << foo.circum() << '\n';

    Cylinder zyl(1, 1);
    cout << "zyl's volume: " << zyl.volume() << '\n';

    Rectangle obj(3, 4);
    Rectangle *p_foo, *p_bar, *p_baz;
    p_foo = &obj;
    p_bar = new Rectangle(5, 6);
    p_baz = new Rectangle[2]{{2, 5}, {3, 6}};
    cout << "obj's area: " << obj.area() << '\n';
    cout << "*foo's area: " << p_foo->area() << '\n';
    cout << "*bar's area: " << p_bar->area() << '\n';
    cout << "baz[0]'s area:" << p_baz[0].area() << '\n';
    cout << "baz[1]'s area:" << p_baz[1].area() << '\n';
    delete p_bar;
    delete[] p_baz;

    return 0;
}
