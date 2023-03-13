#pragma once
#include "shape.h"

class rectangle : public Shape{
private:
	//Data members
	static const char m_identity = 'R';
	float m_length, m_breadth;

public:
	//Constructor
	rectangle();
	rectangle(float Length, float Breadth);

	//Member function
	float Area() const;
	float Perimeter() const;
	char Identity() const;

	//Destructor
	~rectangle(void);
};

