#include "iLinkedList.h"

ListItem::ListItem()
	: data(0), index(0), previousItem(NULL), nextItem(NULL)
{
}

ListItem::ListItem(ListItemData d)
	: data(d), index(0), previousItem(NULL), nextItem(NULL)
{
}

ListItemData ListItem::get()
{
	return data;
}

ListItem::operator ListItemData()
{
	return data;
}

void ListItem::operator=(ListItemData d)
{
	d = data;
}

ListItem::~ListItem()
{
}