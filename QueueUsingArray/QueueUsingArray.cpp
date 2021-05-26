// QueueUsingArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Queue.h"
using namespace std;

bool PrintDeQueue(Queue& que)
{
    int data;
    if(que.DeQueue(data))
    {
        cout << data << "\t"; return false;
    }
    return true;
}
int main()
{

    Queue que(100);
    que.EnQueue(3);
    que.EnQueue(5);
    que.EnQueue(7);
    int data;

    PrintDeQueue(que);
    PrintDeQueue(que);

    cout << endl;
    que.EnQueue(30);
    que.EnQueue(50);
    que.EnQueue(70);
    que.EnQueue(70);

    cout << endl;
    PrintDeQueue(que);
    PrintDeQueue(que);

    cout << endl;
    que.EnQueue(300);
    que.EnQueue(500);
    que.EnQueue(700);
    que.EnQueue(700);
    que.EnQueue(30);
    que.EnQueue(50);
    que.EnQueue(70);
    que.EnQueue(70);
    cout << endl;
    while (!PrintDeQueue(que))
    {

    }

}
