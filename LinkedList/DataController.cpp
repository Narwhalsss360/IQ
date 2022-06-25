#include "DataLib.h"

DataController::DataController()
	: first(NULL), current(NULL), last(NULL)
{
}

void DataController::addData(DataType& d)
{
	if (first == NULL)
	{
		first = &d;
		d.previous = NULL;
	}
	else
	{
		d.previous = last;
		last->next = &d;
	}

	d.next = NULL;
	last = &d;
}

DataType* DataController::search(dataID id)
{
	current = first;
	DataType* next;
	while (current)
	{
		if (current->id) return current;
		next = current->next;
	}
	return NULL;
}

void DataController::deleteData(DataType& d)
{
	if (d.previous == NULL)
	{
		if (d.next == NULL)
		{
			first = NULL;
			last = NULL;
			return;
		}
		else
		{
			d.previous->next = NULL;
			first = d.next;
			d.next = NULL;
			return;
		}
	}

	if (d.next == NULL)
	{
		d.previous->next = NULL;
		last = d.previous;
		d.previous = NULL;
		return;
	}

	d.previous->next = d.next;
	d.next->previous = d.previous;
	d.previous = NULL;
	d.next = NULL;
}

void DataController::deleteData(dataID id)
{
	deleteData(*search(id));
}

void DataController::operator+=(DataType& d)
{
	addData(d);
}

void DataController::operator-=(DataType& d)
{
	deleteData(d);
}

DataType* DataController::operator<<(dataID id)
{
	return search(id);
}

DataController::~DataController()
{
}