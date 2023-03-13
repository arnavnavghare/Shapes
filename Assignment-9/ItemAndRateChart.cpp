#include "StdAfx.h"
#include "ItemAndRateChart.h"

//--------------------------------------------------------------------------------

ItemAndRateChart::ItemAndRateChart(void){
}

//--------------------------------------------------------------------------------

void ItemAndRateChart::AddItem(ItemAndRate& const ItemAndRate){
	m_itemandratechart.push_back(ItemAndRate);
}

//--------------------------------------------------------------------------------

void ItemAndRateChart::RemoveItemAndRate(const int& Index){
	m_itemandratechart.erase(m_itemandratechart.begin()+Index-1);
}

//--------------------------------------------------------------------------------

ItemAndRate& const ItemAndRateChart::RetrieveItemAndRate(const int& Index){
	return m_itemandratechart[Index];
}

//--------------------------------------------------------------------------------

int ItemAndRateChart::NumberofObjects() const{
	return m_itemandratechart.size();
}

//--------------------------------------------------------------------------------

ItemAndRateChart::~ItemAndRateChart(void){
}

//--------------------------------------------------------------------------------