/**
@file main.cpp
*/


/*! \mainpage Lab Book 3
 *
 * Implementation of a Double Linked List
 */

// Define and includes to show memory leak report
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>
#include "doubleLinkedList.h"

int main() /** Entry point for the application */
{
	DoubleLinkedList<int> myList;

	myList.pushFront(10);
	myList.pushFront(100);
	myList.pushFront(1000);
	myList.pushFront(100);
	myList.pushFront(10);

	while (myList.getSize() != 0)
	{
		std::cout << myList.removeFront() << endl;
	}

	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
	return 0;
}
