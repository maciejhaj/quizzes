#include<iostream>
#include<functional>

int main () 
{

    auto l = [ i = 0, j = 1]() mutable { 
	
	i = std::exchange(j, j+i);
	return i; 
	
	};
    for (int i = 0; i < 4 ; i++)
    {
	l();
    }
    std::cout << l() << '\n';    
    return 0;
}

