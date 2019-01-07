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
	for (int i = 0; i < 10; i++) 
	{
		myList.pushFront(rand() % 100);
	}

	cout << "<--Generate List-->" << endl << endl;
	myList.printList();

	cout << endl << "<--Push Front-->" << endl << endl;
	myList.pushFront(99);
	myList.printList();

	cout << endl << "<--Push Back-->" << endl << endl;
	myList.pushBack(22);
	myList.printList();

	cout << endl << "<--Sorting List Accending-->" << endl << endl;
	myList.sortAccending();
	myList.printList();

	cout << endl << "<--Remove Front-->" << endl << endl;
	myList.removeFront();
	myList.printList();

	cout << endl << "<--Remove Back-->" << endl << endl;
	myList.removeBack();
	myList.printList();

	cout << endl << "<--Move Current Back-->" << endl << endl;
	cout << "Current = " << myList.getCurrent() << endl;
	myList.moveBack();
	cout << "Current = " << myList.getCurrent() << endl;

	cout << endl << "<--Move Current Forward-->" << endl << endl;
	cout << "Current = " << myList.getCurrent() << endl;
	myList.moveForward();
	cout << "Current = " << myList.getCurrent() << endl;

	cout << endl << "<--Remove Current-->" << endl << endl;
	myList.removeCurrent();
	myList.printList();

	cout << endl << "<--Push Infront Current-->" << endl << endl;
	cout << "Current = " << myList.getCurrent() << endl;
	myList.pushFrontCurrent(33);
	myList.printList();

	cout << endl << "<--Push Behind Current-->" << endl << endl;
	cout << "Current = " << myList.getCurrent() << endl;
	myList.pushBackCurrent(67);
	myList.printList();



	while (myList.getSize() != 0)
	{
		myList.removeBack();
	}

	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
	return 0;
}
