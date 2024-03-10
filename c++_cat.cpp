#include "c++_cat.h"
#include "c++_dog.h"
#include <iostream>

using namespace std;

extern Dog dog;

Cat::Cat(string name) {
    cout << "Constructing Cat " << name_ << endl;
    name_ = name;
    dog.bark();
}

void Cat::meow() { cout << "Cat rules! My name is " << name_ << endl; }