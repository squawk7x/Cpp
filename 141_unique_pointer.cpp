
/*********** unique_ptr *********************/

// Unique Pointers: exclusive owenership ( <-> shared pointers)
// light weight smart pointer


#include<iostream>
#include<memory>

using namespace std;


class Dog {
  public:
      string m_name;
      void bark() { cout << "Dog " << m_name << " rules!" << endl; }
      Dog() {cout << "Nameless dog created." << endl; m_name = "nameless"; }
      Dog(string name) { cout << "Dog is created: " << name << endl; m_name = name; }
     ~Dog() { cout << "dog is destroyed: " << m_name << endl; }
};

void test() {
    
    //Dog* pD = new Dog("Gunner");
    unique_ptr<Dog> pD(new Dog("Gunner"));
    
    pD->bark();
    /* pD does a bunch of different things*/
    
    //Dog* p = pD.release();
    // pD = nullptr;
    // pD.reset(new Dog("Smokey"));
    // pD.reset();  // pD = nullptr;    // does destroy the object

    // delete pD;   // not needed, like with shared pointer

    // Dog* p = pD.release();   // does not destroy the object
    // pD.reset(new Dog("Smokey"));
    
    if (!pD) {
        cout << "pD is empty.\n";
    }
    
}

void f(unique_ptr<Dog> p) {
    p->bark();
}

unique_ptr<Dog> getDog() {
    unique_ptr<Dog> p(new Dog("Smokey"));
    return p;
}

void test2() {
    unique_ptr<Dog> pD(new Dog("Gunner"));
    unique_ptr<Dog> pD2(new Dog("Smokey"));
    
    pD2->bark();
    // transfer from one unique pointer to another unique pointer
    pD2 = move(pD); 
    // 1. Smokey is destroyed
    // 2. pD becomes empty.
    // 3. pD2 owns Gunner.
    
    pD2->bark();

    // unique_ptr<Dog[]> dogs(new Dog[3]);
    // dogs[1].bark();
    // (*dogs).bark(); // * is not defined
}

void test3() {
    // prevent resource leak even when constructor fails
}


int main ()
{
    test2();
}

