#include <iostream>
#include "vec_container.h"
#include "list_container.h"
#include "Shape.h"
#include "Circle.h"
#include "Smiley.h"

/* Vector f() */
/* { */
/* 	Vector x(1000); */
/* 	Vector y(2000); */
/* 	Vector z(3000); */
/* 	z = x; */
/* 	y = std::move(x); */
	
/* 	std::cout << x.size() << '\n'; */
/* 	std::cout << y.size() << '\n'; */
/* 	std::cout << y.size() << '\n'; */
/* 	return z; */
/* } */

int main()
{
	Vector v1{1,3,6,10,15,21};
	Vector v2 = v1;
	Vector v1_plus_v2 = v1+v2;	

	for(int i = 0; i!=v1.size(); ++i)
	{
		std::cout << v1[i] << '\n';
		std::cout << v1_plus_v2[i] << '\n';

	}

	/* std::cout << "f()" << '\n'; */
	/* f(); */
	/* init(1000); */
}
