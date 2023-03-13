#include "StdAfx.h"
#include "FileHandling.h"
#include <fstream>
#include <sstream>

//--------------------------------------------------------------------------------

FileHandling::FileHandling(void){
}

//--------------------------------------------------------------------------------

void FileHandling::WriteToShapesFile (ShapesInALayout& const Layout){
	std::fstream WriteShapes ("ShapesInALayout.txt", std::ios::out | std::ios::trunc);
	for (int i=0; i<Layout.NumberofObjects(); i++){
		WriteShapes<<Layout.RetrieveShapeAndItem(i).first.GetIdentity()<<',';
		WriteShapes<<Layout.RetrieveShapeAndItem(i).first.GetUtility()<<',';
		WriteShapes<<Layout.RetrieveShapeAndItem(i).first.GetArea()<<',';
		WriteShapes<<Layout.RetrieveShapeAndItem(i).first.GetPerimeter()<<',';
		WriteShapes<<Layout.RetrieveShapeAndItem(i).second.GetItemName()<<',';
		WriteShapes<<Layout.RetrieveShapeAndItem(i).second.GetItemRate()<<',';
		WriteShapes<<Layout.RetrieveShapeAndItem(i).second.GetMeasurementUnit()<<'\n';
	}
	WriteShapes.close();
}

//--------------------------------------------------------------------------------

ShapesInALayout& FileHandling::ReadFromShapesFile (ShapesInALayout& Layout){
	std::string Line = " ", TempString = " ";
	
	Shape TempShape;
	ItemAndRate TempItem;

	std::fstream ReadShapes ("ShapesInALayout.txt", std::ios::in);
	while(std::getline(ReadShapes, Line)){
		std::stringstream SStream(Line);
		getline(SStream, TempString,',');
		TempShape.SetIdentity(TempString[0]);
		getline(SStream, TempString,',');
		TempShape.SetUtility(TempString.c_str());
		getline(SStream, TempString,',');
		TempShape.SetArea(atof(TempString.c_str()));
		getline(SStream, TempString,',');
		TempShape.SetPerimeter(atof(TempString.c_str()));

		getline(SStream, TempString,',');
		TempItem.SetItemName(TempString);
		getline(SStream, TempString,',');
		TempItem.SetItemRate(atof(TempString.c_str()));
		getline(SStream, TempString,',');
		TempItem.SetMeasurementUnit(TempString);

		Layout.AddShapeAndItem(TempShape,TempItem);
	}
	return Layout;
}

//--------------------------------------------------------------------------------

void FileHandling::WriteToItemsFile (ItemAndRateChart& const ItemAndRateChart){
	std::fstream WriteItems ("ItemAndRateChart.txt", std::ios::out | std::ios::trunc);
	for (int i=0; i<ItemAndRateChart.NumberofObjects(); i++){
		WriteItems<<ItemAndRateChart.RetrieveItemAndRate(i).GetItemName()<<',';
		WriteItems<<ItemAndRateChart.RetrieveItemAndRate(i).GetItemRate()<<',';
		WriteItems<<ItemAndRateChart.RetrieveItemAndRate(i).GetMeasurementUnit()<<'\n';
	}
	WriteItems.close();
}

//--------------------------------------------------------------------------------

ItemAndRateChart& FileHandling::ReadFromItemsFile (ItemAndRateChart& ItemAndRateChart){
	std::string Line = " ", TempString = " ";
	
	ItemAndRate TempItemAndRate;

	std::fstream ReadItems ("ItemAndRateChart.txt", std::ios::in);
	while(std::getline(ReadItems, Line)){
		std::stringstream SStream(Line);
		getline(SStream, TempString,',');
		TempItemAndRate.SetItemName(TempString);
		getline(SStream, TempString,',');
		TempItemAndRate.SetItemRate(atoi(TempString.c_str()));
		getline(SStream, TempString,',');
		TempItemAndRate.SetMeasurementUnit(TempString);
		ItemAndRateChart.AddItem(TempItemAndRate);
	}
	return ItemAndRateChart;
}

//--------------------------------------------------------------------------------

FileHandling::~FileHandling(void){
}

//--------------------------------------------------------------------------------
