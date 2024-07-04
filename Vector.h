#include <iostream>
double sqrt(double);

class Vector {
	private:
		double* elem;
		int sz;
	public:
		Vector(std::initializer_list<double>);
		Vector() {};
		~Vector() { delete[] elem; }

		Vector(const Vector& a);	    //copy constructor
		Vector& operator=(const Vector& a); //copy assignment
		
		Vector(Vector&& a);		//move constructor
		Vector& operator=(Vector&& a);	//move assignment
		
		friend Vector operator+(const Vector& a, const Vector& b);

		void push_back(double);
		explicit Vector(int s) :elem{new double[s]}, sz{s}
		{
			for(int i=0; i!=s; ++i)
				elem[i] = 0;
		}


		double& operator[](int i);
		const double& operator[](int i) const;

		int size() const { return sz; }
};


/* Vector f(); */
/* void hello(); */
/* Vector init(int n); */

/* void bad_copy(Vector); */
