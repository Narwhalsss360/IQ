#pragma once
#include "iLinkedList.h"

LinkedItemList list = LinkedItemList();
ListItem aa = ListItem(4);
ListItem ab = ListItem(8);
ListItem ac = ListItem(16);
ListItem ad = ListItem(32);

void addItems()
{
	list.append(aa);
	list.append(ab);
	list.append(ac);
	list.append(ad);
}