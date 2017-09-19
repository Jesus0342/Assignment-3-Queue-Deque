#ifndef CIRCULARVECTOR_H_
#define CIRCULARVECTOR_H_

#include <iostream>
#include <string>
using namespace std;

template <class Type>
class CircularVector
{
public:
	// Default constructor.
	CircularVector(int vectorSize = 100);

	// Destructor.
	~CircularVector();

	// Returns true if count == 0, else returns false.
	// PRE-CONDITION: The vector must exist.
	bool empty();

	// Returns true if count == maxSize, else returns false.
	// PRE-CONDITION: Th vector must exist.
	bool full();

	// Returns the value of count.
	// PRE-CONDITION: The vector must exist.
	int size();

	// Adds a new value to the back of the vector.
	// POST-CONDITION: A new value is added to the vector - rear and count are
	//				   increased by 1.
	void push_back(const Type item);

	// Adds a new value to the front of the vector.
	// POST-CONDITION: A new value is added to the vector - head is decremented
	// 				   and count is incremented.
	void push_front(const Type item);

	// Adds a new value to the vector at a specified position.
	// PRE-CONDITION:  Position is valid (not out of range).
	// POST-CONDITION: A new value is added to the vector - rear is incremented,
	// 				   all values are moved 1 index to the right and count is
	//				   is incremented.
	void insert(int position, const Type item);

	// Removes the value at the front of the vector.
	// POST-CONDITION: A value is removed from the vector - head is incremented
	//				   and count is decremented.
	void pop_front();

	// Removes the value at the end of the vector.
	// POST-CONDITION: A value is removed from the vector - rear and count are
	//				   decremented.
	void pop_back();

	// Removes the value at the indicated position.
	// PRE-CONDITION:  Position is valid (not out of range).
	// POST-CONDITION: A value is removed from the vector - rear is decremented
	// 				   and all values are moved one index down.
	void erase(int position);

	// Returns the value stored in the cell whose index is stored in head.
	// PRE-CONDITION: count > 0
	Type front();

	// Returns the value stored in the cell whose index is stored in rear.
	// PRE-CONDITION: count > 0.
	Type back();

	// Returns the value stored in the cell at the indicated position.
	// PRE-CONDITION: position is valid (not out of range).
	Type at(int position);

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
	// Creates a vector of size 100 by default if no size is specified or if
	// the size is negative, else creates a vector of the specified size.
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

	// Assigns maxSize to head so all insertions at the front of the vector
	// happen from maxSize - 1 to 0.
	head = maxSize;

	// Assigns rear to be 1 below maxSize so that all insertions at the back of
	// the vector happen from 0 to maxSize - 1.
	rear  = maxSize - 1;

	// Initializes the size of the vector to 0.
	count = 0;

	// Creates a pointer to a dynamic array of the size specified at object
	// instantiation.
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
	// Creates a dynamic array that is twice the size of the initial array.
	Type *copyList = new Type [maxSize * 2];
	Type *temp = list;

	// Makes head = 0 if no push_front() insertions were done.
	if(head >= maxSize)
	{
		head = 0;
	}

	// Copies the contents on the old list into the new list.
	for(int i = 0; i < count; i++)
	{
		copyList[i] = list[head];

		head++;

		// Resets head to 0 in order to loop it back to the front of the dynamic
		// array, but to continue on in the circular array.
		if(head >= maxSize)
		{
			head = 0;
		}
	}

	// Points list to the new list that is twice as big.
	list = copyList;

	// Doubles max size.
	maxSize *= 2;

	// Assings head back to maxSize just as in the constructor.
	head = maxSize;

	// Assigns rear to be 1 less than half the new size of the vector since
	// this is always the index where the last value of the old list will be
	// in the new list.
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
	// Doubles the size of the vector if it is full.
	if(full())
	{
		resize();
	}

	// Changes the value of rear to be the next index up in the dynamic array
	// starting from 0 and going to maxSize - 1.
	rear = (rear + 1) % maxSize;

	// Increments count to signify that the vector has grown by 1.
	count++;

	// Assigns the new value into the appropriate index of the circular array.
	list[rear] = item;
}

template <class Type>
void CircularVector<Type>::push_front(const Type item)
{
	// Doubles the size of the vector if it is full.
	if(full())
	{
		resize();
	}

	// Changes the value of head to be the next index down in the dynamic array
	// starting from maxSize - 1 and going to 0.
	head = (head - 1) % maxSize;

	// Increments count to signify that the vector has grown by 1.
	count++;

	// Assigns the new value into the appropriate index of the circular array.
	list[head] = item;
}

template <class Type>
void CircularVector<Type>::insert(int position, const Type item)
{
	// Escapes the function if an inalid position is entered.
	if(position >= maxSize || position < 0)
	{
		cout << "\nInvalid position.\n\n";

		return;
	}

	// Doubles the size of the vector if it is full.
	if(full())
	{
		resize();
	}

	// Calls the push_front() or push_back methods if the position entered is
	// at either end of the vector, else inserts the item at specified position.
	if(position == 0)
	{
		push_front(item);
	}
	else if(position == maxSize - 1)
	{
		push_back(item);
	}
	else
	{
		// Makes head = 0 if no push_front() insertions were done.
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
			position -= maxSize;
		}

		// Assigns the value of rear to the index that will access each element
		// in the array.
		int moveIndex = rear;

		// Increments rear to the next index since a new value is being inserted.
		rear++;

		// Moves all values after the position where the new value will be
		// inserted to the right by 1.
		while(moveIndex >= position)
		{
			// Brings move index to maxSize - 1 once it is less than 0 to wrap
			// around to the back of the dynamic array but continue on back
			// in the circular array.
			if(moveIndex < 0)
			{
				moveIndex = maxSize - 1;

				list[0] = list[moveIndex];
			}
			else
			{
				// Assigns the value of the current index to the next cell in
				// the array.
				list[moveIndex + 1] = list[moveIndex];
			}

			moveIndex--;
		}

		// Assigns the value to the correct position in the circular array once
		// all values have been shifted.
		list[position] = item;

		// Increments count to signify that the vector has grown by 1.
		count++;
	}
}

template <class Type>
void CircularVector<Type>::pop_front()
{
	count--;

	// Assigns 0 to head if no push_front() insertions were used, else moves head
	// to the next index up.
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

	// Assigns 0 to rear if no push_back() insertions were used else moves
	// rear to the next index down.
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
			position -= maxSize;
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

template <class Type>
Type CircularVector<Type>::at(int position)
{
	// Performs a boundary check and returns -1 if the indicated index is out
	// of bounds.
	if(position < 0 || position >= maxSize)
	{
		cout << "\nOut of bounds!\n\n";

		return -1;
	}

	position += head;

	// Subtracts maxSize from position if position is out of bounds so that
	// position is reset at the beginning of the array but moves to the
	// correct index of the circular array.
	if(position >= maxSize)
	{
		position -= maxSize;
	}

	return list[position];
}

#endif
