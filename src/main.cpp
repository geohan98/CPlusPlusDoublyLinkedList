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
#include <random>
#include <time.h>
#include <iostream>
#include "doubleLinkedList.h"

int main() /** Entry point for the application */
{
	DoubleLinkedList<int> myList;
	srand(time(0));
	for (int i = 0; i < 1; i++) 
	{
		myList.pushFront(rand() % 100);
	}


	myList.sortAccending();


	while (myList.getSize() != 0)
	{
		std::cout << myList.removeFront() << endl;
	}

	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
	return 0;
}
