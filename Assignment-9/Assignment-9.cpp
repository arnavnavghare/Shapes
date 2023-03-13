#include "stdafx.h"
#include <iostream>
#include "AllShapes.h"
#include "ShapesInALayout.h"
#include "UserInterface.h"
#include "FileHandling.h"

using std::cout;
using std::endl;

int* fun(){
	int arr[5] = {1,5,6,4,7};
	return arr;
}

int main(){

	ShapesInALayout Layout;
	UserInterface UI;
	FileHandling FH;
	ItemAndRateChart ItemsAndRates;
	FH.ReadFromShapesFile(Layout);
	FH.ReadFromItemsFile(ItemsAndRates);

	enum CHOICE {ShowRateChart  = 1, AddItemToRateChart, RemoveItemFromRateChart, ShowAllShapesInTheLayout, AddNewShapeToTheLayout, RemoveAShapeFromTheLayout, SaveAll, SaveAndExit};
	enum SHAPE {Rec = 1, Tri, Cir};

	while(true){
		system("cls");
		UI.DisplayMainMenuSelectionOptions();
		int Choice = UI.GetChoiceFromUser();
		switch (Choice){
		case (CHOICE::ShowRateChart):{
			system("cls");
			UI.ShowItemsInRateChart(ItemsAndRates);
			system("pause");
			break;
			   }

		case (CHOICE::AddItemToRateChart):{
			system("cls");
			UI.ShowItemsInRateChart(ItemsAndRates);
			ItemAndRate Item;
			UI.CreateNewItem(Item);
			ItemsAndRates.AddItem(Item);
			system("cls");
			UI.DisplayEntryAddedSuccessfullyStatement();
			UI.ShowItemsInRateChart(ItemsAndRates);
			system("pause");
			break;
			   }

		case (CHOICE::RemoveItemFromRateChart):{
			system("cls");
			UI.ShowItemsInRateChart(ItemsAndRates);
			UI.DisplayRemoveItemStatement();
			ItemsAndRates.RemoveItemAndRate(UI.GetChoiceFromUser());
			system("cls");
			UI.DisplayRemoveSuccessfulStatement();
			UI.ShowItemsInRateChart(ItemsAndRates);
			system("pause");
			break;
			   }

		case (CHOICE::ShowAllShapesInTheLayout):{
			system("cls");
			UI.ShowShapesInLayout(Layout);
			system("pause");
			break;
			   }

		case (CHOICE::AddNewShapeToTheLayout):{
			system("cls");
			UI.ShowShapesInLayout(Layout);
			UI.DisplayShapeSelectionOptions();
			int Choice = UI.GetChoiceFromUser(); 
			Shape* ptr;
			Shape Shape;
			switch (Choice){
			case (SHAPE::Rec):{
				rectangle R = UI.CreateRectangleUsingInputFromUser();
				ptr = &R;
				Shape.SetIdentity(ptr -> Identity());
				Shape.SetUtility(UI.GetUtilityNameFromUser());
				Shape.SetArea(ptr -> Area());
				Shape.SetPerimeter(ptr -> Perimeter());
				break;
				   }

			case (SHAPE::Tri):{
				Triangle T = UI.CreateTriangleUsingInputFromUser();
				ptr = &T;
				Shape.SetIdentity(ptr -> Identity());
				Shape.SetUtility(UI.GetUtilityNameFromUser());
				Shape.SetArea(ptr -> Area());
				Shape.SetPerimeter(ptr -> Perimeter());
				break;
				   }

			case (SHAPE::Cir):{
				Circle C = UI.CreateCircleUsingInputFromUser();
				ptr = &C;
				Shape.SetIdentity(ptr -> Identity());
				Shape.SetUtility(UI.GetUtilityNameFromUser());
				Shape.SetArea(ptr -> Area());
				Shape.SetPerimeter(ptr -> Perimeter());
				break;
				   }
			}
			UI.ShowItemsInRateChart(ItemsAndRates);
			UI.DisplayItemSelectionFromUser();
			Layout.AddShapeAndItem(Shape, UI.GetItemSelectionFromUser(ItemsAndRates, UI.GetChoiceFromUser()-1));
			system("cls");
			UI.DisplayEntryAddedSuccessfullyStatement();
			UI.ShowShapesInLayout(Layout);
			system("pause");
			   }
			   break;

		case (CHOICE::RemoveAShapeFromTheLayout):{
			system("cls");
			UI.ShowShapesInLayout(Layout);
			UI.DisplayRemoveShapeStatement();
			Layout.RemoveShapeAndItem(UI.GetChoiceFromUser());
			system("cls");
			UI.DisplayRemoveSuccessfulStatement();
			UI.ShowShapesInLayout(Layout);
			system("pause");
			break;
			   }

		case (CHOICE::SaveAll):{
			system("cls");
			FH.WriteToShapesFile(Layout);
			FH.WriteToItemsFile(ItemsAndRates);
			UI.DisplaySaveSuccessfulStatement();
			system("pause");
			break;
			   }

		case (CHOICE::SaveAndExit):{
			FH.WriteToShapesFile(Layout);
			FH.WriteToItemsFile(ItemsAndRates);
			return 0;
			break;
			   }
		}
	}

return 0;
}