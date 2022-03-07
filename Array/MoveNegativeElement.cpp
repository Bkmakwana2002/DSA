#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
       vector<int>s1;
      vector<int>s2;
      for(int i=0;i<n;i++){
          if(arr[i]>0){
              s1.push_back(arr[i]);
          }
          else{
              s2.push_back(arr[i]);
          }
      }
       
  s1.insert(s1.end(), s2.begin(), s2.end()); // to append two vectors
  for(int i=0;i<n;i++){
      arr[i]=s1.at(i);
  }
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}