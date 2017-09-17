/******************************************************************************
 * AUTHOR        : Jesus Sanchez
 * ASSIGNMENT #3 : Queue-DeQue
 * CLASS         : CS1D
 * SECTION       : MW: 3:00pm
 * DUE DATE      : 09/20/2017
 *****************************************************************************/

#include "LinkedQueueType.h"

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
 *
 *
 * OUTPUT:
 *
 *****************************************************************************/
int main()
{
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

	return 0;
}
