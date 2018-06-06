#include <utility>
#include <iostream>

int main()
{
    int x{0};    
    int y{1};
    int z{2};

    std::cout << "x = " << x << ", y = " << y << ", z = " << z << '\n';
    
    x = std::exchange(y, 3);

    std::cout << "x = " << x << '\n';
    std::cout << "y = " << y << '\n';
    std::cout << "z = " << z << '\n';

    std::string s1{"hello"};
    std::string s2{"world!"};

    std::swap(s1, s2);
//    std::swap(s1, std::string{"asd"});

    std::cout << s1 << ' ' << s2 << '\n';

    return 0;
}
