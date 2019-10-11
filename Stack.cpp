#include<iostream>
#include"Node.cpp"
using namespace std;
class Stack
{
protected:
	Node *top;
	int count;
public:
	Stack() :top(NULL),count(0)
	{
	}
	Stack(Node*ptr) :top(ptr)
	{

		top->nextNode = NULL;
		ptr = NULL;
	}
	bool isNotEmpty()
	{
		if (top)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isEmpty()
	{
		if (top)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	Stack& push(Node *ptr)
	{
		ptr->nextNode = top;
		top = ptr;
		ptr = NULL;
		return *this;
	}
	Node* pop()
	{
		Node *ptr = top;
		top = top->nextNode;
		ptr->nextNode = NULL;
		return ptr;
	}
	Stack(const Stack* &src)
	{
		this->top = src->top;
		if (src->top)
		{
			Node *sptr, *dptr;
			new Node(*src->top);
			dptr=this->top= new Node(*src->top);
			sptr = src->top->nextNode;
			while (sptr)
			{
				dptr->nextNode = new Node(*sptr);
				sptr = sptr->nextNode;
				dptr = dptr->nextNode;
			}
		}

	}
	Stack& operator=(const Stack& robj)
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
		}
		return *this;
	}
	void print()const
	{
		if (!top)
		{
			cout << "Stack is empty!" << endl;
		}
		else
		{
			Node *ptr = top;
			while (ptr)
			{
				ptr->getNext();
				ptr = ptr->nextNode;
			}
		}
	}
	~Stack()
	{
		Node *ptr = top;
		while (ptr)
		{
			ptr = ptr->nextNode;
			delete top;
			top = ptr;
		}
	}
};