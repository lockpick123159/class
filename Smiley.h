#include "Circle.h"
#include "Point.h"
class Smiley : public Circle {
public:
	Smiley(Point p, int rad) : Circle{p,rad}, mouth{nullptr} {}

	~Smiley()
	{
		delete mouth;
		for(auto p : eyes)
			delete p;
	}	

	void move(Point to) override {}
	
	void draw() const override;
	void rotate(int) override;

	void add_eye(Shape* s)
	{
		eyes.push_back(s);
	}
	void set_mouth(Shape* s) {}
	virtual void wink(int i) {}

	// ...

private:
	std::vector<Shape*> eyes;
	Shape* mouth;
};
