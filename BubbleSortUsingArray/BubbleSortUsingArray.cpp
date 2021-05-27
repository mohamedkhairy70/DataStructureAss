// BubbleSortUsingArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void BubbleSort(int* arr, int size)
{
    int EndLoop = 0, loopsChild =0, loopsParent = 0, IndexParent=0;

    while (EndLoop == 0)
    {
        EndLoop = 1;
        for (int IndexChild = IndexParent; IndexChild < size; IndexChild++)
        {
            if (arr[IndexChild] < arr[IndexParent]) {

                swap(arr[IndexParent], arr[IndexChild]);
                EndLoop = 0;
                loopsChild++;

            }
        }
        loopsParent++;
        IndexParent++;
    }

    cout << "loopsChild : " << loopsChild << endl;
    cout << "loopsParent : " << loopsParent << endl;
}


void Display(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
}
int main()
{
    int arr[] = { 5,4,7,3,8,2 };
    
    BubbleSort(arr, 6);
    Display(arr, 6);
    cout << endl;
}
