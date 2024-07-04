#include <iostream>
#include <vector>
#include "Shape.h"
#include "Point.h"

enum class Kind {circle, triangle, smiley };

/* Shape* read_shape(std::istream& is) */
/* { */

/* 	switch(k) { */
/* 	case Kind::circle: */
/* 	{ */
/* 		Point p; */
/* 		double p_x p_y; */
/* 		int r; */
/* 		is >> p_x >> p_y >> r; */
/* 		p.x = p_x; */
/* 		p.y = p_y; */
/* 		return new Circle{p,r}; */
/* 	} */
/* 	case Kind::triange: */
/* 	{ */	
/* 		Point p1, p2, p3; */
/* 		double p1_x, p1_y; */
/* 		double p2_x, p2_y; */
/* 		double p3_x, p3_y; */

/* 		is >> p1_x >> p1_y; */	
/* 		is >> p2_x >> p2_y; */
/* 		is >> p3_x >> p3_y; */
		
/* 		p1.x = p1_x; */
/* 		p1.y = p1_y; */

/* 		p2.x = p2_x; */
/* 		p2.y = p2_y; */

/* 		p3.x = p3_x; */
/* 		p3.y = p3_y; */
/* 		return new Triangle{p1,p2,p3}; */
/* 	} */
/* 	case Kind::smiley: */	
/* 	{ */
/* 		Point p; */
/* 		int r; */
/* 		Shape e1, e2, m; */
/* 		is >> p >> r >> e1 >> e2 >> m; */
/* 		Smiley* ps = new Smiley{p,r}; */
/* 		ps->add_eye(e1); */
/* 		ps->add_eye(e2); */
/* 		ps->set_mouth(m); */
/* 		return ps; */
/* 	} */
/* } */

void rotate_all(std::vector<Shape*>& v, int angle)
{
	for(auto p : v)
		p->rotate(angle);
}
