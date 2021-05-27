#include "Node.h"
#include <cstddef>
using namespace std;
#include <string>
Node::Node(int date, string _Name)
{
	Data = date;
	Name = _Name;
	Prev = Next = NULL;
}

int Node::getData()
{
	return Data;
}

string Node::getName()
{
	return Name;
}

void Node::SetData(int data)
{
	Data = data;
}
