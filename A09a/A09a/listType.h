#pragma once
const int MAX_SIZE = 100;
const int null = -99999;

struct listType {
	int list[MAX_SIZE];
	int count;
};

void initL(listType & L);
bool addL(listType & L, int newNum);
bool deleteL(listType & L, int listItem);
void displayL(listType L);
bool modifyL(listType & L, int listItem, int newNum);
int searchL(listType L, int searchValue, int count);
bool emptyL(listType L);
bool fullL(listType L);
bool clearL(listType & L);