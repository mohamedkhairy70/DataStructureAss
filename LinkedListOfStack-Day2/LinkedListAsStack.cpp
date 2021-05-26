#include "LinkedListAsStack.h"
LinkedListAsStack::LinkedListAsStack()
{
	Top = nullptr;
}
void LinkedListAsStack::Push(int data)
{
	Node* newNode = new Node(data);
	if (Top == nullptr)
	{
		Top = newNode;
	}
	else
	{
		newNode->Prev = Top;
		Top = newNode;
	}
}

bool LinkedListAsStack::Pop(int& data)
{
	if (!IsEmpty())
	{
		data = Top->GetData();

		Node* Ptr = Top;
		Top = Top->Prev;

		delete Ptr;
		return true;
	}
	return false;
}

bool LinkedListAsStack::IsEmpty()
{
	return Top == nullptr;
}

