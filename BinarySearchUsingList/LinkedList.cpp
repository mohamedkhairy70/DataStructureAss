#include "LinkedList.h"
#include <cstddef>
#include <iostream>
using namespace std;
LinkedList::LinkedList()
{
	Index = 0;
	Root = NULL;
}

void LinkedList::Add(int data)
{
	Node* node = new Node(data);
	if (Root == NULL)
	{
		Root = node;
	}
	else
	{
		Node* Current = Root;
		Node* Parent = Root;
		while (Current != NULL)
		{
			Parent = Current;
			if (Current->Right->getData() > data)
			{
				Current = Current->Right;
			}
			else if (Current->Left->getData() < data)
			{
				Current = Current->Left;
			}
		}

		if (Parent->Right->getData() > data)
		{
			Parent->Right = node;
		}
		else if (Parent->Left->getData() < data)
		{
			Parent->Left = node;
		}
	}
	Index++;
}


//Node* LinkedList::Search(int data)
//{
//	Node* current = Head;
//	int _Data = 0;
//	while (current != NULL)
//	{
//		if (current->getData() == data)
//		{
//			return current;
//		}
//		current = current->Next;
//	}
//	return NULL;
//}

int LinkedList::GetLenth()
{
	return Index;
}
