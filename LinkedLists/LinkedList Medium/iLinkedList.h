#pragma once
#include <cstdint>

typedef uint32_t ItemIndex;
typedef int64_t ListItemData;

class ListItem
{
public:
	ListItem();
	~ListItem();
	ListItem(ListItemData);
	ListItemData get();
	operator ListItemData();
	void operator=(ListItemData);
	friend class LinkedItemList;
private:
	ListItemData data;
	ItemIndex index;
	ListItem* previousItem, * nextItem;
};

class LinkedItemList
{
public:
	LinkedItemList();
	~LinkedItemList();

	//List Tools.
	void append(ListItem&);
	void prepend(ListItem&);
	void insert(ListItem&, ItemIndex); //Insert after given index.
	void remove(ListItem&);
	void remove(ItemIndex);
	ItemIndex length();

	//Queueing tools.
	void push(ListItem&);
	ListItem* pop();
	
	//Search tools.
	ListItem* atIndex(ItemIndex);
	ListItem* find(ListItemData);
	ListItem* getLastItem();
private:
	void incrementIndicies(ListItem&);
	void decrementIndices(ListItem&);
	ItemIndex itemCount;
	ListItem* firstItem;
};