#include "LinkedList.h"
#include <stdexcept>

#define UNCLAIMED(pItem) (pItem->owner == NULL)
#define CLAIMED(pItem) (pItem->owner != NULL)
#define NOT_OWNED(pItem) (pItem->owner != this)

#define INCREMENT_INDICES(pStart) \
	ListItem* currentItem = pStart->nextItem; \
	while (currentItem) \
	{ \
		currentItem->index++; \
		currentItem = currentItem->nextItem; \
	}

#define DECREMENT_INDICES(pStart) \
	ListItem* currentItem = pStart->nextItem; \
	while (currentItem) \
	{ \
		currentItem->index--; \
		currentItem = currentItem->nextItem; \
	}

LinkedList::LinkedList()
	: itemCount(0), firstItem(NULL)
{
}

void LinkedList::append(ListItem* item)
{
	if (CLAIMED(item)) return;
	
	if (length())
	{
		ListItem* lastItem = getLastItem();
		lastItem->nextItem = item;
		item->previousItem = lastItem;
	}
	else
	{
		firstItem = item;
		item->previousItem = NULL;
	}

	item->nextItem = NULL;
	item->index = itemCount;
	item->owner = this;
	itemCount++;
}

void LinkedList::prepend(ListItem* item)
{
	if (CLAIMED(item)) return;

	if (length())
	{
		firstItem->previousItem = item;
		firstItem = item;
	}
	else
	{
		firstItem = item;
		item->nextItem = NULL;
	}

	item->index = 0;
	item->previousItem = NULL;
	item->owner = this;

	INCREMENT_INDICES(item);
	itemCount++;
}

void LinkedList::insert(ListItem* item, LinkedListItemIndex index)
{
	if (CLAIMED(item)) return;

	ListItem* itemAtSelectedIndex = get(index);

	item->nextItem = itemAtSelectedIndex->nextItem;
	itemAtSelectedIndex->nextItem = item;

	item->previousItem = itemAtSelectedIndex;
	item->nextItem->previousItem = item;

	item->owner = this;
	item->index = itemAtSelectedIndex->index + 1;
	INCREMENT_INDICES(item);
	itemCount++;
}

void LinkedList::remove(ListItem* item)
{
	if (NOT_OWNED(item)) return;

	if (item->previousItem == NULL)
	{
		firstItem = item->nextItem;
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
}

LinkedListItemIndex LinkedList::length()
{
	return itemCount;
}

ListItem* LinkedList::get(LinkedListItemIndex index)
{
	if (index < itemCount)
	{
		ListItem* current = firstItem;
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

ListItem* LinkedList::getFirstItem()
{
	if (length()) return firstItem;
	return NULL;
}

ListItem* LinkedList::getLastItem()
{
	ListItem* current = firstItem;
	while (current)
	{
		if (current->nextItem == NULL) return current;
		current = current->nextItem;
	}
	return NULL;
}

ListItem& LinkedList::operator[](LinkedListItemIndex index)
{
	return *get(index);
}

void LinkedList::iterate(void (*doFunction)(ListItem*))
{
	for (LinkedListItemIndex i = 0; i < itemCount; i++)
	{
		doFunction(get(i));
	}
}

LinkedList::~LinkedList()
{
}