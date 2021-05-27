#include "Node.h"
#include <cstddef>
Node::Node(int date)
{
	Data = date;
	Left = Right = NULL;
}

int Node::getData()
{
	return Data;
}
void Node::setData(int data)
{
	Data = data;
}
