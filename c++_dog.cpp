#include <iostream>
#include "c++_dog.h"
#include "c++_cat.h"

Cat cat("Smokey");

Dog::Dog(std::string name) : name_(name) {
    std::cout << "Constructing Dog " << name_ << std::endl;
    cat.meow();
}

void Dog::bark() {
    std::cout << "Dog rules! My name is " << name_ << std::endl;
}
