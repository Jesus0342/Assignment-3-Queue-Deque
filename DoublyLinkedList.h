#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

#include <iostream>
#include <string>
using namespace std;

// DoublyLinkedList - Template class to implement a linked list.
template <class T>
struct NodeType
{
	T data;
	NodeType<T> *next;
	NodeType<T> *back;
};

template <class T>
class DoublyLinkedList
{
public:
	// Default constructor.
	DoublyLinkedList();

	// Destructor.
	~DoublyLinkedList();

	// Returns true if the list is empty (head == NULL), else returns false.
	bool empty();

	// Returns the number of nodes that are in the list.
	int size();

	// Returns the data stored in the first node of the list.
	// PRE-CONDITION: The list has at least one node.
	const T front();

	// Returns the data stored in the last node in the list.
	// PRE-CONDITION: The list has at least one node.
	const T back();

	// Adds a new item to the front of the list.
	// POST-CONDITION: A new node is added to the list - head points to the new
	// 				   node and numNodes is incremented.
	void addFront(const T item);

	// Adds a new item to the back of the list.
	// POST-CONDITION: A new node is added to the list - tail points to the new
	// 				   node and numNodes is incremented.
	void addBack(const T item);

	// Removes the item at the front of the list.
	// POST-CONDITION: A node is deleted from the list - head points to the next
	// 				   node in the list and numNodes is decremented.
	void removeFront();

	// Removes the item at the back of the list.
	// POST-CONDITION: A node is deleted from the list - tail points to the node
	//				   before it and numNodes is decremented.
	void removeBack();

private:
	NodeType<T> *head;
	NodeType<T> *tail;
	static int numNodes;
};

template <class T>
int DoublyLinkedList<T>::numNodes = 0;

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = NULL;
	tail = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	// Node used for deleting the head of the list.
	NodeType<T> *temp;

	// Points temp to head, moves head to the next node in the list and deletes
	// the old head of the list.
	while(!empty())
	{
		temp = head;

		head = head->next;

		delete temp;
	}

	tail = NULL;

	numNodes = 0;
}

template <class T>
bool DoublyLinkedList<T>::empty()
{
	return head == NULL;
}

template <class T>
int DoublyLinkedList<T>::size()
{
	return numNodes;
}

template <class T>
const T DoublyLinkedList<T>::front()
{
	return head->data;
}

template <class T>
const T DoublyLinkedList<T>::back()
{
	return tail->data;
}

template <class T>
void DoublyLinkedList<T>::addFront(const T item)
{
	// Pointer to a new node.
	NodeType<T> *temp = new NodeType<T>;

	// Stores item in data data member of temp.
	temp->data = item;

	// If list is empty, points back and next to NULL and tail points to temp,
	// else points temp->back to NULL, temp->next to the old head and head->back
	// to temp.
	if(empty())
	{
		temp->back = NULL;

		temp->next = NULL;

		tail = temp;
	}
	else
	{
		temp->back = NULL;

		temp->next = head;

		head->back = temp;
	}

	// Points head to temp to signify the new head of the list.
	head = temp;

	numNodes++;
}

template <class T>
void DoublyLinkedList<T>::addBack(const T item)
{
	// Pointer to a new node.
	NodeType<T> *temp = new NodeType<T>;

	// If list is empty, points back and next to NULL and tail points to temp,
	// else points temp->back to the old tail, temp->next to the NULL and
	// head->next to temp.
	temp->data = item;

	if(empty())
	{
		temp->back = NULL;

		temp->next = NULL;

		head = temp;
	}
	else
	{
		temp->back = tail;

		temp->next = NULL;

		tail->next = temp;
	}

	// Points tail to the new back of the list.
	tail = temp;

	numNodes++;
}

template <class T>
void DoublyLinkedList<T>::removeFront()
{
	// Pointer to node to be deleted.
	NodeType<T> *temp = head;

	// If there is only 1 node in the list, points head and tail to NULL, else
	// points head to the next node in the list, points head->back to NULL and
	// deletes the old head.
	if(temp->next == NULL)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		head = head->next;

		head->back = NULL;

		delete temp;
	}

	numNodes--;

}

template <class T>
void DoublyLinkedList<T>::removeBack()
{
	// Pointer to a node to be deleted.
	NodeType<T> *temp = tail;

	// If there is only 1 node in the list, points head and tail to NULL, else
	// points tail to the node before it, points tail->next to NULL and
	// deletes the old tail.
	if(temp->back == NULL)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		tail = tail->back;

		tail->next = NULL;

		delete temp;
	}

	numNodes--;
}

#endif
