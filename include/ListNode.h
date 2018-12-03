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
	shared_ptr<ListNode> next;
	shared_ptr<ListNode> previous;
	G data;
public:
	ListNode(G newElement);
	G getData();
	shared_ptr<ListNode> getNext();
	void setNext(shared_ptr<ListNode<G>> newNext);
	shared_ptr<ListNode> getPrevious();
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
inline G ListNode<G>::getData()
{
	return data;
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
