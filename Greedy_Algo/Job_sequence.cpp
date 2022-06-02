#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int deadLine;
    int profit;
};

static bool compareJob(Job j1, Job j2)
{
    return (j1.profit > j2.profit);
}

pair<int, int> maxProfitandCount(Job arr[], int n)
{
    sort(arr, arr + n, compareJob);
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x = max(arr[i].deadLine, x);
    }
    int val[x + 1];
    int count = 0;
    int profit = 0;
    memset(val, -1, sizeof(val));
    for (int i = 0; i < n; i++)
    {
        int j = arr[i].deadLine;
        while (val[j] != -1 && j > 0)
        {
            j--;
        }
        if (j == 0)
        {
            continue;
        }
        val[j] = arr[i].id;
        count++;
        profit = profit + arr[i].profit;
    }
    return {count, profit};
}

int main()
{
    int n;
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id;
        cin >> arr[i].deadLine;
        cin >> arr[i].profit;
    }
    return 0;
}