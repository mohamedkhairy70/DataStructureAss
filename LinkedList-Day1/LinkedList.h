#pragma once
#include "Node.h"
class LinkedList
{
private:
	Node* Head, * Tail;
	int Index;
	Node* Search(int data);
public:
	LinkedList();
	void Add(int data);
	void InsertAfter(int LastData, int data);
	void Display();
	void Delete(int data);
	void PrintByIndex(int Index);
	int GetLenth();
};

