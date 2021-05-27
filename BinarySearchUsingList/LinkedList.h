#pragma once
#include "Node.h"
class LinkedList
{
private:
	Node* Root;
	int Index;
	Node* Search(int data);
public:
	LinkedList();
	void Add(int data);
	int GetLenth();
};

