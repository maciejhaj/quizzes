/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <iterator>

using std::string;
using std::cout;

int main()
{

    string u{"aaaabbbcdeaaa"};
    string c{};
    string::iterator curr{u.begin()};
    string::iterator next{u.begin()+1};
    size_t counter{0};
     
    for (; curr != u.end(); ++curr, ++next)
    {
       if (*curr == *next)
        {
            counter++;
        }
        else if (counter != 0 && *curr != *next)
        {
            c.append(std::to_string(counter));
            c.push_back(*curr);
            counter = 0;
        }
        else
        {
            c.push_back(*curr);
        }
    }
    cout << "Uncompressed string: " << u << '\n';
    cout << "Uncompressed string: " << c << '\n';
    return 0;
}







