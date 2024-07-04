#include <iostream>
#include <list>
#include "Container.h"

class List_container : public Container {
public:
	List_container() { }
	List_container(std::initializer_list<double> il) : ld{il} {}
	~List_container() {}

	double& operator[](int i) override;
	int size() const override { return ld.size(); }
private:
	std::list<double> ld;
};

void h();