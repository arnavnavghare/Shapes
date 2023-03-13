#include "StdAfx.h"
#include "UserInterface.h"
#include "AllShapes.h"
#include <iostream>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//--------------------------------------------------------------------------------

UserInterface::UserInterface(void){
}

//--------------------------------------------------------------------------------

void UserInterface::DisplayMainMenuSelectionOptions(){
	int Choice = 0;
	string temp;
	cout<<endl << std::setw(12)<<std::right<< ' ' <<"**********************  WELCOME TO LAYOUT PLANNING SYSTEM  ***********************"<<std::endl<<std::endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Show rate chart                  -->   [1]"<<endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Add item to rate chart           -->   [2]"<<endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Remove item from rate chart      -->   [3]"<<endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Show all shapes in the layout    -->   [4]"<<endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Add new shape to the layout      -->   [5]"<<endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Remove a shape from the layout   -->   [6]"<<endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Save all                         -->   [7]"<<endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Save & Exit                      -->   [8]"<<endl;
	cout<<endl << std::setw(12)<<std::right<< ' ' <<"**********************************************************************************"<<std::endl<<std::endl; 
	cout<<std::setw(30)<<std::right<<'\t'<<"Make choice from above options   -->    ";
}

//--------------------------------------------------------------------------------

void UserInterface::DisplayShapeSelectionOptions(){
	int Choice = 0;
	string temp;
	cout<<"Add Rectangle  -->  [1]"<<endl;
	cout<<"Add Triangle   -->  [2]"<<endl;
	cout<<"Add Circle     -->  [3]"<<endl;
	cout<<"Make choice of shape from above options --> ";
}

//--------------------------------------------------------------------------------

void UserInterface::DisplayRemoveShapeStatement(){
	cout<< "Enter the shape number to remove = ";
}

//--------------------------------------------------------------------------------

void UserInterface::DisplayRemoveItemStatement(){
	cout<< "Enter the item number to remove = ";
}

//--------------------------------------------------------------------------------

void UserInterface::DisplayEntryAddedSuccessfullyStatement(){
	cout<< "Entry added successfully!"<<endl;
}

//--------------------------------------------------------------------------------

void UserInterface::DisplaySaveSuccessfulStatement(){
	cout<< "Data Saved Successfully!"<<endl;
}

//--------------------------------------------------------------------------------

void UserInterface::DisplayRemoveSuccessfulStatement(){
	cout<< "Entry removed Successfully!"<<endl<<endl;
}

//--------------------------------------------------------------------------------

void UserInterface::DisplayItemSelectionFromUser(){
	cout<< "Enter item selection = ";
}

//--------------------------------------------------------------------------------

int UserInterface::GetChoiceFromUser() {
	std::string str;
	int Choice = 0;
	getline(std::cin, str);
	Choice = (atoi(str.c_str()));
	return Choice;
}

//--------------------------------------------------------------------------------

std::string UserInterface::GetUtilityNameFromUser(){
	std::string Str;
	cout<<"Enter utility type = ";
	getline(std::cin, Str);
	return Str;
}

//--------------------------------------------------------------------------------

ItemAndRate& UserInterface::CreateNewItem(ItemAndRate& Item){
	std::string itemname, measurementunit, tempstring;
	float rate;
	cout<<"Enter item name = ";
	getline(cin,itemname);
	Item.SetItemName(itemname);
	cout<<"Enter item rate = ";
	getline(cin,tempstring);
	rate = atof(tempstring.c_str());
	Item.SetItemRate(rate);
	cout<<"Enter measurement unit = ";
	getline(cin,measurementunit);
	Item.SetMeasurementUnit(measurementunit);
	return Item;
}

//--------------------------------------------------------------------------------

const ItemAndRate& UserInterface::GetItemSelectionFromUser(ItemAndRateChart& const ItemsAndRates, const int& Index){
	return ItemsAndRates.RetrieveItemAndRate(Index);
}

//--------------------------------------------------------------------------------

void UserInterface::ShowShapesInLayout(ShapesInALayout& const Layout){
	int Total = 0;

	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<std::setw(04)<<std::left<<"|"<<std::setw(7)<<std::right<<"Sr. No."<<'\t'<<std::setw(10)<<"Shape"<<'\t'<<std::setw(10)<<"Utility"<<'\t'<<std::setw(10)<<"Area"<<'\t'<<std::setw(10)<<"Perimeter"<<'\t'<<std::setw(10)<<"Type"<<'\t'<<std::setw(10)<<"Rate"<<'\t'<<std::setw(10)<<"Unit"<<'\t'<<std::setw(13)<<"Cost in Rs"<<std::setw(04)<<std::right<<"|"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	for (int i=0; i<Layout.NumberofObjects(); i++){
		cout<<std::setw(04)<<std::left<<"|"<<std::setw(04)<<std::right<<i+1<<std::setw(16)<<Layout.RetrieveShapeAndItem(i).first.GetIdentity()<<'\t'<<"   ";
		cout<<std::setw(12)<<std::left<<Layout.RetrieveShapeAndItem(i).first.GetUtility()<<'\t';
		cout<<std::setw(8)<<std::right<<Layout.RetrieveShapeAndItem(i).first.GetArea()<<" sq.m";
		cout<<std::setw(10)<<std::right<<Layout.RetrieveShapeAndItem(i).first.GetPerimeter()<<" m         ";
		cout<<std::setw(8)<<std::left<<Layout.RetrieveShapeAndItem(i).second.GetItemName()<<'\t';
		cout<<std::setw(10)<<std::right<<Layout.RetrieveShapeAndItem(i).second.GetItemRate()<<'\t';
		cout<<std::setw(10)<<std::right<<Layout.RetrieveShapeAndItem(i).second.GetMeasurementUnit()<<'\t';
		cout<<std::setw(10)<<std::right<<std::fixed<<std::setprecision(0)<<ceil(UserInterface::CostCalculator(Layout,i))<<" Rs"<<std::setw(04)<<std::right<<"|"<<'\n';
		Total = Total + ceil(UserInterface::CostCalculator(Layout,i));
	}
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<std::setw(04)<<std::left<<"|"<<std::setw(120)<<std::left<< "The total quote cost is = "<<std::setw(14)<<std::right<<std::fixed<<std::setprecision(0)<<Total<<" Rs"<<std::setw(04)<<std::right<<"|"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

}
  
//--------------------------------------------------------------------------------

void UserInterface::ShowItemsInRateChart(ItemAndRateChart& const ItemAndRateChart){
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<std::setw(04)<<std::left<<"|"<<std::setw(7)<<std::right<<"Sr. No."<<'\t'<<'\t'<<std::setw(10)<<std::left<<"Item"<<'\t'<<'\t'<<std::setw(10)<<std::left<<"Rate"<<'\t'<<'\t'<<std::setw(4)<<std::left<<"Unit"<<std::setw(04)<<std::right<<"|"<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	for (int i=0; i<ItemAndRateChart.NumberofObjects(); i++){
		cout<<std::setw(04)<<std::left<<"|"<<std::setw(04)<<std::right<<i+1<<"            "<<std::setw(15)<<std::left<<ItemAndRateChart.RetrieveItemAndRate(i).GetItemName();
		cout<<std::setw(17)<<std::right<<ItemAndRateChart.RetrieveItemAndRate(i).GetItemRate()<<'\t'<<'\t';
		cout<<std::setw(12)<<std::right<<ItemAndRateChart.RetrieveItemAndRate(i).GetMeasurementUnit()<<std::setw(04)<<std::right<<"|"<<'\n';
	}
	cout<<"--------------------------------------------------------------------------------"<<endl;
}

//--------------------------------------------------------------------------------

rectangle UserInterface::CreateRectangleUsingInputFromUser(){
	float Length = 0, Breadth = 0;
	string temp;
	cout<<"Enter length of Rectangle (In Meters) = ";
	std::getline(cin,temp);
	Length = atoi(temp.c_str());
	cout<<"Enter breadth of Rectangle (In Meters) = ";
	std::getline(cin,temp);
	Breadth = atoi(temp.c_str());
	rectangle Rectangle(Length, Breadth);
	return Rectangle;
}

//--------------------------------------------------------------------------------

Triangle UserInterface::CreateTriangleUsingInputFromUser(){
	int Side1 = 0, Side2 = 0, Side3 = 0;
	string temp;
	cout<<"Enter length of first side of Triangle (In Meters) = ";
	std::getline(cin,temp);
	Side1 = atoi(temp.c_str());
	cout<<"Enter length of second side of Triangle (In Meters) = ";
	std::getline(cin,temp);
	Side2 = atoi(temp.c_str());
	cout<<"Enter length of third side of Triangle (In Meters) = ";
	std::getline(cin,temp);
	Side3 = atoi(temp.c_str());
	Triangle Triangle(Side1, Side2, Side3);
	return Triangle;
}

//--------------------------------------------------------------------------------

Circle UserInterface::CreateCircleUsingInputFromUser(){
	int Radius = 0;
	string temp;
	cout<<"Enter radius of Circle (In Meters) = ";
	std::getline(cin,temp);
	Radius = atoi(temp.c_str());
	Circle Circle(Radius);
	return Circle;
}

//--------------------------------------------------------------------------------

float UserInterface::CostCalculator(ShapesInALayout& const Layout, int& const Index){
	if(Layout.RetrieveShapeAndItem(Index).second.GetMeasurementUnit() == "Rs/sq.m"){
		return (Layout.RetrieveShapeAndItem(Index).first.GetArea()*Layout.RetrieveShapeAndItem(Index).second.GetItemRate());
	}
	else if(Layout.RetrieveShapeAndItem(Index).second.GetMeasurementUnit() == "Rs/m"){
		return (Layout.RetrieveShapeAndItem(Index).first.GetPerimeter()*Layout.RetrieveShapeAndItem(Index).second.GetItemRate());
	}
	else{
		cout<<"Invalid Unit!"<<endl;
	}
}

//--------------------------------------------------------------------------------

UserInterface::~UserInterface(void){
}

//--------------------------------------------------------------------------------