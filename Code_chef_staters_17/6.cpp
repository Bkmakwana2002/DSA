#include <bits/stdc++.h>
using namespace std;

vector<int> seive(int arr[], int n)
{
    vector<int> v;
    bool hash[n + 1];
    memset(hash, true, sizeof(hash));
    hash[1] = false;
    hash[0] = false;
    for (int i = 2; i <= n; i++)
    {
        if (hash[i] == true)
        {
            for (int j = 2 * i; j <= n; j = j + i)
            {
                hash[j] = false;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (hash[i] == true)
        {
            v.push_back(i);
        }
    }
    return v;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int k;
        cin >> n;
        cin >> k;
        int arr[n + 1];
        for (int i = 0; i <= n; i++)
        {
            arr[i] = i;
        }
        vector<int> v1;
        vector<int> v2;
        for (int i = 0; i < seive(arr, n).size(); i++)
        {
            if (seive(arr, n)[i] * 2 <= n)
            {
                int x = seive(arr, n)[i];
                v1.push_back(x);
            }
            else
            {
                int x = seive(arr, n)[i];
                v2.push_back(x);
            }
        }
        v2.push_back(1);
        for (int i = 0; i < n + 1; i++)
        {
            if ((find(v1.begin(), v1.end(), arr[i]) == v1.end()) && ((find(v2.begin(), v2.end(), arr[i]) == v2.end())) && arr[i] != 0)
            {
                v1.push_back(arr[i]);
            }
        }
        if (k == v1.size())
        {
            cout<<"YES"<<endl;
            for (int i = 0; i < v1.size(); i++)
            {
                cout << v1[i] << " ";
            }
        }
        else if (k == v2.size())
        {
            cout<<"YES"<<endl;
            for (int i = 0; i < v2.size(); i++)
            {
                cout << v2[i] << " ";
            }
        }
        else if (k > v1.size())
        {
            int c = k - v1.size();
            for (int i = 0; i < c; i++)
            {
                int x = v2[i];
                v1.push_back(x);
            }
            cout<<"YES"<<endl;
            for (int i = 0; i < v1.size(); i++)
            {
                cout << v1[i] << " ";
            }
        }
        else if (k < v2.size())
        {
            int c = v2.size() - k;
            cout<<"YES"<<endl;
            for (int i = 0; i < v2.size()-c; i++)
            {
                cout << v2[i] << " ";
            }
        }
        else
        {
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}