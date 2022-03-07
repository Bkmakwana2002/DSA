#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    int temp;
    for(int i=1; i<n; i++)
    {
        temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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
    insertionSort(arr,n);
    return 0;
}