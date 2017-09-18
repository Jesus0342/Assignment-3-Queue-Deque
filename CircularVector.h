#ifndef CIRCULARVECTOR_H_
#define CIRCULARVECTOR_H_

#include <iostream>
#include <string>
using namespace std;

template <class Type>
class CircularVector
{
public:
	CircularVector(int vectorSize = 100);
	~CircularVector();
	bool empty();
	bool full();
	int size();
	void push_back(const Type item);
	void push_front(const Type item);
	void pop_front();
	void pop_back();
	Type getFront();
	Type getBack();

private:
	int maxSize;
	int count;
	int front;
	int rear;
	Type *list;

	void resize();
};

template <class Type>
CircularVector<Type>::CircularVector(int vectorSize)
{
	if(vectorSize <= 0)
	{
		cout << "Size of the vector cannot be negative.\n"
				<< "Creating a vector of size 100.";

		maxSize = 100;
	}
	else
	{
		maxSize = vectorSize;
	}

	front = maxSize;

	rear  = maxSize - 1;

	count = 0;

	list = new Type[maxSize];
}

template <class Type>
CircularVector<Type>::~CircularVector()
{
	delete [] list;
}

template <class Type>
bool CircularVector<Type>::empty()
{
	return (count == 0);
}

template <class Type>
bool CircularVector<Type>::full()
{
	return (count == maxSize);
}

template <class Type>
void CircularVector<Type>::resize()
{
	Type *copyList = new Type [maxSize * 2];
	Type *temp = list;

	for(int i = 0; i < size(); i++)
	{
		copyList[i] = list[front];

		front++;

		if(front == maxSize)
		{
			front = 0;
		}
	}

	list = copyList;

	maxSize *= 2;

	delete temp;
}

template <class Type>
int CircularVector<Type>::size()
{
	return count;
}

template <class Type>
void CircularVector<Type>::push_back(const Type item)
{
	if(full())
	{
		resize();
	}

	rear = (rear + 1) % maxSize;

	count++;

	list[rear] = item;
}

template <class Type>
void CircularVector<Type>::push_front(const Type item)
{
	if(full())
	{
		resize();
	}

	front = (front - 1) % maxSize;

	count++;

	list[front] = item;
}

template <class Type>
void CircularVector<Type>::pop_front()
{
	count--;

	if(front == maxSize)
	{
		front = 0;
	}
	else
	{
		front = (front + 1) % maxSize;
	}
}

template <class Type>
void CircularVector<Type>::pop_back()
{
	count--;

	if(rear == 0)
	{
		rear = maxSize - 1;
	}
	else
	{
		rear = (rear - 1) % maxSize;
	}
}

template <class Type>
Type CircularVector<Type>::getFront()
{
	return list[front];
}

template <class Type>
Type CircularVector<Type>::getBack()
{
	return list[rear];
}

#endif
