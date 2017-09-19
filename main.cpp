/******************************************************************************
 * AUTHOR        : Jesus Sanchez
 * ASSIGNMENT #3 : Queue-DeQue
 * CLASS         : CS1D
 * SECTION       : MW: 3:00pm
 * DUE DATE      : 09/20/2017
 *****************************************************************************/

#include "LinkedQueueType.h"
#include "CircularVector.h"

/******************************************************************************
 * QUEUE-DEQUE
 * ----------------------------------------------------------------------------
 * This program will implement the queue container class based on a linked
 * deque class whose functions will be wrapped in the Queue class and test the
 * functions. Then, the vector ADT will be implemented using an expandable
 * circular array. The vector will be printed after each insertion and deletion
 * and all other necessary functions will also be implemented and tested.
 * ----------------------------------------------------------------------------
 * INPUT:
 *    There are no inputs.
 *
 * OUTPUT:
 *    stringQueue after each insertion and deletion.
 *	  intVector after each insertion and deletion.
 *****************************************************************************/
int main()
{
	cout << "NAME          : Jesus Sanchez\n"
		 << "ASSIGNMENT #3 : Queue DeQue\n"
		 << "CLASS         : CS1D - MW: 3:00pm\n"
		 << "DUE DATE      : 09/20/2017\n\n"
		 << "DESCRIPTION : This program will implement the queue container\n"
		    "class based on a linked deque class whose functions will be\n"
		    "wrapped in the Queue class and test the functions. Then, the\n"
		    "vector ADT will be implemented using an expandable circular array.\n"
		    "The vector will be printed after each insertion and deletion and\n"
		    "all other necessary functions will also be implemented and tested.\n\n";

	LinkedQueueType<string> stringQueue;

	string string1 = "A man, a plan, a canal, Panama";
	string string2 = "Was it a car or a cat I saw?";
	string string3 = "Sit on a potato pan, Otis";
	string string4 = "No lemon, no melon";

	cout << "***** Part 1 *****\n\n";

	// Tests the empty() method of the LinkedQueueType class.
	if(stringQueue.empty())
	{
		cout << "The queue is empty!\n\n";
	}

	// Tests the enqueue() method of the LinkedQueueType class.
	cout << "Adding values to the queue...\n\n";
	stringQueue.enqueue(string1);
	stringQueue.enqueue(string2);

	// Tests the size() method of the LinkedQueueType class.
	cout << "There are " << stringQueue.size() << " items in the queue.\n\n";

	// Tests the front() and dequeue() methods of the LinkedQueueType class.
	cout << "The values in the queue are:\n";
	while(!stringQueue.empty())
	{
		cout << stringQueue.front() << endl;

		stringQueue.dequeue();
	}

	// Adds more values to the queue.
	cout << "\nAdding more values to the queue...\n\n";
	stringQueue.enqueue(string3);
	stringQueue.enqueue(string4);

	// Prints the values in the queue.
	cout << "The values in the queue are:\n";
	while(!stringQueue.empty())
	{
		cout << stringQueue.front() << endl;

		stringQueue.dequeue();
	}

	// Prints the number of items in the queue after they have been removed.
	cout << "\nThere are " << stringQueue.size() << " items in the queue.\n\n";

	cout << "***** Part 2 *****\n\n";

	// Initializes a vector of size 2.
	CircularVector<int> intVector(2);

	// Prints a statement if the vector is empty to test the empty() method.
	if(intVector.empty())
	{
		cout << "The vector is empty!\n\n";
	}

	// Testing push_front() method.
	cout << "Adding values to the front of the vector...\n";
	for(int i = 5; i >= 1; i--)
	{
		intVector.push_front(i);
	}

	// Prints the values in the vector to test the size() and at() methods.
	for(int i = 0; i < intVector.size(); i++)
	{
		cout << intVector.at(i) << " ";
	}

	// Tests the pop_front() method and prints the values in the vector after
	// using the function twice.
	cout << "\n\nPopping the first 2 values off the vector...\n";
	intVector.pop_front();
	intVector.pop_front();

	for(int i = 0; i < intVector.size(); i++)
	{
		cout << intVector.at(i) << " ";
	}

	// Test the push_back() method and adds values to the back of the vector.
	cout << "\n\nAdding values to the back of the vector...\n";
	for(int i = 6; i <= 9; i++)
	{
		intVector.push_back(i);
	}

	for(int i = 0; i < intVector.size(); i++)
	{
		cout << intVector.at(i) << " ";
	}

	// Tests the pop_back() function and prints the values in the vector after
	// removing the last 3 values.
	cout << "\n\nRemoving the last 3 values from the vector...\n";
	for(int i = 1; i <= 3; i++)
	{
		intVector.pop_back();
	}

	for(int i = 0; i < intVector.size(); i++)
	{
		cout << intVector.at(i) << " ";
	}

	// Tests the insert() method by inserting a number at the specified position
	// and prints the vector after the insertion.
	cout << "\n\nInserting a new item at position 2...\n";
	intVector.insert(2, 10);

	for(int i = 0; i < intVector.size(); i++)
	{
		cout << intVector.at(i) << " ";
	}

	// Tests the erase() method by deleting the value in the indicated position
	// and printing the values in the vector.
	cout << "\n\nErasing the value at position 1...\n";
	intVector.erase(1);

	for(int i = 0; i < intVector.size(); i++)
	{
		cout << intVector.at(i) << " ";
	}

	// Erases another value in the vector and prints the vector.
	cout << "\n\nErasing the value at position 2...\n";
	intVector.erase(2);

	for(int i = 0; i < intVector.size(); i++)
	{
		cout << intVector.at(i) << " ";
	}

	// Direct test of the size() method.
	cout << "\n\nThere are " << intVector.size() << " values in the vector.\n\n";

	cout << "Popping all values off the vector.\n\n";

	// Pops all of the values off the vector.
	while(!intVector.empty())
	{
		intVector.pop_back();
	}

	// Prints the number of values in the vector.
	cout << "There are " << intVector.size() << " values in the vector.\n\n";

	return 0;
}
