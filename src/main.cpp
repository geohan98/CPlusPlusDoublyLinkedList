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

	myList.pushFront(1);
	myList.pushBack(2);
	myList.pushBack(3);
	myList.pushBack(4);
	myList.pushBack(5);

	std::cout << "Front:" << myList.getFront() << endl;
	std::cout << "Back:" << myList.getBack() << endl;
	std::cout << "Current:" << myList.getCurrent() << endl;

	myList.pushFrontCurrent(69);

	std::cout << "Front:" << myList.getFront() << endl;
	std::cout << "Back:" << myList.getBack() << endl;
	std::cout << "Current:" << myList.getCurrent() << endl;

	while (myList.getSize() != 0)
	{
		std::cout << myList.removeFront() << endl;
	}

	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
	return 0;
}
