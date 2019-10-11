#include<iostream>
#include"Queue.cpp"
#include"Stack.cpp"
#include"Node.cpp"
class PriorityQueue :public Queue
{
public:
	PriorityQueue(Node*&ptr)
	{
	}
	PriorityQueue()
	{
	}
	PriorityQueue &add(Node *&ptr)
	{
		if (!top)
		{
			top = tail = ptr;
			tail->nextNode = ptr = NULL;
		}
		else if (top->priority < ptr->priority)
			Stack::push(ptr);
		else if (top->priority >= ptr->priority)
			Queue::add(ptr);
		else
		{
			Node *rptr = top;
			while (rptr->priority >= ptr->priority)
			{
				rptr = rptr->nextNode;
			}
			ptr->nextNode = rptr->nextNode;
			rptr->nextNode = ptr;
			ptr = NULL;
		}
		return *this;	
	}
	PriorityQueue(const PriorityQueue& src)
	{
		this->top = src.top;
		this->tail = src.tail;
		if (src.top)
		{
			Node *sptr, *dptr;
			dptr = this->top = new Node(*src.top);
			sptr = top->nextNode;
			while (sptr)
			{
				dptr->nextNode = new Node(*sptr);
				sptr = sptr->nextNode;
				dptr = dptr->nextNode;
			}
			tail=dptr;
		}

	}
	PriorityQueue& operator=(const PriorityQueue& robj)
	{
		if (this == &robj)
			return *this;
		if (true)
		{
			PriorityQueue temp;
			temp.top = top;
			temp.tail = tail;
		}
		if (true)
		{
			PriorityQueue temp = robj;
			top = temp.top;
			tail = temp.tail;
			temp.top = NULL;
			temp.tail = NULL;
		}
	}
};
