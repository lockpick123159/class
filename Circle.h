#pragma once
#include "Shape.h"
#include "Point.h"
class Circle : public Shape {
public:
	Circle(Point p, int rad) : x{p}, r{rad} {};

	Point center() const override
	{
		return x;
	}
	void move(Point to) override
	{
		x = to;
	}

	void draw() const override;
	void rotate(int) override {}
private:
	Point x;
	int r;
};
