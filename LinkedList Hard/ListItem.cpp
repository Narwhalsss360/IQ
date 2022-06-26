#include "LinkedList.h"

ListItem::ListItem()
	: index(0), previousItem(NULL), nextItem(NULL), owner(NULL)
{
}

void ListItem::appendTo(LinkedList* list)
{
	list->append(this);
}

void ListItem::prependTo(LinkedList* list)
{
	list->prepend(this);
}

void ListItem::insertTo(LinkedList* list, LinkedListItemIndex index)
{
	list->insert(this, index);
}

void ListItem::removeFrom(LinkedList* list)
{
	list->remove(this);
}

void ListItem::appendTo(LinkedList& list)
{
	list.append(this);
}

void ListItem::prependTo(LinkedList& list)
{
	list.prepend(this);
}

void ListItem::insertTo(LinkedList& list, LinkedListItemIndex index)
{
	list.insert(this, index);
}

void ListItem::removeFrom(LinkedList& list)
{
	list.remove(this);
}

ListItem::~ListItem()
{
}