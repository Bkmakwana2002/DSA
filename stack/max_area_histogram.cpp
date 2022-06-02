#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    vector<int> ls(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (i < n)
        {
            if (!st.empty())
            {
                ls[i] = st.top() + 1;
            }
        }
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }
    vector<int> rs(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (i < n)
        {
            if (st.empty())
            {
                rs[i] = n - 1;
            }
            else
            {
                rs[i] = st.top() - 1;
            }
        }
        st.push(i);
    }
    int maxArea = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int area = heights[i] * (rs[i] - ls[i] + 1);
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<largestRectangleArea(v);
    return 0;
}