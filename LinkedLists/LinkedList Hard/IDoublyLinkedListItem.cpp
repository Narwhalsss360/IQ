#include "LinkedList.h"

IDoublyLinkedListItem::IDoublyLinkedListItem(DoublyLinkedListItem* _item_)
	: item(_item_)
{
}

bool IDoublyLinkedListItem::operator!=(IDoublyLinkedListItem r)
{
	return (item != NULL);
}

DoublyLinkedListItem& IDoublyLinkedListItem::operator*()
{
	return *item;
}

void IDoublyLinkedListItem::operator++()
{
	item = item->nextItem;
}

IDoublyLinkedListItem::~IDoublyLinkedListItem()
{
}