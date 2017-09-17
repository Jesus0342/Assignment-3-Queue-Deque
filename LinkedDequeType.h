#ifndef LINKEDDEQUETYPE_H_
#define LINKEDDEQUETYPE_H_

#include "DoublyLinkedList.h"

// LinkedDequeType - Wrapper class that utilizes the methods of the
//					 DoublyLinkedList class in order to implement the functions
//					 of a deque.
template <class T>
class LinkedDequeType
{
public:
	// Default constructor.
	LinkedDequeType();

	// Returns true if the deque is empty.
	bool empty();

	// Returns the number of nodes that are in the deque.
	int size();

	// Returns the data stored in the first node of the deque.
	// PRE-CONDITION: The deque has at least one node.
	const T front();

	// Adds a new item to the back of the queue.
	// POST-CONDITION: The queue is changed.
	void insertBack(const T item);

	// Removes the item at the front of the queue.
	// POST-CONDITION: The queue is changed.
	void eraseFront();

private:
	DoublyLinkedList<T> deque;
};

template <class T>
LinkedDequeType<T>::LinkedDequeType() : deque()
{

}

template <class T>
bool LinkedDequeType<T>::empty()
{
	return deque.empty();
}

template <class T>
int LinkedDequeType<T>::size()
{
	return deque.size();
}

template <class T>
const T LinkedDequeType<T>::front()
{
	return deque.front();
}

template <class T>
void LinkedDequeType<T>::insertBack(const T item)
{
	deque.addBack(item);
}

template <class T>
void LinkedDequeType<T>::eraseFront()
{
	deque.removeFront();
}

#endif
