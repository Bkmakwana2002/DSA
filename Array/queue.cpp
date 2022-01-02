#include <bits/stdc++.h>
using namespace std;

class Queue {
  private : 
    int front;
    int rear;
    int arr[5];
  public : 
    Queue()
     {
         front = -1;
         rear = -1;
         memset(arr,0,5);
     }
    bool isEmpty()
    {
        if(front == -1 && rear == -1)
        {
            return true;
        }
        else
        return false;
    }
    bool isFull()
    {
        if(rear == size(arr)-1)
        {
            return true
        }
        else
        return false;
    }
    void enqueue(int data)
    {
        if(isFull())
        {
            cout<<"QUEUE is FULL";
            return ;
        }
        else if(isEmpty())
        {
            rear = 0;
            front = 0;
            arr[rear] = data;
        }
        else {
            rear ++;
            arr[rear] = data;
        }
    }
};

int main()
{
    return 0;
}