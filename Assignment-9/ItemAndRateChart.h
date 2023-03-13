#pragma once
#include "ItemAndRate.h"
#include <vector>

class ItemAndRateChart{
	std::vector <ItemAndRate> m_itemandratechart;
public:
	//Constructor
	ItemAndRateChart(void);

	//Member functions
	void AddItem(ItemAndRate& const ItemAndRate);
	void RemoveItemAndRate(const int& Index);
	ItemAndRate& const RetrieveItemAndRate(const int& Index);
	int NumberofObjects() const;

	//Destructor
	~ItemAndRateChart(void);
};

