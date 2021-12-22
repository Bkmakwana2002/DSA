#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int Arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (Arr[i]>Arr[i-1])
        {
            profit = profit + (Arr[i]-Arr[i-1]);
        }
    }
    cout<<profit;
}