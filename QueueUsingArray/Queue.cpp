#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int _size)
{
    maxSize = _size;
	arr = new int[_size];

    size = front = 0 ; rear = -1;
}

void Queue::EnQueue(int data)
{
    if (QueueFull())
    {
        cout << "Queue is full";
        return;
    }

    rear = (rear + 1) % maxSize;
    arr[rear] = data;
    size++;
   
}
void Queue::ClearQueue() {
    front = 0;
    rear = -1;
    size = 0;
}//same as CreateQueue. No nodes to free.
int Queue::DeQueue(int& data)
{
    if (QueueEmpty())
    {
        return 0;
    }
    else
    {
       
        data = arr[front];
        front = (front + 1) % maxSize;
        size--;
       
    }
}


int Queue::QueueEmpty() {
    return !size;
}

int Queue::QueueFull() {
    return size == maxSize;
}
int Queue::QueueSize() {
    return size;
}

void Queue::Shift()
{    
    
    for (int i = front; i < rear; i++)
    {
            arr[i] = arr[i+1];
    }    
}
