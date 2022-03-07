#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        bool swapped = false;
        for(int j=0; j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swapped = true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(!swapped)
        {
            break;
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = {4,3,1,5,7};
    int n = 5;
    bubbleSort(arr,n);
    return 0;
}