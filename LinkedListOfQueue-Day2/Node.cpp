#include "Node.h"
#include <cstddef>

Node::Node(int data)
{
	Next = NULL;
	Data = data;
}

int Node::GetData()
{
	return Data;
}
