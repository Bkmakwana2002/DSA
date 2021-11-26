#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int v;
        cin>>v;
        int cost_max = 0;
        for(int i=1; i<=n-1; i++)
        {
            cost_max = cost_max + i;
        }
        int cost_min = 0;
        if(v == 1)
        {
            cost_min = cost_max;
        }
        else
        {
            if(v == n-1)
            {
                cost_min = 1*(n-1);
            }
            // else
            // {
            //     int i = 1;
            //     while(v>0 && i <= n-1)
            //     {
            //         cost_min = i*v + cost_min;
            //         i++;
            //         v--;
            //     }
            // }
            else
            {
                cost_min = v + ((n-v) * (n-v+1))/2 -1;
            }
        }
        cout<<cost_max<<" "<<cost_min<<endl;
    } 
    return 0;
}