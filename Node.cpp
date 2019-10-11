class Node
{
	int object;
public:
	Node *nextNode;
	int priority;
	int get()
	{
		return object;
	}
	void set(int object)
	{
		this->object = object;
	}
	Node *getNext()
	{
		return nextNode;
	}
	void setNext(Node *nextNode)
	{
		this->nextNode = nextNode;
	}
};
