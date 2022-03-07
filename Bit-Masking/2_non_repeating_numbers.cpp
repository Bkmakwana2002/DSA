#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res ^ arr[i];
    }
    int a, b;
    int temp = res;
    cout << res << endl;
    if (res % 2 != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 != 0)
            {
                temp = temp ^ arr[i];
            }
        }
        a = temp;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                res = res ^ arr[i];
            }
        }
        b = res;
        cout << a << " " << b;
    }
    else{
        cout<<"use map";
    }
    return 0;
}