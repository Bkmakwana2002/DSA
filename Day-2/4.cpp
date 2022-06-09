#include <bits/stdc++.h> 
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	unordered_map<int,int> m;
	for(int i=0; i<n; i++)
	{
		m[arr[i]]++;
	}
	for(auto it = m.begin(); it!=m.end(); it++)
	{
		if(it->second>1)
		{
			return it->first;
		}
	}
	return -1;
}

int main()
{
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<findDuplicate(arr,n);
}
