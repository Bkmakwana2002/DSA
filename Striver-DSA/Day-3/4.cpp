#include <bits/stdc++.h> 
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> ans;
	int n = arr.size();
	unordered_map<int,int> m;
	for(int i=0; i<n; i++)
	{
		m[arr[i]]++;
	}
	for(auto it=m.begin(); it!=m.end(); it++)
	{
		if(it->second>n/3)
		{
			ans.push_back(it->first);
		}
	}
	return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int> ans = majorityElementII(arr);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}