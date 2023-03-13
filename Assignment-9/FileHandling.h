#pragma once
#include "ShapesInALayout.h"
#include "ItemAndRateChart.h"

class FileHandling
{
public:
	//Constructor
	FileHandling(void);

	//Member functions
	void WriteToShapesFile (ShapesInALayout& const Layout);
	ShapesInALayout& ReadFromShapesFile (ShapesInALayout& Layout);

	void WriteToItemsFile (ItemAndRateChart& const ItemAndRate);
	ItemAndRateChart& ReadFromItemsFile (ItemAndRateChart& ItemAndRate);

	//Destructor
	~FileHandling(void);
};

