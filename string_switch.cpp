#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <functional>

class StringSwitch
{
	public:
	// set function for our cases	
		std::function<void()>& Case(std::string str)
		{
			return map[str];
		}
		std::function<void()>& Default() 
		{
			return def;
		}
		// switch on a string
		// [] are not const member, so they cannot be called in this 
		// member function
		void operator[](const std::string& str) const
		{
			auto i = map.find(str);
			if ( i != map.end() )
			{
				i->second();
			}
			else
			{
				def();
			}
		}
	private:
		std::function<void()> def = [](){};
		std::unordered_map<std::string, std::function<void()>> map;
};

int main() 
{
	StringSwitch sw;
	sw.Case("asd") = [](){ std::cout << "asd" << '\n';};
	sw.Case("qwe") = [](){ std::cout << "qwe" << '\n';};
	sw.Case("DEF") = [](){ std::cout << "DEF" << '\n';};
	sw.Default() = [](){ std::cout << "Default()" << '\n';};	

	sw["asd"];
	sw["ASD"];

return 0;
}

