#include <string>
#include <iostream>
#include <algorithm>

using std::cout;

int main() 
{
    std::string s1{"challenge"};
    std::string s2{"my fav number is 69 and 420"};
    std::string s3{"do it_- right with* wierd char&acters !@"};

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), 
		s2.end(), 
		[](const char& a, const char& b) -> char {
		    //if ( a == ' ')
	//		return b;
	//	    else if ( b == ' ')
	//		return a;
		    return a < b;
		});
    s2.erase( std::remove_if(s2.begin(), 
				       s2.end(),
			       [](unsigned char x) 
			    {
				return std::isspace(x);
			    }), 
			    s2.end());
    std::sort(s3.begin(), s3.end());
    
    s3.erase( std::remove_if(s3.begin(), 
				       s3.end(),
			       [](unsigned char x) 
			    {
				return std::isspace(x);
			    }), 
			    s3.end());

    cout << s1 << '\n';
    cout << s2 << '\n';
    cout << s3 << '\n';

    return 0;
}
