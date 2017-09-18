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
	LinkedQueueType();
	bool empty();
	int size();
	const T front();
	void enqueue(const T item);
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
