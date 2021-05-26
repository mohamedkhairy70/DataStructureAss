// LinkedListOfQueue-Day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedListAsQueue.h"
using namespace std;

bool PrintDequeue(LinkedListAsQueue & linkedList)
{
    int data;
    if (linkedList.DeQueue(data))
    {
        cout << data << "\t"; return false;
    }
    return true;
}

int main()
{
    LinkedListAsQueue linkedList;

    linkedList.EnQueue(3);
    linkedList.EnQueue(5);
    linkedList.EnQueue(7);
    linkedList.EnQueue(9);
    linkedList.EnQueue(11);
    int data;

    cout << endl;
    PrintDequeue(linkedList);
    PrintDequeue(linkedList);
    PrintDequeue(linkedList);

    cout << endl;

    linkedList.EnQueue(70);
    linkedList.EnQueue(40);
    linkedList.EnQueue(60);

    cout << endl;
    PrintDequeue(linkedList);
    PrintDequeue(linkedList);

    cout << endl;

    linkedList.EnQueue(700);
    linkedList.EnQueue(400);
    linkedList.EnQueue(600);

    cout << endl;
    while (!PrintDequeue(linkedList))
    {
       
    }
}

