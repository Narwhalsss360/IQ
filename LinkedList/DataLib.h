#pragma once

#include <stdint.h>

typedef uint16_t dataID;

class DataType
{
public:
	DataType();
	DataType(dataID, uint64_t);
	void set(uint64_t);
	uint64_t get();
	uint16_t getID();
	~DataType();

private:
	friend class DataController;
	DataType* previous, *next; //Previous & next DataType in list.
	dataID id; //unique identifier.
	uint64_t data;
};

class DataController
{
public:
	DataController();
	~DataController();
	void addData(DataType&); //Add a instance to linked list.
	DataType* search(dataID); //Get pointer to instance with id.
	void deleteData(DataType&); //Removes data from linked list.
	void deleteData(dataID); //Same but ID.
	void operator+=(DataType&);
	void operator-=(DataType&);
	DataType* operator<<(dataID);

private:
	DataType* first, *current, *last; //Pointers to first in list, current(getting data or whatever), last for the last one we just changed.
};