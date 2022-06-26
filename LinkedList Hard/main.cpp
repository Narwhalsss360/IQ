#include <iostream>
#include "Person.h"

DoublyLinkedList list;

Person p1 = Person("Lila", 18);
Person p2 = Person("Franklyn", 18);
Person p3 = Person("Person 3", 9);
Person p4 = Person("Person 4", 12);
Person p5 = Person("Person 5", 25);
Person p6 = Person("Person 6", 18);

void personIterator(DoublyLinkedListItem* i)
{
	Person item = *(Person*)i;
	std::cout << item.getName() << '\n';
}

int main()
{
	list.append(&p1);
	list.append(&p2);
	list.append(&p3);
	list.append(&p4);
	list.append(&p5);
	p6.appendTo(list);
	list.iterate(personIterator);

	std::cout << "Person 1 is: " << GET_PERSON(list[0]).getName() << "\n";

	std::cin.get();
}