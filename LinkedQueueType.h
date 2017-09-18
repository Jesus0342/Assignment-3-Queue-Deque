#ifndef LINKEDQUEUETYPE_H_
#define LINKEDQUEUETYPE_H_

#include "LinkedDequeType.h"

// LinkedDequeType - Wrapper class that utilizes the methods of the
//					 DoublyLinkedList class and LinkedDequeType in order to
// 					 implement the functions of a deque.
template <class T>
class LinkedQueueType
{
public:
	// Default constructor.
	LinkedQueueType();

	// Returns true if the queue is empty.
	bool empty();

	// Returns the number of nodes that are in the queue.
	int size();

	// Returns the data stored in the first node of the queue.
	// PRE-CONDITION: The queue has at least one node.
	const T front();

	// Adds a new item to the back of the queue.
	// POST-CONDITION: The queue is changed.
	void enqueue(const T item);

	// Removes the item at the front of the queue.
	// POST-CONDITION: The queue is changed.
	void dequeue();

private:
	LinkedDequeType<T> queue;
};

template <class T>
LinkedQueueType<T>::LinkedQueueType() : queue()
{
}

template <class T>
bool LinkedQueueType<T>::empty()
{
	return queue.empty();
}

template <class T>
int LinkedQueueType<T>::size()
{
	return queue.size();
}

template <class T>
const T LinkedQueueType<T>::front()
{
	return queue.front();
}

template <class T>
void LinkedQueueType<T>::enqueue(const T item)
{
	queue.insertBack(item);
}

template <class T>
void LinkedQueueType<T>::dequeue()
{
	queue.eraseFront();
}

#endif
