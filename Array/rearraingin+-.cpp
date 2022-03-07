// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:

	void rearrange(int arr[], int n) {
     vector<int> v1;
     vector<int> v2;
     vector<int> v;
     for(int i=0; i<n; i++)
	 {
	     if(arr[i]>=0)
	     {
	         v1.push_back(arr[i]);
	     }
	 }
	 for(int i=0; i<n; i++)
	 {
	     if(arr[i]<0)
	     {
	         v2.push_back(arr[i]);
	     }
	 }
	 int x = v1.size();
	 int y = v2.size();
	 int p =0;
	 int q = 0;
	 for(int i=0; i<n; i++)
	 {
	    if(i%2 == 0 && x>0)
	    {
	       v.push_back(v1[p]);
	       p++;
	       x--;
	    }
	    else if(i%2!=0 && y>0)
	    {
	        v.push_back(v2[q]);
	        q++;
	        y--;
	    }
	 }
	 for(int i=0; i<n; i++)
	 {
	     arr[i] = v[i];
	 }
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}