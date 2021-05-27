#include "Node.h"
#include <cstddef>
Node::Node(int date)
{
	Data = date;
	Prev = Next = NULL;
}

int Node::getData()
{
	return Data;
}

void Node::SetData(int data)
{
	Data = data;
}
