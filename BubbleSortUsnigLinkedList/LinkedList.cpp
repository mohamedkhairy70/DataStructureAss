#include "LinkedList.h"
#include <cstddef>
#include <iostream>
using namespace std;
LinkedList::LinkedList()
{
	Index = 0;
	Head = Tail = NULL;
}

LinkedList LinkedList::operator=(LinkedList* linkedList)
{
	Node* current = linkedList->Head;
	LinkedList* LinkedCopy = this;
	while (current != NULL)
	{
		LinkedCopy->Add(current->getData());
		current = current->Next;
	}

	return *this;
}

void LinkedList::Add(int data)
{
	Node* node = new Node(data);
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

void LinkedList::InsertAfter(int LastData, int data)
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

void LinkedList::InsertBefore(int LastData, int data)
{
	Node* node = Search(data);
	Node* LastNode = Search(LastData);
	if (LastData == NULL)
	{
		cout << "Can Not Find This Node" << "\t";
		return;
	}
	if (Tail == NULL)
	{
		Head = Tail = LastNode;
		LastNode->Next = node;
		node->Prev = node;
	}
	else
	{
		Node* nd = LastNode;
		Node* nd2 = node;
		LastNode->Next->Prev = node;
		if (LastNode->Prev != NULL)
		{
			LastNode->Prev->Next = node;
		}
		if (nd2->Next)
		{
			nd2->Prev->Next = nd;
			nd2->Next->Prev = nd;
		}
		else if (nd2->Prev)
		{
			nd2->Prev->Next = nd;
		}
		delete LastNode;
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

bool LinkedList::PrintByIndex(int index,int &data)
{
	Node* current = Head;
	int _Data = 0;
	for (int i = 0; i < Index; i++)
	{
		if (i == index)
		{
			data = current->getData();
			return true;
		}
		current = current->Next;
	}
	return false;
	

}

void LinkedList::my_swapByNodeOnly(Node* current, Node* Pcurrent)
{
	Node* tempcurrent = current;
	Node* tempcurrentPrev = current;
	//Node* tempcurrentNext = tempcurrent->Next;


	Node* tempPcurrent = Pcurrent;
	//Node* tempPcurrentPrev = tempPcurrent->Prev;
	Node* tempPcurrentNext = Pcurrent;


	if (tempcurrent->Prev != NULL)
	{
		tempcurrentPrev = tempcurrent->Prev;
	}
	else
	{
		tempcurrentPrev = NULL;
	}


	if (tempPcurrent->Next != NULL)
	{
		tempPcurrentNext = tempPcurrent->Next;
	}
	else
	{
		tempPcurrentNext = NULL;
	}


	if (current->Prev != NULL || Pcurrent->Next != NULL)
	{
		if (tempcurrentPrev != NULL)
		{
			tempcurrentPrev->Next = tempPcurrent;
			tempPcurrent->Prev = tempcurrentPrev;
		}
		else
		{
			tempPcurrent->Prev = NULL;
			Head = tempPcurrent;
		}



		if (tempPcurrentNext != NULL)
		{
			tempPcurrentNext->Prev = tempcurrent;
			tempcurrent->Next = tempPcurrentNext;
		}
		else
		{
			tempcurrent->Next = NULL;
			Tail = tempcurrent;
		}


		tempPcurrent->Next = tempcurrent;
		tempcurrent->Prev = tempPcurrent;

		
		current = tempPcurrent;
		Pcurrent = tempcurrent;
	}
}



void LinkedList::my_swap(Node* current, Node* node_2)
{
	int temp = current->getData();
	current->SetData(node_2->getData());
	node_2->SetData(temp);
}
LinkedList LinkedList::BubbleSort()
{

	int swapped;

	Node* lPtr; // left pointer will always point to the start of the list
	do
	{
		swapped = 0;
		lPtr = Head;
		while (lPtr->Next != NULL)
		{
			if (lPtr->getData() > lPtr->Next->getData())
			{
				my_swap(lPtr, lPtr->Next);
				swapped = 1;
			}
			lPtr = lPtr->Next;
		}


	} while (swapped);
	return *this;
}





Node* LinkedList::Search(int data)
{
	Node* current = Head;
	int _Data = 0;
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
LinkedList LinkedList::BubbleSort2()
{
	int Max = 1, IndexCurrent = 0, loopsParent = 0, IndexNext = 0, EndLoop = 0, loopsChild = 0;
	
	Node* current = Head;
	Node* currentNow = Head;
	while (EndLoop == 0)
	{
		IndexCurrent = 0;
		current = Head;
		EndLoop = 1;
		while (current->Next != NULL)
		{
			
			IndexCurrent = current->getData();
			IndexNext = current->Next->getData();

			if (IndexNext < IndexCurrent)
			{
				EndLoop = 0;
				my_swapByNodeOnly(current, current->Next);
				loopsChild++;
			}
			else
			{
				current = current->Next;
			}
		}
		loopsParent++;
	}
	cout << "loopsChild : " << loopsChild << endl;
	cout << "loopsParent : " << loopsParent << endl;
	return *this;
}

//LinkedList LinkedList::BubbleSort2()
//{
//	int Max = 1, IndexCurrent = 0, loopsParent = 0, IndexNext = 0, EndLoop = 0;
//	Node* current = Head;
//	for (int i = 0; i < 3; i++)
//	{
//		EndLoop = 1;
//
//		while (current != NULL && current->Next != NULL)
//		{
//			IndexCurrent = current->getData();
//			IndexNext = current->Next->getData();
//
//			if (IndexNext < IndexCurrent)
//			{
//				EndLoop += 1;
//				if (current->Prev == NULL)
//				{
//					Node* ndcurrent = current;
//					Node* ndcurrentNext = current->Next;
//					Node* ndcurrentNextNext = current->Next->Next;
//
//					current = ndcurrentNext;
//					Head = current;
//					current->Next = ndcurrent;
//					current->Next->Prev = current;
//					current->Next->Next = ndcurrentNextNext;
//					ndcurrentNextNext->Prev = ndcurrent;
//					current->Prev = NULL;
//					cout << "";
//				}
//				else
//				{
//					Node* ndcurrent = current;
//					Node* ndcurrentNext = current->Next;
//					Node* ndcurrentNextNext = current->Next->Next;
//
//					current = ndcurrentNext;
//					current->Next = ndcurrent;
//
//					if (ndcurrentNext->Next != NULL)
//						ndcurrentNext->Next = ndcurrentNextNext;
//
//
//
//					cout << "";
//				}
//			}
//
//
//
//			current = current->Next;
//		}
//		current = Head;
//	}
//}