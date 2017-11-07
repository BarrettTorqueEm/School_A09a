#include <iostream>
#include "listType.h"

using namespace std;

int displayMenu(); //prototype for menu choice

int main()
{
	int choice;
	bool success;
	int itemToAdd;

	listType theList; //create the list (uninitialized)

	do
	{
		choice = displayMenu();
		switch (choice)
		{
		case 0: //exit
			cout << "Thank you, good bye.\n";
			break;
		case 1: //initalize
			initL(theList);
			cout << "List initalized\n";
			break;
		case 2: //add
			cout << "Enter item to add: ";
			cin >> itemToAdd;
			success = addL(theList, itemToAdd);
			if (success)
				cout << "add worked...";
			else
				cout << "unsuccessful add";
			cout << endl;
			break;
		case 3: //delete
			int listItem;

			cout << "Which list item would you like to delete?\n";
			cin >> listItem;

			//Subtract 1 to change from NLI to the real list item
			listItem--;

			if (listItem < theList.count)
			{
				if (deleteL(theList, listItem))
				{
					cout << "Item deleted successfully.\n";
				}
				else
				{
					cout << "There was an error the item did not delete.\n";
				}
			}
			else
			{
				cout << "That list item does not exist.\n";
			}

			break;
		case 4: //display
			displayL(theList);
			cout << endl;
			break;
		case 5: //modify
			int newNum;
			cout << "Which list item would you like to modify?\n";
			cin >> listItem;
			cout << "What is the new value?\n";
			cin >> newNum;

			if (modifyL(theList, (listItem-1), newNum) == true)
			{
				cout << "Modify success..\n";
			}
			else
			{
				cout << "Modify unsuccessful..\n";
			}
			break;
		case 6: //search for value
			int searchValue, j, cont;
			listType returnedList;

			//Inizilization
			cont, j, returnedList.count = 0;
			
			cout << "What is the value you wish to search for?\n";
			cin >> searchValue;
			
			//Checks the list then adds the list index to a temp list
			for (int i = 0; i < theList.count; i++)
			{
				
				addL(returnedList, searchL(theList, searchValue, i));
				j++;
			}

			//Reads thru temp list and prints out the index value (as long as its not the 'null' value of -99999
			for (int i = 0; i < returnedList.count; i++)
			{
				if (returnedList.list[i] != null)
				{
					cout << "The index of the search value in the list is " << returnedList.list[i] << "\n";
					cont = 1;
				}
			}

			//If no value was found prints out.
			if (cont != 1) 
			{
				cout << "The search value was not found in the list.\n";
			}

			//resets control
			cont = 0;

			break;
		case 7: //List Empty?

			if (emptyL(theList))
			{
				cout << "The list is empty.\n";
			}
			else
			{
				cout << "The list is not emtpy.\n";
			}

			break;
		case 8: //List Full?

			if (fullL(theList))
			{
				cout << "The list is full.\n";
			}
			else
			{
				cout << "The list is not full.\n";
			}

			break;
		case 9: //Clear list
			
			if (clearL(theList))
			{
				cout << "List successfully cleared.\n";
			}
			else
			{
				cout << "The list was not cleared, an error orrcured.\n";
			}

			break;
		case 10:
			cout << "There are " << theList.count << " items in the list.\n";
			break;
		default:
			cout << "not yet supported choice..\n";
			break;

		}//end switch
	} while (choice != 0);


	system("pause");
	return 0;
}//end main

int displayMenu()
{
	int choice;
	cout << endl;
	cout << "choice 1: Initalize list MUST RUN BEFORE ANYTHING ELSE " << endl;
	cout << "choice 2: add" << endl;
	cout << "choice 3: delete from the list" << endl;
	cout << "choice 4: display" << endl;
	cout << "choice 5: modify a list item" << endl;
	cout << "choice 6: search for a list item" << endl;
	cout << "choice 7: Is the list empty?" << endl;
	cout << "choice 8: Is the list full?" << endl;
	cout << "choice 9: clear the list" << endl;
	cout << "choice 10: how many items are on the list" << endl;
	cout << "enter 0 to quit." << endl;

	cin >> choice;
	return choice;
}