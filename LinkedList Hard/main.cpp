#define __INLINE_LINKEDLIST__
#include <iostream>
#include "Person.h"
#include "Rearrangments.h"

const int index1 = 5;
const int index2 = 4;

DoublyLinkedList list;

Person p1 = Person("Lila", 18);
Person p2 = Person("Franklyn", 18);
Person p3 = Person("Rosa", 9);
Person p4 = Person("Sandra", 12);
Person p5 = Person("Benito", 25);
Person p6 = Person("Marino", 18);

auto printPersonName = [](DoublyLinkedListItem* listItem)
{
	std::cout << '[' << ((Person*)listItem)->index << "]: " << ((Person*)listItem)->getName() << '\n';
};

int main()
{
	list.append(&p1);
	list.append(&p2);
	list.append(&p3);
	list.append(&p4);
	list.append(&p5);
	p6.appendTo(list);

	list.iterate(printPersonName);
	std::cout << "Person 1 is: " << GET_PERSON(list[0]).getName() << "\n";

	reverseDoublyLinkedList(&list);
	std::cout << "\nReversed List:\n";
	list.iterate(printPersonName);

	list.swap(index1, index2);
	std::cout << "\nSwapped indicies (" << index1 << ", " << index2 << "):\n";
	list.iterate(printPersonName);

	reverseDoublyLinkedList(&list);
	std::cout << "\nRe-reversed List:\n";
	list.iterate(printPersonName);

	sortName(&list);
	std::cout << "\nSorted by name [UP]:\n";
	list.iterate(printPersonName);

	sortName(&list, SORT_NAME_DOWN);
	std::cout << "\nSorted by name [DOWN]:\n";
	list.iterate(printPersonName);

	std::cout << "\nRegular for loop:\n";
	for (IDoublyLinkedListItem iterator = list.begin(); iterator != list.end(); ++iterator)
	{
		Person p = GET_PERSON_FROM_PTR(iterator.item);
		std::cout << '[' << p.index << "]: " << p.getName() << '\n';
	}

	std::cout << "\nRanged-Based for loop:\n";
	for (auto& i : list)
	{
		Person p = GET_PERSON(i);
		std::cout << '[' << p.index << "]: " << p.getName() << '\n';
	}

	std::cin.get();
}