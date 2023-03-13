#include "StdAfx.h"
#include "rectangle.h"

//--------------------------------------------------------------------------------

rectangle::rectangle(float Length, float Breadth){
	m_length = Length;
	m_breadth = Breadth;
}

//--------------------------------------------------------------------------------

float rectangle::Area() const{
	return (m_length*m_breadth);
}

//--------------------------------------------------------------------------------

float rectangle::Perimeter() const{
	return (2.0*(m_length+m_breadth));
}

//--------------------------------------------------------------------------------

char rectangle::Identity() const{
	return m_identity;
}

//--------------------------------------------------------------------------------

rectangle::~rectangle(void){
}

//--------------------------------------------------------------------------------