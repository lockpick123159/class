#include <cmath>
#include "Smiley.h"
#include "Circle.h"
#include <algorithm>

void Smiley::draw() const
{
	Circle::draw();
	for(auto p : eyes)
		p->draw();
	mouth->draw();
}

void Smiley::rotate(int rad)
{
	for_each(eyes.cbegin(), eyes.cend(), [=](Shape* eye){eye->rotate(rad);} );
	mouth->rotate(rad);
}
