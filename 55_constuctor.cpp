#include <iostream>

<<<<<<< HEAD class Student {
=======
    class Student {
>>>>>>> origin/master
    public:
        std::string name;
        int age;
        double gpa;

<<<<<<< HEAD
        Student(std::string name, int age, double gpa){
=======
        Student(std::string name, int age, double gpa) {
>>>>>>> origin/master
            this->name = name;
        this->age = age;
        this->gpa = gpa;
    }
};

<<<<<<< HEAD
int main() {
=======
    int main() {
>>>>>>> origin/master
    Student student1("rick", 25, 3.2);

    std::cout << student1.name << '\n';
    std::cout << student1.age << '\n';
    std::cout << student1.gpa << '\n';

    return 0;
}