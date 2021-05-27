// BubbleSortUsnigLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
using namespace std;



int main()
{
    LinkedList linkedList;
    
    linkedList.Add(8,"Num 8");
    linkedList.Add(3, "Num 3");
    linkedList.Add(5, "Num 5");
    linkedList.Add(2, "Num 2");
    linkedList.Add(11, "Num 11");

    //linkedList.my_swapByNodeOnly(linkedList.Head->Next, linkedList.Head->Next->Next);
    linkedList.Display();
    cout << endl;
    linkedList.BubbleSort2();
    cout << endl;
    linkedList.Display();
    cout << endl;
    cout << "Hello World!\n";
}

