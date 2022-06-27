#include "iLinkedList.h"
#include <stdexcept>

#define CLAIMED(name) (item.previousItem != NULL && item.nextItem != NULL)
#define EMPTY() (itemCount == 0)

LinkedItemList::LinkedItemList()
	: itemCount(0), firstItem(NULL)
{
}

void LinkedItemList::append(ListItem& item)
{
	if (CLAIMED(item)) return;
	if (firstItem == NULL)
	{
		firstItem = &item;
		item.previousItem = NULL;
	}
	else
	{
		ListItem* last = getLastItem();
		last->nextItem = &item;
		item.previousItem = last;
	}

	item.index = itemCount;
	itemCount++;
	item.nextItem = NULL;
}

void LinkedItemList::prepend(ListItem& item)
{
	if (CLAIMED(item)) return;
	if (firstItem == NULL)
	{
		item.nextItem = NULL;
	}
	else
	{
		item.nextItem = firstItem;
		firstItem = &item;
	}

	item.previousItem = NULL;
	item.index = itemCount;
	incrementIndicies(item);
	itemCount++;
}

void LinkedItemList::insert(ListItem& item, ItemIndex index)
{
	if (CLAIMED(item)) return;
	//Get the item at the given index, check is its first or last then prepend or append if so.
	ListItem* itemAtIndex = atIndex(index);
	if (itemAtIndex->nextItem == NULL)
	{
		append(item);
		return;
	}
	if (itemAtIndex->previousItem == NULL)
	{
		prepend(item);
		return;
	}

	//Re-arranging foward order.
	item.nextItem = itemAtIndex->nextItem;
	itemAtIndex->nextItem = &item;

	//Re-arranging backward order.
	item.previousItem = itemAtIndex;
	item.nextItem->previousItem = &item;

	item.index = itemAtIndex->index + 1; //Setting the new indices.
	incrementIndicies(item);
	itemCount++;
}

void LinkedItemList::remove(ListItem& item)
{
	if (item.previousItem == NULL)
	{
		firstItem = item.nextItem;
		decrementIndices(item);
		item.previousItem = NULL;
		item.nextItem = NULL;
		itemCount--;
		return;
	}

	if (item.nextItem == NULL)
	{
		item.index = 0;
		item.previousItem = NULL;
		item.nextItem = NULL;
		itemCount--;
		return;
	}

	decrementIndices(item);

	//Merging neighbor items.
	item.previousItem->nextItem = item.nextItem;
	item.nextItem->previousItem = item.previousItem;

	item.previousItem = NULL;
	item.nextItem = NULL;
	itemCount--;
}

void LinkedItemList::remove(ItemIndex index)
{
	remove(*atIndex(index));
}

void LinkedItemList::push(ListItem& item)
{
	append(item);
}

ListItem* LinkedItemList::pop()
{
	if (EMPTY()) return NULL;
	ListItem* poppedItem = firstItem;
	remove(0);
	return poppedItem;
}

ItemIndex LinkedItemList::length()
{
	return itemCount;
}

ListItem* LinkedItemList::getLastItem()
{
	ListItem* current = firstItem;
	while (current)
	{
		if (current->nextItem == NULL) return current;
		current = current->nextItem;
	}
	return NULL;
}

ListItem* LinkedItemList::atIndex(ItemIndex index)
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
		throw std::out_of_range("ItemList::find(ItemIndex): Index out of range.");
	}
	return NULL;
}

ListItem* LinkedItemList::find(ListItemData data)
{
	ListItem* current = firstItem;
	while (current)
	{
		if (current->data == data) return current;
		current = current->nextItem;
	}
	return NULL;
}

void LinkedItemList::decrementIndices(ListItem& item)
{
	item.index = 0;
	ListItem* current = item.nextItem;
	while (current)
	{
		current->index--;
		current = current->nextItem;
	}
}

void LinkedItemList::incrementIndicies(ListItem& item)
{
	ListItem* current = item.nextItem;
	while (current)
	{
		current->index++;
		current = current->nextItem;
	}
}

LinkedItemList::~LinkedItemList()
{
}