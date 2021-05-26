#pragma once
class Node
{
private:
	int Data;
public:
	Node* Prev;
	Node(int data);
	int GetData();
};

