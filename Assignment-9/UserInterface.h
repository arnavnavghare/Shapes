#pragma once
#include "AllShapes.h"
#include "ShapesInALayout.h"
#include "ItemAndRateChart.h"

class UserInterface{
public:
	//Constructor
	UserInterface(void);

	//Member functions
	void DisplayMainMenuSelectionOptions();
	void DisplayShapeSelectionOptions();
	void DisplayRemoveShapeStatement();
	void DisplayRemoveItemStatement();
	void DisplaySaveSuccessfulStatement();
	void DisplayEntryAddedSuccessfullyStatement();
	void DisplayRemoveSuccessfulStatement();
	void DisplayItemSelectionFromUser();

	int GetChoiceFromUser();
	std::string GetUtilityNameFromUser();

	ItemAndRate& CreateNewItem(ItemAndRate& Item);
	const ItemAndRate& GetItemSelectionFromUser(ItemAndRateChart& const ItemsAndRates, const int& Index);

	void ShowShapesInLayout(ShapesInALayout& const Layout);
	void ShowItemsInRateChart(ItemAndRateChart& const ItemAndRateChart);

	rectangle CreateRectangleUsingInputFromUser();
	Triangle CreateTriangleUsingInputFromUser();
	Circle CreateCircleUsingInputFromUser();

	float CostCalculator(ShapesInALayout& const Layout, int& const Index);

	//Destructor
	~UserInterface(void);
};