#include <iostream>
#include "my_complex.h"

void f(myclass::complex z) {
	myclass::complex a {2.3};
	myclass::complex b {1/a};
	myclass::complex c {a+z*myclass::complex{1,2.3}};
	std::cout << c.real() << ' ' << c.imag() << '\n';
}
