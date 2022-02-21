// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool find3Numbers(int A[], int n, int X)
    {
        unordered_map<int,int> m;
        for(int i=0; i<n; i++)
        {
           int num = X-A[i];
           for(int j=i+1; j<n; j++)
           {
               if(m[num-A[j]])
               {
                   return true;
               }
               m[A[i]]++;
           }
        }
        return false;
    }

};


int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}