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
	ListNode(G newData, shared_ptr<ListNode<G>>& newNext, shared_ptr<ListNode<G>>& newPrevious);
	G getData();
	shared_ptr<ListNode> getNext();
	shared_ptr<ListNode> getPrevious();
};

template<class G>
inline ListNode<G>::ListNode(G newData, shared_ptr<ListNode<G>>& newNext, shared_ptr<ListNode<G>>& newPrevious)
{
	data = newData;
	next = newNext;
	previous = newPrevious;
}

template<class G>
inline G ListNode<G>::getData()
{
	return data();
}

template<class G>
inline shared_ptr<ListNode<G>> ListNode<G>::getNext()
{
	return next;
}

template<class G>
inline shared_ptr<ListNode<G>> ListNode<G>::getPrevious()
{
	return previous();
}
