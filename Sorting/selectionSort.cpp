#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int minIndex = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[minIndex]>arr[j])
            minIndex = j;
        }
        if(minIndex!=i)
        {
            swap(arr[minIndex],arr[i]);
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
    selectionSort(arr,n);
    return 0;
}