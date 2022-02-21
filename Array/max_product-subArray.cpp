// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:

	long long maxProduct(vector<int> arr, int n) {
	   long long int maxP = (long long int)arr[0];
	   long long int minP = (long long int)arr[0];
	   long long int ans = (long long int)arr[0];
	   for(int i=1; i<n; i++)
	   {
	       if(arr[i]<0)
	       {
	           swap(maxP,minP);
	       }
	       maxP = max(maxP*arr[i],(long long int)arr[i]);
	       minP = min(minP*arr[i],(long long int)arr[i]);
	       ans = max(maxP,ans);
	   }
	   return max(maxP,ans);
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
} 