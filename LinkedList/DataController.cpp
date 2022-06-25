#include <iostream>
#include "DataLib.h"

DataController::DataController()
	: firstInList(NULL), current(NULL), lastAdded(NULL)
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
		lastAdded->next = &d;
	}

	lastAdded = &d;
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

void DataController::operator+=(DataType& d)
{
	addData(d);
}

specialData DataController::get(dataID id)
{
	return search(id)->data;
}

specialData DataController::operator<<(dataID id)
{
	return get(id);
}

DataController::~DataController()
{
}