#pragma once
#include <memory>
#include "listNode.h"

/*! \class Double Linked List
    \brief A double linked list data structure
*/


using namespace std;

template<class G>
class DoubleLinkedList
{
private :
	unsigned int size;
	shared_ptr<ListNode<G>> front;
	shared_ptr<ListNode<G>> back;
	shared_ptr<ListNode<G>> current;
public :
	DoubleLinkedList();
	void pushFront(G newElement); //Push node at Front
	void pushBack(G newElement); //Push node at Back
	void pushFrontCurrent(G newElement); //Push node before Current
	void pushBackCurrent(G newElement); //Push node after Current
	G removeFront(); //Remove the First Element
	void removeBack(); //Remove the Last Element
	void sort(); //Sorts the List Assending

	bool isEmpty(); //Retunes whether list is empty
	unsigned int getSize(); //Retunrs size of List
	G getFront(); //Returns First Element
	G getBack(); //Returns Last Element
	G getCurrent(); //Returns Last Element
	void moveForward(); //Move Current Forward
	void moveBack(); //Move Current Back
};

template<class G>
inline DoubleLinkedList<G>::DoubleLinkedList()
{
	size = 0;
	front = nullptr;
	back = nullptr;
	current = nullptr;
}

template<class G>
inline void DoubleLinkedList<G>::pushFront(G newElement)
{
	front = shared_ptr<ListNode<G>>(new ListNode<G>(newElement, front, nullptr));
	size++;
}

template<class G>
inline void DoubleLinkedList<G>::pushBack(G newElement)
{
	back = shared_ptr<ListNode<G>>(new ListNode<G>(newElement, nullptr, back));
	size++;
}

template<class G>
inline void DoubleLinkedList<G>::pushFrontCurrent(G newElement)
{
	size++;
}

template<class G>
inline void DoubleLinkedList<G>::pushBackCurrent(G newElement)
{
	size++;
}

template<class G>
inline G DoubleLinkedList<G>::removeFront()
{
	G result = front->getData();
	front = front->getNext();
	size--;
	return result;
}

template<class G>
inline void DoubleLinkedList<G>::removeBack()
{
	size--;
}

template<class G>
inline void DoubleLinkedList<G>::sort()
{

}

template<class G>
inline bool DoubleLinkedList<G>::isEmpty()
{
	return size == 0;
}

template<class G>
inline unsigned int DoubleLinkedList<G>::getSize()
{
	return size;
}

template<class G>
inline G DoubleLinkedList<G>::getFront()
{
	return front->getData();
}

template<class G>
inline G DoubleLinkedList<G>::getBack()
{
	return front->getData();
}

template<class G>
inline G DoubleLinkedList<G>::getCurrent()
{
	return current->getData();
}

template<class G>
inline void DoubleLinkedList<G>::moveForward()
{
	current = current->getNext();
}

template<class G>
inline void DoubleLinkedList<G>::moveBack()
{
	current = current->getPrevious();
}
