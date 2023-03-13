#pragma once
#include <string>

class Shape{
private:
	//Data members
	char m_identity;
	std::string m_utility;
	float m_area, m_perimeter;

public:
	//Constructor
	Shape(void);

	//Member functions
	virtual float Area() const;
	virtual float Perimeter() const;
	virtual char Identity() const;

	void SetIdentity(const char& Identity);
	void SetUtility(const std::string& Str);
	void SetArea(const float& Area);
	void SetPerimeter(const float& Perimeter);

	const char GetIdentity(void) const;
	const std::string& GetUtility() const;
	float GetArea(void) const;
	float GetPerimeter(void) const;

	//Destructor
	~Shape(void);
};

