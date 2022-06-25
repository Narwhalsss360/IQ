#include <iostream>
#include "DataLib.h"

DataController::DataController()
	: firstInList(NULL), current(NULL), lastAdded(NULL)
{
}

void DataController::addData(DataType& d)
{
	if (firstInList == NULL)
	{
		firstInList = &d;
		lastAdded = &d;
		std::cout << "Added First DataType @ " << &d << '\n';
	}
	else
	{
		lastAdded->next = &d;
		lastAdded = &d;
		std::cout << "Added DataType @ " << &d << '\n';
	}

	d.next = NULL;
}

DataType* DataController::search(dataID id)
{
	current = firstInList;
	DataType* next;
	while (current)
	{
		if (current->id) return current;
		next = current->next;
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