#include "StdAfx.h"
#include "ShapesInALayout.h"
#include "FileHandling.h"

//--------------------------------------------------------------------------------

ShapesInALayout::ShapesInALayout(void){
}

//--------------------------------------------------------------------------------

void ShapesInALayout::AddShapeAndItem(const Shape& Shape1, const ItemAndRate& Item){
	std::pair <Shape, ItemAndRate> Obj;
	Obj.first = Shape1;
	Obj.second = Item;
	m_shapesInALayout.push_back(Obj);
}

void ShapesInALayout::RemoveShapeAndItem(const int& Index){
	m_shapesInALayout.erase(m_shapesInALayout.begin()+Index-1);
}

//--------------------------------------------------------------------------------

std::pair<Shape, ItemAndRate>& const ShapesInALayout::RetrieveShapeAndItem(const int& Index){
	return m_shapesInALayout[Index];
}

//--------------------------------------------------------------------------------

int ShapesInALayout::NumberofObjects() const{
	return ShapesInALayout::m_shapesInALayout.size();
}

//--------------------------------------------------------------------------------

ShapesInALayout::~ShapesInALayout(void){
}

//--------------------------------------------------------------------------------