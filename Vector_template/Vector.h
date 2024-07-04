#include <stdexcept>
double sqrt(double);

template<typename T>
class Vector {
	private:
		T* elem;
		int sz;
	public:
		Vector(std::initializer_list<T>);
		Vector() {};	
		~Vector() { delete[] elem; }

		Vector(const Vector<T>& a);	    //copy constructor
		Vector& operator=(const Vector<T>& a); //copy assignment
		
		Vector(Vector<T>&& a);		//move constructor
		Vector& operator=(Vector<T>&& a);	//move assignment
		
		friend Vector<T> operator+(const Vector<T>& a, const Vector<T>& b);

		void push_back(T);
		explicit Vector(int s) :elem{new T[s]}, sz{s}
		{
			for(int i=0; i!=s; ++i)
				elem[i] = 0;
		}


		T& operator[](int i);
		const T& operator[](int i) const;

		int size() const { return sz; }
};

template<typename T>
T& Vector<T>::operator[](int i)
{
	return elem[i];
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
	return elem[i];
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> lst)
	:elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())}
{
	std::copy(lst.begin(), lst.end(), elem);
}

template<typename T>
void Vector<T>::push_back(T s)
{
	//this will be implemented in later chapters.
}

/* void bad_copy(Vector v1) */
/* { */
/* 	Vector v2 = v1; */
/* 	v1[0] = 2; */
/* 	v2[1] = 3; */
/* } */

template<typename T>
Vector<T>::Vector(const Vector<T>& a)
	:elem{new T[a.sz]},
	sz{a.sz}
{
	for(int i =0; i!=sz; ++i)
		elem[i] = a.elem[i];
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
	T* p = new T[a.sz];
	for (int i = 0; i!=a.sz; ++i)
		p[i] = a.elem[i];
	delete[] elem;
	elem = p;
	sz = a.sz;
	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& a)
{
	elem = a.elem;
	sz = a.sz;

	a.elem = nullptr;
	a.sz = 0;

	return *this;
}

template<typename T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b)
{
	if(a.size() != b.size())
		throw std::logic_error("Two vectors are not the same length!");
	
	Vector res(a.size());

	for(int i = 0; i!=a.size(); ++i)
		res[i] = a[i] + b[i];
	return res;
}

template<typename T>
Vector<T>::Vector(Vector<T>&& a)
	:elem{a.elem},
	sz{a.sz}
{
	a.elem = nullptr;
	a.sz = 0;
}

/*void heartbeat() {
	std::cout << "Thread Id: " << std::this_thread::get_id() << '\n';
}

std::vector<std::thread> my_threads;
*/

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
