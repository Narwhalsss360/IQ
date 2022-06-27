#include "LinkedList.h"
#include <stdexcept>

#pragma region Defenitions
#define UNCLAIMED(pItem) (pItem->owner == NULL)
#define CLAIMED(pItem) (pItem->owner != NULL)
#define NOT_OWNED(pItem) (pItem->owner != this)

#define INCREMENT_INDICES(pStart) \
	DoublyLinkedListItem* currentItem = pStart->nextItem; \
	while (currentItem) \
	{ \
		currentItem->index++; \
		currentItem = currentItem->nextItem; \
	}

#define DECREMENT_INDICES(pStart) \
	DoublyLinkedListItem* currentItem = pStart->nextItem; \
	while (currentItem) \
	{ \
		currentItem->index--; \
		currentItem = currentItem->nextItem; \
	}
#pragma endregion

DoublyLinkedList::DoublyLinkedList()
	: itemCount(0), head(NULL), tail(NULL)
{
}

void DoublyLinkedList::append(DoublyLinkedListItem* item)
{
	if (CLAIMED(item)) return;
	
	if (length())
	{
		DoublyLinkedListItem* lastItem = last();
		lastItem->nextItem = item;
		item->previousItem = lastItem;
	}
	else
	{
		head = item;
		item->previousItem = NULL;
	}

	item->nextItem = NULL;
	item->index = itemCount;
	item->owner = this;
	itemCount++;
	tail = last();
}

void DoublyLinkedList::prepend(DoublyLinkedListItem* item)
{
	if (CLAIMED(item)) return;

	if (length())
	{
		head->previousItem = item;
		head = item;
	}
	else
	{
		head = item;
		item->nextItem = NULL;
	}

	item->index = 0;
	item->previousItem = NULL;
	item->owner = this;

	INCREMENT_INDICES(item);
	itemCount++;
	tail = last();
}

void DoublyLinkedList::insert(DoublyLinkedListItem* item, LinkedListItemIndex index)
{
	if (CLAIMED(item)) return;

	DoublyLinkedListItem* itemAtSelectedIndex = get(index);

	item->nextItem = itemAtSelectedIndex->nextItem;
	itemAtSelectedIndex->nextItem = item;

	item->previousItem = itemAtSelectedIndex;
	item->nextItem->previousItem = item;

	item->owner = this;
	item->index = itemAtSelectedIndex->index + 1;
	INCREMENT_INDICES(item);
	itemCount++;
	tail = last();
}

void DoublyLinkedList::remove(DoublyLinkedListItem* item)
{
	if (NOT_OWNED(item)) return;

	if (item->previousItem == NULL)
	{
		head = item->nextItem;
		DECREMENT_INDICES(item);
		item->previousItem = NULL;
		item->nextItem = NULL;
		item->index = 0;
		itemCount--;
		return;
	}

	if (item->nextItem == NULL)
	{
		item->previousItem = NULL;
		item->index = 0;
		itemCount--;
		return;
	}

	DECREMENT_INDICES(item);
	item->previousItem->nextItem = item->nextItem;
	item->nextItem->previousItem = item->previousItem;

	item->previousItem = NULL;
	item->nextItem = NULL;
	item->owner = NULL;
	itemCount--;
	tail = last();
}

void DoublyLinkedList::swap(DoublyLinkedListItem* a, DoublyLinkedListItem* b)
{
	if (a == head)
		head = b;
	else if (b == head)
		head = a;

	DoublyLinkedListItem* aNext = a->nextItem;
	LinkedListItemIndex aIndex = a->index;
	a->nextItem = b->nextItem;
	a->index = b->index;

	b->nextItem = aNext;
	b->index = aIndex;
	
	if (a->nextItem) a->nextItem->previousItem = a;
	if (b->nextItem) b->nextItem->previousItem = b;

	DoublyLinkedListItem* aPrev = a->previousItem;
	a->previousItem = b->previousItem;
	b->previousItem = aPrev;

	if (a->previousItem) a->previousItem->nextItem = a;
	if (b->previousItem) b->previousItem->nextItem = b;
	tail = last();
}

void DoublyLinkedList::swap(LinkedListItemIndex i1, LinkedListItemIndex i2)
{
	if (i1 == i2) return;
	DoublyLinkedListItem* a = get(i1);
	DoublyLinkedListItem* b = get(i2);
	swap(a, b);
}

LinkedListItemIndex DoublyLinkedList::length()
{
	return itemCount;
}

DoublyLinkedListItem* DoublyLinkedList::get(LinkedListItemIndex index)
{
	if (index < itemCount)
	{
		DoublyLinkedListItem* current = head;
		while (current)
		{
			if (current->index == index) return current;
			current = current->nextItem;
		}
	}
	else
	{
		throw std::out_of_range("get(LinkedListItemIndex index): (argument: Index) out of range");
	}
	return NULL;
}

DoublyLinkedListItem* DoublyLinkedList::first()
{
	if (head) return head;
	else return NULL;
}

DoublyLinkedListItem* DoublyLinkedList::last()
{
	DoublyLinkedListItem* current = head;
	while (current)
	{
		if (current->nextItem == NULL) return current;
		current = current->nextItem;
	}
	return NULL;
}

IDoublyLinkedListItem DoublyLinkedList::begin()
{
	tail = last();
	if (length()) return IDoublyLinkedListItem(head);
	return NULL;
}

IDoublyLinkedListItem DoublyLinkedList::end()
{
	return IDoublyLinkedListItem(tail);
}

DoublyLinkedListItem& DoublyLinkedList::operator[](LinkedListItemIndex index)
{
	return *get(index);
}

void DoublyLinkedList::iterate(void (*doFunction)(DoublyLinkedListItem*))
{
	for (LinkedListItemIndex i = 0; i < itemCount; i++)
	{
		doFunction(get(i));
	}
}

DoublyLinkedList::~DoublyLinkedList()
{
}