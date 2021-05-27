// BubbleSortUsnigLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
using namespace std;



int main()
{
    LinkedList linkedList;
    
    linkedList.Add(8);
    linkedList.Add(3);
    linkedList.Add(5);
    linkedList.Add(2);
    linkedList.Add(11);

    //linkedList.my_swapByNodeOnly(linkedList.Tail->Prev, linkedList.Tail);

    linkedList.BubbleSort2();
    linkedList.Display();
    cout << "Hello World!\n";
}

