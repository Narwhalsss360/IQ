#include "LinkedList.h"

DoublyLinkedListItem::DoublyLinkedListItem()
	: index(0), previousItem(NULL), nextItem(NULL), owner(NULL)
{
}

void DoublyLinkedListItem::appendTo(DoublyLinkedList* list)
{
	list->append(this);
}

void DoublyLinkedListItem::prependTo(DoublyLinkedList* list)
{
	list->prepend(this);
}

void DoublyLinkedListItem::insertTo(DoublyLinkedList* list, LinkedListItemIndex index)
{
	list->insert(this, index);
}

void DoublyLinkedListItem::removeFrom(DoublyLinkedList* list)
{
	list->remove(this);
}

void DoublyLinkedListItem::appendTo(DoublyLinkedList& list)
{
	list.append(this);
}

void DoublyLinkedListItem::prependTo(DoublyLinkedList& list)
{
	list.prepend(this);
}

void DoublyLinkedListItem::insertTo(DoublyLinkedList& list, LinkedListItemIndex index)
{
	list.insert(this, index);
}

void DoublyLinkedListItem::removeFrom(DoublyLinkedList& list)
{
	list.remove(this);
}

DoublyLinkedListItem::~DoublyLinkedListItem()
{
}