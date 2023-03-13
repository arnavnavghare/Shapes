#pragma once
#include "shape.h"

class Circle : public Shape{
private:
	//Data members
	static const char m_identity = 'C';
	float m_radius;

public:
	//Constructor
	Circle(float Radius);

	//Member function
	float Area() const;
	float Perimeter() const;
	char Identity() const;

	//Destructor
	~Circle(void);
};