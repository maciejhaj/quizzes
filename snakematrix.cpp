/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <iomanip>

using std::cout;

struct cell
{
    int value;
    bool seen;
};

enum direction
{
    right, left, down, up
};

void ShowMatrix(int **tab, const size_t& s)
{
    for (size_t i = 0; i < s; ++i)
    {
        for (size_t j = 0; j < s; ++j)
            cout << std::setw(8) << tab[i][j];
        cout << '\n';
    }
}

void ShowCell(cell **c, const size_t& s)
{
    for (size_t i = 0; i < s; ++i)
    {
        for (size_t j = 0; j < s; ++j)
        {
            cout << std::setw(8) << c[i][j].value;
        }
        cout << '\n';
    }
    for (size_t i = 0; i < s; ++i)
    {
        for (size_t j = 0; j < s; ++j)
        {
            cout << std::setw(8) << c[i][j].seen;
        }
        cout << '\n';
    }
}

int **MakeMatrix(const size_t& s)
{
    size_t counter{s*s};
    int **tab = new int*[s];
    for (size_t i = 0; i < s; ++i)
    {
        tab[i] = new int[s];
        for (size_t j = 0; j < s; ++j)
            tab[i][j] = counter--;
        //cout << '\n';
    }
    return tab;
}

cell **MakeCell(const size_t& s)
{
    size_t counter{s*s};
    cell **c{new cell*[s]};
    for (size_t i = 0; i < s; ++i)
    {
        c[i] = new cell[s];
        for (size_t j = 0; j < s; ++j)
        {
            c[i][j].value = counter--;
            c[i][j].seen = false; 
        }
    }
    return c;
}

int **CopyCellToMatrix(cell **c, const size_t s)
{
    int **tab = MakeMatrix(s);
    for (size_t i = 0; i < s; ++i)
    {
        for (size_t j = 0; j < s; ++j)
        {
            tab[i][j] = c[i][j].value;
        }
    }
    return tab;
}

int **MakeSnake(int **tab, const size_t& s)
{
    size_t counter{s*s}; 
    int i{0}, j{0}, state{1};
     
    cell **c{MakeCell(s)};
    int **m{MakeMatrix(s)};
    
    while (counter != 0)
    {
        cout << counter << '\n';
        switch(state)
        {
            case 1:
            {
                ++state;
                while (i < s && c[i][j].seen != true)
                {
                    c[i][j].value = counter--;
                    c[i][j].seen = true;
                    ++i;
                }
                ++j;
                --i;
            }
            case 2:
            {
                ++state;
                while (j < s && c[i][j].seen != true)
                {
                    c[i][j].value = counter--; 
                    c[i][j].seen = true;
                    ++j;
                }
                --i;
                --j;
            }
            case 3:
            {
                ++state;
                while (i >= 0 && c[i][j].seen != true)
                {
                    c[i][j].value = counter--; 
                    c[i][j].seen = true;
                    --i;
                }
                --j;
                ++i;
            }
            case 4:
            {
                ++state;
                while (j >= 0 && c[i][j].seen != true)
                {
                    c[i][j].value = counter--; 
                    c[i][j].seen = true;
                    --j;
                }
                ++i;
                ++j;
            }
            state = 1;
        }
    }
    cout << "Matrix has been snaked" << '\n';
    m = CopyCellToMatrix(c, s);
    return m;
}


int main()
{
    cout<<"Wezyk w macierzy" << '\n';
    
    size_t s{5};
    int **m{MakeMatrix(s)};
    int **snake{};
    cell **c{MakeCell(s)};
    
    ShowMatrix(m, s); 
    cout << '\n';
    ShowCell(c, s);
    cout << '\n';
    
    snake = MakeSnake(m, s);
    
    ShowMatrix(snake, s);
    
    return 0;
}
