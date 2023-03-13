#pragma once
#include "shape.h"

class Triangle : public Shape{
private:
	//Data members
	static const char m_identity = 'T';
	float m_side1, m_side2, m_side3;

public:
	//Constructor
	Triangle(float Side1, float Side2, float Side3);

	//Member function
	float Area() const;
	float Perimeter() const;
	char Identity() const;

	//Destructor
	~Triangle(void);
};