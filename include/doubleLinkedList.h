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
	void sortAccending(); //Sorts the List Assending

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
	shared_ptr<ListNode<G>> tmp = shared_ptr<ListNode<G>>(new ListNode<G>(newElement));
	if (front != nullptr)
	{
		tmp->setNext(front);
		front->setPrevious(tmp);
	}
	if (back == nullptr)
	{
		back = tmp;
	}
	if (current == nullptr)
	{
		current = tmp;
	}
	front = tmp;
	size++;
}

template<class G>
inline void DoubleLinkedList<G>::pushBack(G newElement)
{
	shared_ptr<ListNode<G>> tmp = shared_ptr<ListNode<G>>(new ListNode<G>(newElement));
	tmp->setPrevious(back);
	if (back != nullptr)
	{
		back->setNext(tmp);
	}
	if (front == nullptr)
	{
		front = tmp;
	}
	if (current == nullptr)
	{
		current = tmp;
	}
	back = tmp;
	size++;
}

template<class G>
inline void DoubleLinkedList<G>::pushFrontCurrent(G newElement)
{
	shared_ptr<ListNode<G>> tmp = shared_ptr<ListNode<G>>(new ListNode<G>(newElement));
	tmp->setNext(current);
	tmp->setPrevious(current->getPrevious());
	current->setPrevious(tmp);
	if (tmp->getPrevious() != nullptr)
	{
		tmp->getPrevious()->setNext(tmp);
	}

	if (current == front)
	{
		front = tmp;
	}

	size++;
}

template<class G>
inline void DoubleLinkedList<G>::pushBackCurrent(G newElement)
{
	shared_ptr<ListNode<G>> tmp = shared_ptr<ListNode<G>>(new ListNode<G>(newElement));
	tmp->setPrevious(current);
	tmp->setNext(current->getNext());
	current->setNext(tmp);
	if (tmp->getNext() != nullptr)
	{
		tmp->getNext()->setPrevious(tmp);
	}

	if (current = back)
	{
		back = tmp;
	}
	size++;
}

template<class G>
inline G DoubleLinkedList<G>::removeFront()
{
	G result = front->getData();
	if (front == current)
	{
		current = current->getNext();
	}
	front = front->getNext();
	size--;

	return result;
}

template<class G>
inline void DoubleLinkedList<G>::removeBack()
{
	G result = back->getData();
	if (back == current)
	{
		current = current->getPrevious();
	}
	back = back->getPrevious();
	size--;
	return result;
}

template<class G>
inline void DoubleLinkedList<G>::sortAccending()
{

	for (int i = 0; i < size; i++)
	{
		current = front;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (current->getData() > current->getNext()->getData())
			{
				//Swap
				shared_ptr<ListNode<G>> tmp1 = current->getPrevious();
				shared_ptr<ListNode<G>> tmp2 = current;
				shared_ptr<ListNode<G>> tmp3 = current->getNext();
				shared_ptr<ListNode<G>> tmp4 = current->getNext()->getNext();

				if (tmp1 !=nullptr)
				{
					tmp1->setNext(tmp3);
				}
				else
				{
					front = tmp3;
				}
				tmp2->setNext(tmp4);
				tmp2->setPrevious(tmp3);
				tmp3->setNext(tmp2);
				tmp3->setPrevious(tmp1);
				if (tmp4 != nullptr)
				{
					tmp4->setPrevious(tmp2);
				}
				else
				{
					back = tmp2;
				}
			}
			else
			{
				moveForward();
			}
		}
	}
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
	return back->getData();
}

template<class G>
inline G DoubleLinkedList<G>::getCurrent()
{
	return current->getData();
}

template<class G>
inline void DoubleLinkedList<G>::moveForward()
{
	if (current != back)
	{
		current = current->getNext();
	}
}

template<class G>
inline void DoubleLinkedList<G>::moveBack()
{
	if (current != front)
	{
		current = current->getPrevious();
	}
}
