#pragma once
class Queue
{
    int* arr;
    int maxSize;
    int size, front, rear;

public:
    Queue(int size);
    void EnQueue(int data);
    int DeQueue(int& data);
    void ClearQueue();
    int QueueEmpty();
    int QueueFull();
    int QueueSize();
private:
    void Shift();
};

