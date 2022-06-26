#pragma once
#include "LinkedList.h"
#include <string>

#define NOT_A_PERSON(p) (p.name == "" && p.age == 0)
#define GET_PERSON(toReinterpret) (*(Person*)&toReinterpret)

typedef uint8_t Age;

class Person : public ListItem
{
public:
	Person();
	Person(std::string, Age);
	std::string getName();
	void setName(std::string);
	Age getAge();
private:
	std::string name;
	Age age;
};