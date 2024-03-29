#pragma once
#include "LinkedList.h"

#define SORT_NAME_UP 0
#define SORT_NAME_DOWN 1
#define SORT_AGE_UP 0
#define SORT_AGE_DOWN 1

void reverseDoublyLinkedList(DoublyLinkedList* list)
{
	DoublyLinkedListItem* current = list->head; //Starting at head.
	DoublyLinkedListItem* nextToReverse = NULL;

	while (true)
	{
		nextToReverse = current->nextItem; //Save the next item to reverse.
		
		//Swap the prev and next
		DoublyLinkedListItem* nextTemp = current->nextItem;
		current->nextItem = current->previousItem;
		current->previousItem = nextTemp;

		//Calculate new index y = -x + i (y = new index, x = old index, i = highest index).
		current->index = ((-1 * current->index) + (list->itemCount - 1));

		if (nextToReverse == NULL) //if next is nothing, change the head to the current item and we are done.
		{
			list->head = current;
			return;
		}
		current = nextToReverse;
	}
}

//Slow bubble sort, continues to iterate and compare after the point of sorted elements. https://www.youtube.com/watch?v=Cq7SMsQBEUw&ab_channel=TimoBingmann
void sortName(DoublyLinkedList* list, uint8_t dir = SORT_NAME_UP)
{
	void (*sorter)(DoublyLinkedListItem*);
	if (dir == SORT_NAME_UP)
	{
		sorter = [](DoublyLinkedListItem* i)
		{
			Person* pA = (Person*)i;
			if (!pA->nextItem) return;
			Person* pB = (Person*)pA->nextItem;
			if (strcmp(pA->getName().c_str(), pB->getName().c_str()) > 0) pA->owner->swap(pA, pB);
		};
	}
	else
	{
		sorter = [](DoublyLinkedListItem* i)
		{
			Person* pA = (Person*)i;
			if (!pA->nextItem) return;
			Person* pB = (Person*)pA->nextItem;
			if (strcmp(pA->getName().c_str(), pB->getName().c_str()) < 0) pA->owner->swap(pA, pB);
		};
	}

	for (LinkedListItemIndex i = 0; i < list->length() - 1; i++) list->iterate(sorter);
}

template <typename T>
void bubbleSort(DoublyLinkedList* list, int (*compareFunction)(T*, T*))
{
	for (uint32_t Outer = 0; Outer < list->length() - 1; Outer++)
	{
		for (uint32_t Inner = 0; Inner < list->length() - Outer - 1; Inner++)
		{
			if (compareFunction((T*)list->get(Inner), (T*)list->get(Inner + 1)) > 0)
				list->swap(list->get(Inner), list->get(Inner + 1));
		}
	}
}

void sortAge(DoublyLinkedList* list, uint8_t dir = SORT_AGE_UP)
{
	void (*sorter)(DoublyLinkedListItem*);
	if (dir)
	{
		sorter = [](DoublyLinkedListItem* i)
		{
			Person* pA = (Person*)i;
			if (!pA->nextItem) return;
			Person* pB = (Person*)pA->nextItem;
			if (pA->getAge() < pB->getAge()) pA->owner->swap(pA, pB);
		};
	}
	else
	{
		sorter = [](DoublyLinkedListItem* i)
		{
			Person* pA = (Person*)i;
			if (!pA->nextItem) return;
			Person* pB = (Person*)pA->nextItem;
			if (pA->getAge() > pB->getAge()) pA->owner->swap(pA, pB);
		};
	}

	for (LinkedListItemIndex i = 0; i < list->length() - 1; i++) list->iterate(sorter);
}