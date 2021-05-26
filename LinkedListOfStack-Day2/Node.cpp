#include "Node.h"
#include <cstddef>

Node::Node(int data)
{
	Prev = NULL;
	Data = data;
}

int Node::GetData()
{
	return Data;
}
