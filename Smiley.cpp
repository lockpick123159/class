#include "Smiley.h"
#include "Circle.h"

void Smiley::draw() const
{
	Circle::draw();
	for(auto p : eyes)
		p->draw();
	mouth->draw();
}

/* void Smiley::rotate(int rad); */
