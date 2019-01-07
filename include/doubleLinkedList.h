#pragma once
#include <memory>
#include "listNode.h"

/*! \class Double Linked List
    \brief A Double Linked List data structure
*/


using namespace std;

template<class G>
class DoubleLinkedList
{
private :
	unsigned int size; //!< Size of List
	shared_ptr<ListNode<G>> front; //!< Pointer to front of List
	shared_ptr<ListNode<G>> back; //!< Pointer to back of List
	shared_ptr<ListNode<G>> current; //!< Pointer to current element in list
public :
	//! Contructor
	DoubleLinkedList();

	//!Push node at Front
	/*!
	\param newElement G, new element to be added
	*/
	void pushFront(G newElement);

	//!Push node at Back
	/*!
	\param newElement G, new element to be added
	*/
	void pushBack(G newElement);

	//!Push node before Current
	/*!
	\param newElement G, new element to be added
	*/
	void pushFrontCurrent(G newElement);

	//!Push node after Current
	/*!
	\param newElement G, new element to be added
	*/
	void pushBackCurrent(G newElement);

	//!Remove the First Element
	G removeFront();

	//!Remove the Last Element
	G removeBack();

	//!Remove the Current Element
	G removeCurrent();

	//!Sorts the List Assending
	void sortAccending();

	//!Retunes whether list is empty
	bool isEmpty();

	//!Retunrs size of List
	unsigned int getSize();

	//!Returns First Element
	G getFront();

	//!Returns Last Element
	G getBack();

	//!Returns Last Element
	G getCurrent();

	//!Move Current Forward
	void moveForward();

	//!Move Current Back
	void moveBack();

	//!Current to the Front
	void moveCurrentToFront();

	//!Current to the Back
	void moveCurrentToBack();

	//!Prints List
	void printList();
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
	tmp = nullptr;
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
	if (front == current && front == back)
	{
		current = nullptr;
		front = nullptr;
		back = nullptr;
	}
	else if (front == current)
	{
		current = front->getNext();
	}
	else
	{
		front = front->getNext();
	}
	if (front != nullptr)
	{
		front->setPrevious(nullptr);
	}
	
	size--;

	return result;
}

template<class G>
inline G DoubleLinkedList<G>::removeBack()
{
	G result = back->getData();
	if (back == current && back == front)
	{
		current = nullptr;
	}
	else if (back == current)
	{
		current = back->getPrevious();
	}
	if (back == front)
	{
		front = nullptr;
		back = nullptr;
	}
	else
	{
		back = back->getPrevious();
	}
	if (back != nullptr)
	{
		back->setNext(nullptr);
	}
	size--;
	return result;
}

template<class G>
inline G DoubleLinkedList<G>::removeCurrent()
{
	G result = current->getData();

	if (current == front && current == back)
	{
		//cout << "Current == Front == Back" << endl;
		front = nullptr;
		back = nullptr;
		current = nullptr;
	}
	else if(current == front)
	{
		//cout << "Current == Front" << endl;
		current = current->getNext();
		current->getPrevious()->setNext(nullptr);
		current->getPrevious()->setPrevious(nullptr);
		current->setPrevious(nullptr);
		front = current;
	}
	else if(current == back)
	{
		//cout << "Current == Back" << endl;
		current = current->getPrevious();
		current->getNext()->setPrevious(nullptr);
		current->getNext()->setNext(nullptr);
		current->setNext(nullptr);
		back = current;
	}
	else
	{
		shared_ptr<ListNode<G>> tmp = current;

		current->getPrevious()->setNext(current->getNext());
		current->getNext()->setPrevious(current->getPrevious());
		current = current->getNext();
		tmp->setNext(nullptr);
		tmp->setPrevious(nullptr);
		tmp = nullptr;
	}

	size--;
	return G();
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

template<class G>
inline void DoubleLinkedList<G>::moveCurrentToFront()
{
	current = front;
}

template<class G>
inline void DoubleLinkedList<G>::moveCurrentToBack()
{
	current = back;
}

template<class G>
inline void DoubleLinkedList<G>::printList()
{
	moveCurrentToFront();

	for (int i = 0; i < size; i++)
	{
		cout << current->getData() << endl;
		moveForward();
	}
}
