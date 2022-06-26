#pragma once
#include <stdint.h>

#ifdef __INLINE_LINKEDLIST__
#define __LINKEDLIST_INLINE__ inline
#else
#define __LINKEDLIST_INLINE__
#endif

typedef uint32_t LinkedListItemIndex;

class DoublyLinkedList;

class DoublyLinkedListItem
{
public:
	DoublyLinkedListItem();
	void appendTo(DoublyLinkedList*);
	void prependTo(DoublyLinkedList*);
	void insertTo(DoublyLinkedList*, LinkedListItemIndex);
	void removeFrom(DoublyLinkedList*);
	void appendTo(DoublyLinkedList&);
	void prependTo(DoublyLinkedList&);
	void insertTo(DoublyLinkedList&, LinkedListItemIndex);
	void removeFrom(DoublyLinkedList&);
	~DoublyLinkedListItem();

	friend class DoublyLinkedList;
	LinkedListItemIndex index;
	DoublyLinkedListItem* previousItem, * nextItem;
	DoublyLinkedList* owner;
};

class DoublyLinkedList
{
public:
	__LINKEDLIST_INLINE__ DoublyLinkedList();
	__LINKEDLIST_INLINE__ ~DoublyLinkedList();

	__LINKEDLIST_INLINE__ void append(DoublyLinkedListItem*);
	__LINKEDLIST_INLINE__ void prepend(DoublyLinkedListItem*);
	__LINKEDLIST_INLINE__ void insert(DoublyLinkedListItem*, LinkedListItemIndex);
	__LINKEDLIST_INLINE__ void remove(DoublyLinkedListItem*);

	__LINKEDLIST_INLINE__ LinkedListItemIndex length();
	__LINKEDLIST_INLINE__ DoublyLinkedListItem* get(LinkedListItemIndex);
	__LINKEDLIST_INLINE__ DoublyLinkedListItem* begin();
	__LINKEDLIST_INLINE__ DoublyLinkedListItem* end();
	
	__LINKEDLIST_INLINE__ DoublyLinkedListItem& operator[](LinkedListItemIndex);
	__LINKEDLIST_INLINE__ void iterate(void (*)(DoublyLinkedListItem*));

	friend class DoublyLinkedListItem;
	LinkedListItemIndex itemCount;
	DoublyLinkedListItem* head;
};