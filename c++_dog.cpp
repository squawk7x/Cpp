#include "c++_cat.h"
#include "c++_dog.h"
#include <iostream>

Cat cat("Smokey");

Dog::Dog(std::string name) : name_(name) {
    std::cout << "Constructing Dog " << name_ << std::endl;
    cat.meow();
}

void Dog::bark() { std::cout << "Dog rules! My name is " << name_ << std::endl; }
