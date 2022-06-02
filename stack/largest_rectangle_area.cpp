#include <bits/stdc++.h>
using namespace std;

int histogram(vector<int> &heights)
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

int largestRectangleArea(vector<vector<int>> matrix)
{
    vector<int> currArr = matrix[0];
    int maxArea = histogram(currArr);
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 1)
            {
                currArr[j] = currArr[j] + 1;
            }
            else
            {
                currArr[j] = 0;
            }
        }
        int area = histogram(currArr);
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    vector<vector<int>> v;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<m; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    cout<<largestRectangleArea(v);
    return 0;
}