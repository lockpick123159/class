#pragma once
#include "Point.h"
#include <vector>
#include <algorithm>
class Shape {
public:
	Shape() =default;
	Shape(const Shape&) =delete;
	Shape& operator=(const Shape&) =delete;

	virtual Point center() const =0;
	virtual void move(Point to) =0;

	virtual void draw() const = 0;
	virtual void rotate(int angle) = 0;

	virtual ~Shape() {}
};

void rotate_all(std::vector<Shape*>& v, int angle);

template<class S>
void rotate_and_draw(std::vector<S>& v, int r)
{
	for_each(v.begin(), v.end(), [=](auto& s){s->rotate(r); s->draw(); });
}
