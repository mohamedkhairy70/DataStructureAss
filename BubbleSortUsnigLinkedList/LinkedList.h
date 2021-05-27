#pragma once
#include "Node.h"
class LinkedList
{
private:
	
	int Index;
	Node* Search(int data);
public:
	Node* Head, * Tail;
	LinkedList();
	LinkedList operator=(LinkedList* linkedList);
	void Add(int data);
	void InsertAfter(int LastData, int data);
	void InsertBefore(int LastData, int data);
	void Display();
	void Delete(int data);
	bool PrintByIndex(int index, int& data);
	LinkedList BubbleSort();
	LinkedList BubbleSort2();
	void my_swap(Node* node_1, Node* node_2);
	void my_swapByNodeOnly(Node* node_1, Node* node_2);
	int GetLenth();
};

