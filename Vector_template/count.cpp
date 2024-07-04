#include <iostream>
#include "count.h"
#include "Less_than.h"

void f(const std::vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s)
{
	std::cout << "number of values less than " << x << ": " << count(vec, [&x](int a){return a<x;}) << '\n';
	std::cout << "number of values less than " << s << ": " << count(lst, [&s](const std::string& a){return a<s;}) << '\n';
}
