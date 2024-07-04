#include <iostream>
#include <stdexcept>
#include <thread>
#include <vector>
#include "Vector.h"

double& Vector::operator[](int i)
{
	return elem[i];
}

const double& Vector::operator[](int i) const
{
	return elem[i];
}

Vector::Vector(std::initializer_list<double> lst)
	:elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
{
	std::copy(lst.begin(), lst.end(), elem);
}

void Vector::push_back(double s)
{
	//this will be implemented in later chapters.
}

/* void bad_copy(Vector v1) */
/* { */
/* 	Vector v2 = v1; */
/* 	v1[0] = 2; */
/* 	v2[1] = 3; */
/* } */

Vector::Vector(const Vector& a)
	:elem{new double[a.sz]},
	sz{a.sz}
{
	for(int i =0; i!=sz; ++i)
		elem[i] = a.elem[i];
}

Vector& Vector::operator=(const Vector& a)
{
	double* p = new double[a.sz];
	for (int i = 0; i!=a.sz; ++i)
		p[i] = a.elem[i];
	delete[] elem;
	elem = p;
	sz = a.sz;
	return *this;
}

Vector& Vector::operator=(Vector&& a)
{
	elem = a.elem;
	sz = a.sz;

	a.elem = nullptr;
	a.sz = 0;

	return *this;
}

Vector operator+(const Vector& a, const Vector& b)
{
	if(a.size() != b.size())
		throw std::logic_error("Two vectors are not the same length!");
	
	Vector res(a.size());

	for(int i = 0; i!=a.size(); ++i)
		res[i] = a[i] + b[i];
	return res;
}

Vector::Vector(Vector&& a)
	:elem{a.elem},
	sz{a.sz}
{
	a.elem = nullptr;
	a.sz = 0;
}

void heartbeat() {
	std::cout << "Thread Id: " << std::this_thread::get_id() << '\n';
}

std::vector<std::thread> my_threads;

/* Vector init(int n) */
/* { */
/* 	std::thread t {heartbeat}; */
/* 	t.join(); */
/* 	my_threads.push_back(std::move(t)); */

/* 	Vector vec(n); */
/* 	for(int i=0; i!=vec.size(); ++i) */
/* 		vec[i] = 777; */
/* 	return vec; */
/* } */
