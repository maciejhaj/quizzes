#include <iostream>
#include <string>

using std::cout;

std::string remove_spaces(const std::string& s)
{
    std::string result{};
    for (auto i = s.begin(); i != s.end(); ++i)
    {
        if (*i != ' ')
            result.push_back(*i);
    } 
    return result;
}

int main()
{
    std::string s{"asd abd  dwa s"};
    std::string r{};
    r = remove_spaces(s);
    cout << s << ". Rozmiar: " << s.size() << '\n';
    cout << r << ". Rozmiar: " << r.size();
    return 0;
}
