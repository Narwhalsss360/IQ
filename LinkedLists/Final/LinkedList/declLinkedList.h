#pragma once
#include <stdint.h>
#include <stdexcept>

typedef uint32_t NodeIndex;

template <typename T>
class LinkedList;

template <typename T>
class Node
{
public:
	Node();
	NodeIndex getNodeIndex();
	Node<T>* getPreviousNode();
	Node<T>* getNextNode();
	~Node();

	friend class LinkedList<T>;
private:
	LinkedList<T>* owner;
	NodeIndex index;
	Node<T>* previousNode, * nextNode;
};

template <typename T>
class LinkedList
{
public:
	LinkedList();
	void append(T*);
	void prepend(T*);
	void insert(T*, NodeIndex);
	void remove(T*);
	void swap(T*, T*);
	NodeIndex length();
	Node<T>* get(NodeIndex);
	~LinkedList();

private:
	void incrementIndices(Node<T>*);
	void decrementIndices(Node<T>*);
	NodeIndex count;
	Node<T>* head, * tail;
};