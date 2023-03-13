#include "StdAfx.h"
#include "ItemAndRate.h"

//--------------------------------------------------------------------------------

ItemAndRate::ItemAndRate(void){
}
//--------------------------------------------------------------------------------

void ItemAndRate::SetItemName(const std::string& Str){
	m_itemname = Str;
}

//--------------------------------------------------------------------------------

void ItemAndRate::SetItemRate(const float& rate){
	m_rate = rate;
}

//--------------------------------------------------------------------------------

void ItemAndRate::SetMeasurementUnit(const std::string& Str){
	m_measurementunit = Str;
}

//--------------------------------------------------------------------------------

const std::string& ItemAndRate::GetItemName() const{
	return m_itemname;
}

//--------------------------------------------------------------------------------

float ItemAndRate::GetItemRate() const{
	return m_rate;
}

//--------------------------------------------------------------------------------

const std::string& ItemAndRate::GetMeasurementUnit() const{
	return m_measurementunit;
}

//--------------------------------------------------------------------------------

ItemAndRate::~ItemAndRate(void){
}

//--------------------------------------------------------------------------------