#pragma once
#include "Node.h"
class LinkedListAsQueue
{
	Node* Front,*Rear;
public:
	LinkedListAsQueue();
	void EnQueue(int data);
	bool DeQueue(int& data);
	bool IsEmpty();
};

