#include "Person.h"

Person::Person(std::string newName, Age newAge)
	: DoublyLinkedListItem(), name(newName), age(newAge)
{
}

Person::Person()
	: Person("", 0)
{
}

void Person::setName(std::string newName)
{
	name = newName;
}

std::string Person::getName()
{
	return name;
}

Age Person::getAge()
{
	return age;
}