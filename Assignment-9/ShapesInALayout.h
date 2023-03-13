#pragma once
#include<vector>
#include "Shape.h"
#include "ItemAndRate.h"

class ShapesInALayout{
	//Data members
	std::vector <std::pair<Shape,ItemAndRate>> m_shapesInALayout;

public:
	//Constructor
	ShapesInALayout(void);

	//Member functions
	void AddShapeAndItem(const Shape& Shape, const ItemAndRate& Item);
	void RemoveShapeAndItem(const int& Index);
	std::pair<Shape, ItemAndRate>& const RetrieveShapeAndItem(const int& Index);
	int NumberofObjects() const;

	//Destructor
	~ShapesInALayout(void);
};