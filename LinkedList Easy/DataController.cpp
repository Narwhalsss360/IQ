#include <iostream>
#include "DataLib.h"

DataController::DataController()
	: firstInList(NULL), current(NULL)
{
}

void DataController::addData(DataType& d)
{
	d.next = NULL; //Next of new is always Nothing.

	if (firstInList == NULL)
	{
		firstInList = &d;
	}
	else
	{
		end()->next = &d;
	}
}

DataType* DataController::search(dataID id)
{
	current = firstInList; //Start at beginning.
	while (current)
	{
		if (current->id == id) return current;
		else current = current->next; //Go to next item.
	}
	return NULL;
}

DataType* DataController::begin()
{
	return firstInList;
}

DataType* DataController::end()
{
	current = firstInList;
	while (current)
	{
		if (current->next == NULL) return current;
		current = current->next;
	}
	return NULL;
}

specialData DataController::get(dataID id)
{
	return search(id)->data;
}

void DataController::operator+=(DataType& d)
{
	addData(d);
}

specialData DataController::operator<<(dataID id)
{
	return get(id);
}

DataController::~DataController()
{
}