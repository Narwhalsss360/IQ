#pragma once

#include <stdint.h>

typedef uint16_t dataID;
typedef uint64_t specialData;


class DataType
{
public:
	DataType();
	DataType(dataID, specialData);
	void set(specialData);
	specialData get();
	dataID getID();
	~DataType();

	friend class DataController;
	DataType* next; //Previous & next DataType in list.
	dataID id; //unique identifier.
	specialData data;
};

class DataController
{
public:
	DataController();
	~DataController();
	void addData(DataType&); //Add a instance to linked list.
	DataType* search(dataID); //Get pointer to instance with id.
	specialData get(dataID);
	DataType* begin();
	DataType* end();
	void operator+=(DataType&);
	specialData operator<<(dataID);

	DataType* firstInList, *current; //Pointers to first in list, current(getting data or whatever), last for the last one we just changed.
};