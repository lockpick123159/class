#include <list>
#include <string>
#include <vector>

template<typename C, typename P>

int count(const C& c, P pred)
{
	int cnt = 0;
	for(const auto& x : c)
		if(pred(x))
			++cnt;
	return cnt;
}

void f(const std::vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s);
