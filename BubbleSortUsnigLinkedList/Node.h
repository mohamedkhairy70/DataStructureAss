#pragma once
class Node
{
private:
	int Data;
public:
	Node* Prev, * Next;
	Node(int data);
	int getData();
	void SetData(int datea);
};

