#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int b[n];
        for(int i=0;i<n; i++)
        {
          cin>>b[i];
        }
        for(int i=0; i<n-1; i++)
        {
          if(b[i]%b[i+1] != 0)
          {
            cout<<-1;
            break;
          }
          else
          {
              for(int i=0; i<n; i++)
              {
                  cout<<b[i]<<" ";
              }
          }
        }
        cout<<endl;
    }
    return 0;
}
