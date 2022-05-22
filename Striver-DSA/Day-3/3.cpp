#include <bits/stdc++.h> 
using namespace std;

int findMajorityElement(int arr[], int n) {
	unordered_map<int,int> m;
	for(int i=0; i<n; i++)
	{
		m[arr[i]]++;
	}
	for(auto it=m.begin(); it!=m.end(); it++)
	{
		if(it->second>n/2)
		{
			return it->first;
		}
	}
	return -1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<findMajorityElement(arr,n)<<endl;
}