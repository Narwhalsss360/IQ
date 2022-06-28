#pragma once
#include <stdint.h>
#include <stdexcept>

typedef uint32_t NodeIndex;

template <typename T>
class LinkedList;

template <typename T>
class INode;

template <typename T>
class ListUtility;

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
	friend class ListUtility<T>;
	friend class INode<T>;
private:
	LinkedList<T>* owner;
	NodeIndex index;
	Node<T>* previousNode, * nextNode;
};

//Ranged-Based for loop support.
template <typename T>
class INode
{
public:
	INode(Node<T>*);
	bool operator!=(INode);
	T& operator*();
	void operator++();
	~INode();

private:
	Node<T>* current;
};

template <typename T>
class PrimitiveNode : public Node<PrimitiveNode<T>>
{
public:
	PrimitiveNode();
	PrimitiveNode(T&);
	PrimitiveNode(T&&);

	T& get() const;
	void set(T&);
	void set(T&&);

	operator T& () const;

	void operator=(T&);
	void operator=(T&&);
private:
	mutable T data;
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
	T& operator[](NodeIndex);
	void operator+=(T&);
	void operator-=(T&);
	INode<T> begin();
	INode<T> end();
	~LinkedList();
	friend class ListUtility<T>;

private:
	void incrementIndices(Node<T>*);
	void decrementIndices(Node<T>*);
	NodeIndex count;
	Node<T>* head, * tail;
};

template <typename T>
class ListUtility
{
public:
	ListUtility(LinkedList<T>*);
	void reverse();
	void bubbleSort(int (*)(T*, T*));
	~ListUtility();
private:
	LinkedList<T>* list;
};