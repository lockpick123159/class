#include "Circle.h"
#include <iostream>
#include <cmath>
void Circle::draw() const
{
	std::cout << "Circle drawn!" << '\n';
}

void Circle::rotate(int rad)
{	
	x.x = x.x * std::cos(rad) - x.y * std::sin(rad);
	x.y = x.x * std::sin(rad) + x.y * std::cos(rad);
}
