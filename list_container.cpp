#include <exception>
#include "list_container.h"
#include "Container.h"

double& List_container::operator[](int i)
{
	for(auto& x : ld) {
		if(i == 0)
			return x;
		--i;
	}
	throw std::out_of_range{"List container"};
}

void h()
{
	List_container lc = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	use(lc);
}