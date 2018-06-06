/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <memory>
#include <iostream>

using std::cout;

class Dog {
    public:
    Dog() { cout << "YellowDog ctor" << '\n'; }
    ~Dog() { cout << "Dog dtor" << '\n'; }
};

class YellowDog : public Dog {
    public:
    YellowDog() { cout << "YellowDog ctor" << '\n'; }
    ~YellowDog() { cout << "YellowDog dtor" << '\n'; }
};

class FactoryDog {
    public:
    static Dog* MakeYellowdog() {
        cout << "Factorydog Yellowdog" << '\n';
        return (new YellowDog());
    }
};

class SmartFactoryDog {
    public:
    static std::shared_ptr<Dog> MakeYellowdog() {
        cout << "SmartFacotryDog Yellowdog" << '\n';
        return std::make_shared<YellowDog>();
    }
};

int main()
{
    // Dog* pd = FactoryDog::MakeYellowdog();
    std::shared_ptr<Dog> spd = SmartFactoryDog::MakeYellowdog(); 
    
    
    // delete pd; 
    return 0;
}
