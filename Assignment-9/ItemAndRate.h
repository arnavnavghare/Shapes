#pragma once
#include <iostream>

class ItemAndRate{
	std::string m_itemname, m_measurementunit;
	float m_rate;

public:
	//Constructor
	ItemAndRate(void);

	//Member functions
	void SetItemName(const std::string& Str);
	void SetItemRate(const float& rate);
	void SetMeasurementUnit(const std::string& Str);

	const std::string& GetItemName() const;
	float GetItemRate() const;
	const std::string& GetMeasurementUnit() const;

	//Destructor
	~ItemAndRate(void);
};

