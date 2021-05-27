#pragma once
using namespace std;
#include <string>
class Node
{
private:
	int Data;
	string Name;
public:
	Node* Prev, * Next;
	Node(int data,string _Name);
	int getData();
	string getName();
	void SetData(int datea);
};

