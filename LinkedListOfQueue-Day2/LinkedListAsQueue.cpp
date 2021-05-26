#include "LinkedListAsQueue.h"
#include <cstddef>

LinkedListAsQueue::LinkedListAsQueue()
{
	Front = Rear = NULL;
}

void LinkedListAsQueue::EnQueue(int data)
{
	Node* NewNode = new Node(data);
	if (Front == NULL)
	{
		Front = Rear = NewNode;
	}
	else
	{
		Rear->Next = NewNode;
		Rear = NewNode;
	}
}

bool LinkedListAsQueue::DeQueue(int& data)
{
	if (!IsEmpty())
	{
		data = Front->GetData();

		Node* prtFront = Front;
		Front = Front->Next;
		
		delete prtFront;
		return true;
	}
	return false;
}

bool LinkedListAsQueue::IsEmpty()
{
	return Front == NULL;
}
// && Front != Rear