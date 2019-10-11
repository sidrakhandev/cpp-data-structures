#include<iostream>
#include"Stack.cpp"
using namespace std;
class Queue: protected Stack
{	
public:
	Node *tail;
	Queue() :tail(NULL)
	{
	}
	Queue(Node *&ptr):  Stack(ptr),tail(top)
	{
	}
	bool isNotEmpty()const
	{
		return Stack::isNotEmpty();
	}
	bool isEmpty()const
	{
		return Stack::isEmpty();
	}
	Node* remove()
	{
		if (!top->nextNode)
		{
			tail = NULL;
			return Stack::pop();
		}
	}
	Queue & add(Node*&ptr)
	{
		if (tail)
		{
			tail->nextNode = ptr;
			tail = tail->nextNode;
		}
		else
		{
			tail = top = ptr;
			tail->nextNode = NULL;
			ptr = NULL;
			return *this;
		}
	}
		void print()const
		
		{
			Stack::print();
		}
		Queue(const Queue&src)
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
		Queue& operator=(const Stack& robj)
		{
			if (this == &robj)
			{
				return *this;
			}
			if (true)
			{
				Stack temp;
				temp.top = top;
			}
			if (true)
			{
				Stack temp = robj;
				top = temp.top;
				temp.top = NULL;
				tail = NULL;
			}
			return *this;
		}
};