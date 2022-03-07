#include <bits/stdc++.h>
using namespace std;

struct interval
{
    int start;
    int end;
};

bool compareInterval(interval i1, interval i2)
{
    return (i1.start < i2.start);
}

void mergeInterval(interval arr[], int n)
{
    stack<interval> s;
    sort(arr, arr + n,compareInterval);
    s.push(arr[0]);
    for(int i=1; i<n; i++)
    {
        interval top = s.top();
        if(top.end < arr[i].start)
        {
            s.push(arr[i]);
        }
        else if(top.end < arr[i].end)
        {
           top.end = arr[i].end;
           s.pop();
           s.push(arr[i]);
        }
    }
    while (!s.empty())
    {
        interval t = s.top();
        cout << "[" << t.start << "," << t.end << "] ";
        s.pop();
    }
    return;
}

int main()
{
    interval arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    int n = 4;
    mergeInterval(arr, n);
    return 0;
}