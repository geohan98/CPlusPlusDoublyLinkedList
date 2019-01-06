#pragma once
#include <memory>

/*! \class List Node
\brief A List Node
*/


using namespace std;

template<class G>
class ListNode
{
private:
	shared_ptr<ListNode> next; //!< Pointer to next element in list
	shared_ptr<ListNode> previous; //!< Pointer to previous element in list
	G data; //!< The Data of this Element
public:
	//! Contructor
	/*!
	\param newElement G, new element to be added
	*/
	ListNode(G newElement);

	//! Decontrusctor
	~ListNode();

	//! Retuns the Data of the element
	G getData();

	//! Set the Data of this element
	/*!
	\param newElement G, new element to be set
	*/
	void setData(G newData);

	//! Retuns the pointer to the next element
	shared_ptr<ListNode> getNext();

	//! Sets the pointer to the next element
	/*!
	\param newNext shared_ptr<ListNode<G>>, new pointer
	*/
	void setNext(shared_ptr<ListNode<G>> newNext);

	//! Retuns the pointer of the previous element
	shared_ptr<ListNode> getPrevious();

	//! Sets the pointer to the previous element
	/*!
	\param newNext shared_ptr<ListNode<G>>, new pointer
	*/
	void setPrevious(shared_ptr<ListNode<G>> newPrevious);
};

template<class G>
inline ListNode<G>::ListNode(G newElement)
{
	data = newElement;
	next = nullptr;
	previous = nullptr;
}

template<class G>
inline ListNode<G>::~ListNode()
{
	//cout << "Destructing " << this << endl;
	next = nullptr;
	previous = nullptr;
}

template<class G>
inline G ListNode<G>::getData()
{
	return data;
}

template<class G>
inline void ListNode<G>::setData(G newData)
{
	data = newData;
}

template<class G>
inline shared_ptr<ListNode<G>> ListNode<G>::getNext()
{
	return next;
}

template<class G>
inline void ListNode<G>::setNext(shared_ptr<ListNode<G>> newNext)
{
	next = newNext;
}

template<class G>
inline shared_ptr<ListNode<G>> ListNode<G>::getPrevious()
{
	return previous;
}

template<class G>
inline void ListNode<G>::setPrevious(shared_ptr<ListNode<G>> newPrevious)
{
	previous = newPrevious;
}
