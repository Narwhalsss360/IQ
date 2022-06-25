#include "DataLib.h"

DataType::DataType()
	: id(0), data(0), previous(NULL), next(NULL)
{
}

DataType::DataType(dataID i, uint64_t d)
	: id(i), data(d), previous(NULL), next(NULL)
{
}

void DataType::set(uint64_t d)
{
	data = d;
}

uint64_t DataType::get()
{
	return data;
}

uint16_t DataType::getID()
{
	return id;
}

DataType::~DataType()
{
}