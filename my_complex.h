namespace myclass {
	class complex {
		double re, im; // representation: two doubles
		public:
		complex(double r, double i) :re{r}, im{i} {} // construct complex from two scalars
		complex(double r) :re{r} {} // construct complex from one scalar
		complex() {} // default complex: {0,0}
	double real() const { return re; }
	void real(double d) { re=d; }
	double imag() const { return im; }
	void imag(double d) { im=d; }

	complex& operator+=(complex z)
	{
		re+=z.re; // add to re and im
		im+=z.im;
		return *this; // and return the result
	}
	complex& operator-=(complex z)
	{
		re-=z.re;
		im-=z.im;
		return *this;
	}
	complex& operator*=(complex z)
	{
		re = re * z.re - im * z.im;
		im = re * z.im + im * z.re;
		return *this;
	}
	complex& operator/=(complex z)
	{
		re = (re * z.re + im * z.im) / (z.re * z.re + z.im * z.im);
		im = (im * z.re - re * z.im) / (z.re * z.re + z.im * z.im);
		return *this;
	}

	};

	myclass::complex operator+(myclass::complex a, myclass::complex b) { return a+=b; }
	myclass::complex operator-(myclass::complex a, myclass::complex b) { return a-=b; }
	myclass::complex operator-(myclass::complex a) { return {-a.real(), -a.imag()}; }
	myclass::complex operator*(myclass::complex a, myclass::complex b) { return a*=b; }
	myclass::complex operator/(myclass::complex a, myclass::complex b) { return a/=b; }

	bool operator==(myclass::complex a, myclass::complex b)
	{
		return a.real()==b.real() && a.imag()==b.imag();
	}

	bool operator!=(myclass::complex a, myclass::complex b)
	{
		return !(a==b);
	}
};

void f(myclass::complex);
