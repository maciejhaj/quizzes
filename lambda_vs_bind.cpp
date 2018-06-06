#include <iostream>
#include <functional>
#include <vector>

template<typename T>
void print(T i, const std::string& s)
{
	std::cout << i << ' ' << s << '\n';
}

struct S
{
	int j = 2;	
	int do_something(const int i)
	{
		return j + i;
	}
};
//template<typename T>
int do_something(const std::string& t, const int i, const int j)
//int do_something(const int i, const int j)
{
	std::cout << t << '\n';
	return j + i;
}
int main()
{
	int i = 5;
	const auto f = [](const std::string& arg1, auto&& arg2)
	{
		print(arg2, arg1);
	};
	f("hello", i);
	i = 6;
	f("world", i);

	std::function<void (const std::string&, int)> f2(f);
	f2("test", 3);

	// jak zmienic zwracany typ void?
	std::function<void (const std::string&, int)> f3(f);

  
// invoke
	std::cout << std::invoke(&do_something, "hello", 1, 5) << '\n';
	S s;
	std::cout << s.do_something(3) << '\n';

	// wskaznik do funkcji do_something w S
	auto fp = &S::do_something;

	std::cout << (s.*fp)(3) << '\n';
	std::cout << std::invoke(s.fp, 3) << '\n';


	return 0;
}
