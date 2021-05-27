#pragma once
class Node
{
private:
	int Data;
public:
	Node* Left,* Right;
	Node(int data);
	int getData();
	void setData(int data);
};

