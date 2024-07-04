#include "Vector.h"
#include "Buffer.h"
#include "Less_than.h"
#include "count.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <numeric>
int main()
{
    Vector<int> vec_integer{0, 1, 2, 3, 4, 5};
    Vector<double> vec_double{0.1, 0.2, 0.3, 0.4, 0.5};
    Vector<std::string> vec_msg{"hello", "world", "this", "is", "a", "message"};


    for(int i = 0; i != vec_integer.size(); ++i)
	    std::cout << vec_integer[i] << ' ';
    std::cout << '\n';

    for(int j = 0; j != vec_double.size(); ++j)
	    std::cout << vec_double[j] << ' ';
    std::cout << '\n';

    for(int k = 0; k != vec_msg.size(); ++k)
	    std::cout << vec_msg[k] << ' ';
    std::cout << '\n';

    Buffer<char, 1024> glob;


    std::strcpy(glob.buf, "hello, world");
    std::cout << glob.buf << '\n';

    std::pair<int, double> p1 = {1, 5.2};
    auto p2 = std::make_pair(1, 5.2);
    std::pair p3 = {1, 5.2};

    std::cout << p1.first << '\n';

    using namespace std::literals::string_literals;
    std::cout << "Function object" << '\n';
    Less_than lti {42};
    Less_than lts {"Backus"s};
    Less_than<std::string> lts2 {"Naur"};

    std::cout << lti(50) << '\n';
    std::cout << lts("America") << '\n';
    std::cout << lts2("Office") << '\n';

    std::vector<int> ivec(100);
    std::iota(ivec.begin(), ivec.end(), 0);

    std::list<std::string> sli{"hello,", "world!", "this", "is", "lockpick"};
    f(ivec, sli, 80, "man");

}
