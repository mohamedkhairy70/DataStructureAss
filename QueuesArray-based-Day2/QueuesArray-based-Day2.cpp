// QueuesArray-based-Day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#define MAXQUEUE 100


typedef int KeyType;

typedef struct elementtype {
    int		year;
}ElementType;

typedef ElementType QueueEntry;



typedef struct Queue
{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
    void CreateQueue(Queue* q)
    {
        q->front = 0;
        q->rear = -1;
        q->size = 0;
    }
    void Append(QueueEntry e, Queue* pq) {
        pq->rear = (pq->rear + 1) % MAXQUEUE;
        pq->entry[pq->rear] = e;
        pq->size++;
    }
    void Serve(QueueEntry* pe, Queue* pq) {
        *pe = pq->entry[pq->front];
        pq->front = (pq->front + 1) % MAXQUEUE;
        pq->size--;
    }
    int QueueEmpty(Queue* pq) {
        return !pq->size;
    }

    int QueueFull(Queue* pq) {
        return (pq->size == MAXQUEUE);
    }
    int QueueSize(Queue* pq) {
        return pq->size;
    }
    void ClearQueue(Queue* pq) {
        pq->front = 0;
        pq->rear = -1;
        pq->size = 0;
    }//same as CreateQueue. No nodes to free.
    void TraverseQueue(Queue* pq, void (*pf)(QueueEntry)) {
        int pos, s;
        for (pos = pq->front, s = 0; s < pq->size; s++) {
            (*pf)(pq->entry[pos]);
            pos = (pos + 1) % MAXQUEUE;
        }
    }

}Queue;


int main()
{
    Queue q;
    
    q.CreateQueue(& q);
    
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        count++;
        QueueEntry qentry;
        qentry.year = count *2;
        q.Append(qentry, &q);
    }
   
    
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        count = 0;
        QueueEntry qentry;
        q.Serve(&qentry, &q);
        cout << q.entry->year;
    }
    
    for (int i = 0; i < 5; i++)
    {
        count++;
        QueueEntry qentry;
        qentry.year = count * 2;
        q.Append(qentry, &q);
        
    }


    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        QueueEntry qentry;
        q.Serve(&qentry, &q);
        cout << q.entry->year;
    }

    std::cout << "Hello World!\n";
}
