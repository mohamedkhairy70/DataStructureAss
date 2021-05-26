#include "LinkedList.h"
#include <cstddef>
#include <iostream>
using namespace std;
LinkedList::LinkedList()
{
	Index = 0;
	Head = Tail = NULL;
}

void LinkedList::Add(int data)
{
	Node * node = new Node(data);
	if (Head == NULL)
	{
		Head = Tail = node;
	}
	else
	{
		Tail->Next = node;
		node->Prev = Tail;
		Tail = node;
	}
	Index++;
}

void LinkedList::InsertAfter(int LastData,int data)
{
	Node* node = new Node(data);
	Node* LastNode = Search(LastData);
	if (LastData == NULL)
	{
		cout << "Can Not Find This Node" << "\t";
		return;
	}
	if (Head == NULL)
	{
		Head = Tail = node;
	}
	else
	{
		Node* nod = LastNode->Next;
		LastNode->Next->Prev = node;
		LastNode->Next = node;

		node->Next = nod;
		node->Prev = LastNode;
	}
	Index++;
}

void LinkedList::Display()
{
	Node* current = Head;
	while (current != NULL)
	{
		cout << current->getData() << "\t";
		current = current->Next;
	}
}

void LinkedList::Delete(int data)
{
	Node* pDelete = Search(data);
	if (pDelete == NULL)
		return;

	if (pDelete == Head)
	{
		if (pDelete == Tail)
		{
			Head = Tail = NULL;
		}
		else
		{
			Head = Head->Next;
			Head->Prev = NULL;
		}
	}
	else if (pDelete == Tail)
	{
		Tail = Tail->Prev;
		Tail->Next = NULL;
	}
	else
	{
		pDelete->Prev->Next = pDelete->Next;
		pDelete->Next->Prev = pDelete->Prev;
	}

	delete pDelete;
	Index--;
}

void LinkedList::PrintByIndex(int index)
{
	Node* current = Head;
	int _Data = 0;
	int Check = 0;
	for (int i = 0; i < Index; i++)
	{
		if (i == index)
		{
			cout << current->getData() << "\t";
			Check = 1;
		}
		current = current->Next;
	}
	if (Check == 0)
	{
		cout << "Can Not Find This Index" << "\t";
	}

}

Node* LinkedList::Search(int data)
{
	Node* current = Head;
	int _Data=0;
	while (current != NULL)
	{
		if (current->getData() == data)
		{
			return current;
		}
		current = current->Next;
	}
	return NULL;
}

int LinkedList::GetLenth()
{
	return Index;
}
