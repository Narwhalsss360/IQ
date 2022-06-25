#include "DataLib.h"

DataType::DataType()
	: id(0), data(0), next(NULL)
{
}

DataType::DataType(dataID i, specialData d)
	: id(i), data(d), next(NULL)
{
}

void DataType::set(specialData d)
{
	data = d;
}

specialData DataType::get()
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