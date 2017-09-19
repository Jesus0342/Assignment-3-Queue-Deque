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
	void insert(int position, const Type item);
	void pop_front();
	void pop_back();
	void erase(int position);
	Type front();
	Type back();

private:
	int maxSize;
	int count;
	int head;
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

	head = maxSize;

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

	if(head >= maxSize)
	{
		head = 0;
	}

	for(int i = 0; i < count; i++)
	{
		copyList[i] = list[head];

		head++;

		if(head >= maxSize)
		{
			head = 0;
		}
	}

	list = copyList;

	maxSize *= 2;

	head = maxSize;

	rear = (maxSize / 2) - 1;

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

	head = (head - 1) % maxSize;

	count++;

	list[head] = item;
}

// FIX THIS...
template <class Type>
void CircularVector<Type>::insert(int position, const Type item)
{
	if(position >= maxSize || position < 0)
	{
		cout << "\nInvalid position.\n\n";

		return;
	}

	if(full())
	{
		resize();
	}

	// Calls the push_front() or push_back methods if the position entered is
	// at either end of the vector, else inserts the item at specified position.
	if(position == 0)
	{
		cout << "0 was entered calling pushhead()\n";

		push_front(item);
	}
	else if(position == maxSize - 1)
	{
		push_back(item);
	}
	else
	{
		if(head == maxSize)
		{
			head = 0;
		}

		position += head;

		if(position >= maxSize)
		{
			position -= maxSize;
		}

		int newRear = rear + 1;

		while(rear >= position)
		{
			if(rear < 0)
			{
				rear = maxSize - 1;

				list[0] = list[rear];
			}
			else
			{
				list[rear + 1] = list[rear];
			}

			rear--;
		}

		list[position] = item;

		rear = newRear;

		// count++ goes inside else because push_front() has its own count++
		count++;
	}
}

template <class Type>
void CircularVector<Type>::pop_front()
{
	count--;

	if(head == maxSize)
	{
		head = 0;
	}
	else
	{
		head = (head + 1) % maxSize;
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
void CircularVector<Type>::erase(int position)
{
	// Exits the function if the position entered is invalid.
	if(position < 0 || position >= maxSize)
	{
		cout << "\nInvalid position!\n\n";

		return;
	}

	// Exits the function if the vector is empty.
	if(empty())
	{
		cout << "\nCannot erase from an empty vector!\n\n";

		return;
	}

	// Calls pop_front() or pop_back() if attempting to delete from either
	// end of the vector, else deletes the value in the indicated position.
	if(position == 0)
	{
		pop_front();
	}
	else if(position == maxSize - 1)
	{
		pop_back();
	}
	else
	{
		// Sets head to 0 if it is out of bounds.
		if(head == maxSize)
		{
			head = 0;
		}

		// Adds the value of head to position so that the correct index in the
		// circular array can be accessed.
		position += head;

		// Subtracts maxSize from position if position is out of bounds so that
		// position is reset at the beginning of the array but moves to the
		// correct index of the circular array.
		if(position >= maxSize)
		{
			position -=maxSize;
		}

		// Moves all values back by one while position has not reached the end
		// of the circular array.
		while(position < rear)
		{
			// Handles the wrapping of the circular array by assigning the
			// value in the 0 index of the array to the maxSize - 1 index of
			// the array, else continues to move the values back one position.
			if(position == maxSize - 1)
			{
				list[position] = list[0];

				position = 0;
			}
			else
			{
				list[position] = list[position + 1];

				position++;
			}
		}

		// Decrements rear to make the previous rear inaccessible.
		rear--;

		// Decrements count to represent an item being removed from the vector.
		count--;
	}
}

template <class Type>
Type CircularVector<Type>::front()
{
	// Assigns head to 0 if it is out of bounds (only push_back() was used when
	// adding values to the vector).
	if(head == maxSize)
	{
		head = 0;
	}

	return list[head];
}

template <class Type>
Type CircularVector<Type>::back()
{
	return list[rear];
}

#endif
