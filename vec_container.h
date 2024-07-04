#include "Vector.h"
#include "Container.h"

class Vector_container : public Container {
public:
	Vector_container(int s) : v(s) { }
	~Vector_container() {}

	double& operator[](int i) override { return v[i]; }
	int size() const override { return v.size(); }
private:
	Vector v;
};
