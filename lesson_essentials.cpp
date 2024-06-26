/********************************************************************

advanced C++:

1. const int * var; <=> int const * var;
   int* const var;

2. const return value, const parameter, const function
           const func  (const int& var) const {...}

3. for logical constness use:
    mutable int var; // var can be changed in func() const {...}

4.
 ____________________________________________________
|   1        2        3        4        5        6   |
|          ... autogenerated if no ...               |
|____________________________________________________|
|                                                    |
| self                                               |
|   2      self       2*                2        2   |
|            3*     self                3        3   |
|            4*       4*     self       4        4   |
|   5        5        5               self       5   |
|            6        6                 6      self  |
|____________________________________________________|
* added in C++ 11


5.  disallow function:
    1. C++11 : f() = delete;
    2. C++03 : declare the function private and do not define it.
    3. private destructor: stay out of stack.

6 virtual ~Dog() {...} ensures destructor applied polymorphically
    other solution: shared_ptr<Dog>

7. Exceptions and destructors
    1. try{...} catch {...} or
    2. Move the exception-prone code to a different function.

8. avoid use of member functions inside constructor and destructor.

9. if (this == &rhs) return *this;
   Collar* pOrigCollar = pCollar; // backup orig pointer

   Solution 2: delegation:
   operator= (const DogD& rhs) {...}

10. RAII:
    - std::shared_ptr<Dog> pd(new Dog());
    - std::lock_guard<std::mutex> locker(mu);
    - create class Lock (destructor is guaranteed to be executed)

13. Ressource Managing Class (C++ 03):
    1. define copy constructor and copy assignment operator for deep copying.
    2. delete copy constructor and copy assignment operator and define clone() function.

14. virtual constructor or virtual clone()
    Dog* c = new Dog(*d);   // operator=
    Dog* c = d->clone();    // clone as virtual constructor
                            // co-variant return type

15.

23.  Inheritance: Interface & Implementation
                    func()      { ... }

24. Inheritance vs Composition
    use composition for code reuse, not inheritance

25. using B::f; // access to private member f of B
    Anonymous Namespace:
    namespace { ... }

26. g(X:x) -> Argument Dependent Lookup (ADL) in appropriate namespace

// *******************************************************************

modern C++:

7. shared_ptr<Dog> dog = make_shared<Dog>("Tank");

8. shared_ptr<Dog> p(new Dog[3], [](Dog *p) {
        delete[] p;

9. weak_ptr for cyclic references:
    .lock() makes a shared_ptr from weak_ptr
    expired, use_count

10. unique_ptr
    specialized for array.
    unique_ptr<Dog[]> dogs(new Dog[3])

11. Ressource Managing Class (C++ 11):

19. tuple<int, string, char> t(32, "Penny wise", 'a');
    get<1>(t) = "Pound foolish";
    cout << get<1>(t) << endl;

20.

// *******************************************************************

Concurrent Programming

2. thread management
    void fun(string& msg){...}
    A parameter to a thread is always passed by value, must use:
     ... t1(fun, std::ref(s));
     ... t2 = std::move(t1); // thread can only be moved, not copied

3. data race
    std::lock_guard<mutex> locker(m_mutex);

4. deadlock (2 or more mutexes)
        std::lock(m_mutex, m_mutex_2);
        std::lock_guard<mutex> locker(m_mutex, std::adopt_lock);
        std::lock_guard<mutex> locker2(m_mutex_2, std::adopt_lock);

5. unique_lock
    std::unique_lock<mutex> ulocker(mu, std::defer_lock)
        // do sth else
        ulocker.lock();
        // ...
        ulocker.unlock();

    std::once_flag m_flag;
    std::call_once(m_flag, [&](){ f.open("log.txt"); });

6. condition_variable cond;
    // needs std::unique_lock<mutex> locker(mu);
    t1: cond.notify_one(); // cond.notify_all();
    t2: cond.wait(locker, [](){ return predicate == true; });

7. future, promise: exchange values between threads

    std::promise<int> p;
    std::future<int> f = p.get_future();
    p.set_value(4);

    std::future<int> fu =
    std::async(std::launch::async, func, std::ref(f)));
    int x = fu.get();

8. callable object
     ... (a, 6);                           // copy_of_a() in a different thread
     ... (std::ref(a), 6);                 // a() as Functor in a different thread
     ... (A(), 6);                         // temp A;
     ... ([](int x) { return x * x; }, 6); // temp A;
     ... (foo, 7);
     ... (&A::f, a, 8, 'w');  // copy_of_a.f(8, 'w') in a different thread
     ... (&A::f, &a, 8, 'w'); // a.f(8, 'w') in a different thread
     ... (std::move(a), 8);   // a is no longer usable in parent thread

9. std::package_task<int(int)> t(factorial);
    t(4);   // or
    std::package_task<int()> t(std::bind(factorial, 4));
    t();

    int x = t.get_future().get();


/* Summary
 * 3 ways to get a future:
 * - async() returns a future
 * - promise::get_future()
 * - packaged_task::get_future()
 */

/********************************************************************/

// variable capture: auto func = [&](int x) { return f(x, y); };