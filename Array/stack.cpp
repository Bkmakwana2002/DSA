#include <bits/stdc++.h>
using namespace std;

class Stack{
  private : 
     int top;
     int arr[5];
    
    public : 
     Stack () 
     {
         top = -1;
         memset(arr,0,5);
     }

     bool isEmpty()
     {
         if(top == -1)
         {
             return true;
         }
         else return false;
     }

     bool isFull()
     {
         if(top == 4)
         {return true;}
         else
         return false;
     }
    
    void push(int data)
    {
        if(isFull())
        { 
            cout<<"STACK IS FULL";
        }
        else
        {
            top ++;
            arr[top] = data;
        }
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"STACK IS EMPTY";
            return 0;
        }
        else{
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }

    int count()
    {
        return (top+1);
    }

    int peek(int pos)
    {
        if(isEmpty())
        {
            cout<<"STACK IS EMPTY";
        }
        else
         return arr[pos];
    }

    void change(int pos, int data)
    {
        arr[pos] = data;
        cout<<"ITEM CHANGED AT THE POSITION :"<<pos;
    }

    void display()
    {
        for(int i=4; i>=0; i--)
        {
            cout<<arr[i]<<endl;
        }
    }
};

int main()
{
    Stack s1;
    int option,pos,data;
    do
    {
        cin>>option;
        switch (option)
        {
        case 1 : cin>>data;
                 s1.push(data);
            break;
        case 2 : s1.pop();
            break;
        case 3 : s1.display();
        default:
            break;
        }
    } while (option!=0);
    
    return 0;
}