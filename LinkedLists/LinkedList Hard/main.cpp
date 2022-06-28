#define __INLINE_LINKEDLIST__
#include <iostream>
#include "Person.h"
#include "Rearrangments.h"

#pragma region Globals
const int index1 = 5;
const int index2 = 4;

DoublyLinkedList list;
Person p1 = Person("Lila", 32);
Person p2 = Person("Franklyn", 33);
Person p3 = Person("Rosa", 4);
Person p4 = Person("Sandra", 5);
Person p5 = Person("Benito", 2);
Person p6 = Person("Marino", 9);
#pragma endregion

auto printPersonName = [](DoublyLinkedListItem* listItem)
{
	Person p = GET_PERSON(listItem);
	std::cout << '[' << p.index << "]: " << p.getName() << ", Age: " << (int)p.getAge() << '\n';
};

int nameCompare(Person* pA, Person* pB)
{
	return strcmp(pA->getName().c_str(), pB->getName().c_str());
}

int main()
{
#pragma region Adding
	list.append(&p1);
	list.append(&p2);
	list.append(&p3);
	list.append(&p4);
	list.append(&p5);
	p6.appendTo(list);

	list.iterate(printPersonName);
	std::cout << "Person 1 is: " << GET_PERSON(&list[0]).getName() << "\n";
#pragma endregion

#pragma region Reversing & Swapping
	reverseDoublyLinkedList(&list);
	std::cout << "\nReversed List:\n";
	list.iterate(printPersonName);

#pragma region Swapping
	list.swap(index1, index2);
	std::cout << "\nSwapped indicies (" << index1 << ", " << index2 << "):\n";
	list.iterate(printPersonName);
#pragma endregion

	reverseDoublyLinkedList(&list);
	std::cout << "\nRe-reversed List:\n";
	list.iterate(printPersonName);
#pragma endregion

#pragma region Sorting
	bubbleSort<Person>(&list, nameCompare);
	std::cout << "\nSorted by name [UP]:\n";
	list.iterate(printPersonName);

	sortName(&list, SORT_NAME_DOWN);
	std::cout << "\nSorted by name [DOWN]:\n";
	list.iterate(printPersonName);

	sortAge(&list);
	std::cout << "\nSorted by age [UP]:\n";
	list.iterate(printPersonName);

	sortAge(&list, SORT_AGE_DOWN);
	std::cout << "\nSorted by age [DOWN]:\n";
	list.iterate(printPersonName);
#pragma endregion

#pragma region Looping
	std::cout << "\nRegular for loop:\n";
	for (IDoublyLinkedListItem iterator = list.begin(); iterator != list.end(); ++iterator)
	{
		Person p = GET_PERSON(iterator.item);
		std::cout << '[' << p.index << "]: " << p.getName() << '\n';
	}

	std::cout << "\nRanged-Based for loop:\n";
	for (auto& i : list)
	{
		Person p = GET_PERSON(&i);
		std::cout << '[' << p.index << "]: " << p.getName() << '\n';
	}

	std::cin.get();
#pragma endregion
}