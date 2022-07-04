#include <bits/stdc++.h>
using namespace std;

bool check(string &x, string &y)
{
    if (x.size() - y.size() == 1)
    {
        int first = 0;
        int second = 0;
        while (first < x.size())
        {
            if (x[first] == y[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
        if (first == x.size() && second == y.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

int f(int index, int prevIndex, int n, vector<string> &a, vector<vector<int>> &dp)
{
    if (index == n)
    {
        return 0;
    }
    if (dp[index][prevIndex + 1] != -1)
    {
        return dp[index][prevIndex + 1];
    }
    int len;
    len = f(index + 1, prevIndex, n, a, dp);
    if (prevIndex == -1 || check(a[index], a[prevIndex]))
    {
        len = max(len, f(index + 1, index, n, a, dp) + 1);
    }
    return dp[index][prevIndex + 1] = len;
}

static bool comp(string &x, string &y)
{
    return x.size() < y.size();
}

int longestStrChain(vector<string> &words)
{
    int n = words.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    sort(words.begin(), words.end(), comp);
    return f(0, -1, n, words, dp);
}

int main()
{
    vector<string> words;
    int n;
    cin>>n;
    while(n--)
    {
        string x;
        cin>>x;
        words.push_back(x);
    }
    cout<<longestStrChain(words);
    return 0;
}