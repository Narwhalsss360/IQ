#pragma once
#include <stdint.h>

#ifdef __INLINE_LINKEDLIST__
#define __LINKEDLIST_INLINE__ inline
#else
#define __LINKEDLIST_INLINE__
#endif

typedef uint32_t LinkedListItemIndex;

class LinkedList;

class ListItem
{
public:
	ListItem();
	void appendTo(LinkedList*);
	void prependTo(LinkedList*);
	void insertTo(LinkedList*, LinkedListItemIndex);
	void removeFrom(LinkedList*);
	void appendTo(LinkedList&);
	void prependTo(LinkedList&);
	void insertTo(LinkedList&, LinkedListItemIndex);
	void removeFrom(LinkedList&);
	~ListItem();

private:
	friend class LinkedList;
	LinkedListItemIndex index;
	ListItem* previousItem, * nextItem;
	LinkedList* owner;
};

class LinkedList
{
public:
	__LINKEDLIST_INLINE__ LinkedList();
	__LINKEDLIST_INLINE__ ~LinkedList();

	__LINKEDLIST_INLINE__ void append(ListItem*);
	__LINKEDLIST_INLINE__ void prepend(ListItem*);
	__LINKEDLIST_INLINE__ void insert(ListItem*, LinkedListItemIndex);
	__LINKEDLIST_INLINE__ void remove(ListItem*);

	__LINKEDLIST_INLINE__ LinkedListItemIndex length();
	__LINKEDLIST_INLINE__ ListItem* get(LinkedListItemIndex);
	__LINKEDLIST_INLINE__ ListItem* begin();
	__LINKEDLIST_INLINE__ ListItem* end();
	
	__LINKEDLIST_INLINE__ ListItem& operator[](LinkedListItemIndex);
	__LINKEDLIST_INLINE__ void iterate(void (*)(ListItem*));
private:
	friend class ListItem;
	LinkedListItemIndex itemCount;
	ListItem* firstItem;
};