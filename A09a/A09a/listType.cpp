#include <iostream>
#include "listType.h"

using namespace std;

//initalize list
void initL(listType & L)
{
	L.count = 0;
}

//Add to list
bool addL(listType & L, int newNum)
{
	if (!fullL(L))
	{
		L.list[L.count] = newNum;
		L.count++;

		return true;
	}
	else
	{
		return false;
	}
}

//Delete from the list
bool deleteL(listType & L, int listItem)
{
	int tempCount = L.count;

	L.list[listItem] = null;
	//L.count--;

	for (int i = listItem; i < L.count; i++)
	{
		L.list[i] = L.list[i + 1];
	}

	L.count--;

	if (L.count != tempCount) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Display list
void displayL(listType L)
{
	cout << "Displaying " << L.count << " items. \n";

	for (int i = 0; i < L.count; i++)
	{
		if (L.list[i] != null)
		{
			cout << "Item " << i + 1 << " = " << L.list[i] << "\n";
		}
	}
}

//Modify selected item in list
bool modifyL(listType & L, int listItem, int newNum)
{
	L.list[listItem] = newNum;

	return true;
}

//Search for values in list
int searchL(listType L, int searchValue, int count)
{
	while(count < L.count)
	{
		if (searchValue == L.list[count])
		{
			return count;
		}
		else
		{
			//Need to find the 'null' value to replace
			return null;
		}
	}
}

//Is the list empty? returns true for yes, false for no.
bool emptyL(listType L)
{
	if (L.count == 0)
	{
		return true;
	}
	else return false;
}

//Is the list full? returns true for yes, false for no.
bool fullL(listType L)
{
	if (L.count == MAX_SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Clears the list. 
bool clearL(listType & L)
{
	for (int i = 0; i < L.count; i++)
	{
		L.list[i] = null;
	}

	L.count = 0;

	return true;
}