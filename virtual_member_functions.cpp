/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <type_traits>
#include <iomanip>

using std::cout;

class base
{
    public:
    virtual void function1()
    {
        cout << "Base class" << '\n'; 
    }
};

class derived: public base 
{
    public:
    void function1()
    {
        cout << "Derived class" << '\n';
    }
};

class derived2: public base 
{
    public: 
    void function1()
    {
        cout << "Derived2 class" << '\n';
    }
};

int main()
{
    
    base b;
    derived d;
    derived2 d2;
    
    //b.function1();
    
    base* b_ptr_to_d = &d;
    //derived* d_ptr_to_p = &b;
    
    b_ptr_to_d->base::function1();
    b_ptr_to_d->function1();
    
    b_ptr_to_d = &d2;
    b_ptr_to_d->function1();
    
    cout << "+++++++++++++++++++++++++++" << '\n';
    cout << "b_ptr: " << std::setw(20) << &b_ptr_to_d << '\n';
    cout << "b_ptr: " << std::setw(20) << b_ptr_to_d << '\n';
    cout << "d: " << std::setw(20) << &d << '\n';
    if (b_ptr_to_d == &d)
        cout << "true";
    return 0;
}
