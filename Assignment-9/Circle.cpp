#include "StdAfx.h"
#include "Circle.h"
#define pi (float)22/7

//--------------------------------------------------------------------------------

Circle::Circle(float Radius){
	m_radius = Radius;
}

//--------------------------------------------------------------------------------

float Circle::Area() const{
	return (pi*(m_radius*m_radius));
}

//--------------------------------------------------------------------------------

float Circle::Perimeter() const{
	return (pi*(2*m_radius));
}

//--------------------------------------------------------------------------------

char Circle::Identity() const{
	return m_identity;
}

//--------------------------------------------------------------------------------

Circle::~Circle(void){
}

//--------------------------------------------------------------------------------