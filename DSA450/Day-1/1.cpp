#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0; i<n; i++)
   {
       cin>>a[i];
   }
   int left = 0;
   int right = n-1;
   int result[n];
   int index = n-1;
   while(left<=right && index>=0)
   {
       if(abs(a[left]) >= abs(a[right]))
       {
           result[index] = a[left]*a[left];
           left++;
       }
       else{
            result[index] = a[right]*a[right];
            right--;
       }
       index --;
   }
   for(int i=0; i<n; i++)
   {
       cout<<result[i]<<" ";
   }
   return 0;
}
