#pragma once
#include "Node.h"

class LinkedListAsStack
{
	Node* Top;
public:
	LinkedListAsStack();
	void Push(int data);
	bool Pop(int& data);
	bool IsEmpty();
};

