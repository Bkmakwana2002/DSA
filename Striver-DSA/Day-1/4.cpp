#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(long long arr[], long long  n)
{
    long long msf = INT_MIN;
	long long mef = 0;
	for(long long i=0; i<n; i++)
	{
		mef = mef + arr[i];
		if(mef <arr[i])
		{ 
			mef = arr[i];
		}
		if(msf<mef)
		{
			msf = mef;
		}
	}
	return msf;
}

int main()
{
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout<<maxSubarraySum(arr, n);
    return 0;
}