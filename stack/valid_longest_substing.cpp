#include <bits/stdc++.h>
using namespace std;

int validSubsting(string s)
{
    stack<int> st;
    int n = s.length();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            if (!st.empty() && s[i] == ')' && s[st.top()] == '(')
            {
                st.pop();
                int x;
                if (!st.empty())
                {
                    x = st.top();
                }
                else
                {
                    x = -1;
                }
                count = max(count, i - x);
            }
            else
            {
                st.push(i);
            }
        }
    }
    return count;
}

int main()
{
    string s = "()()((";
    cout<<validSubsting(s);
    return 0;
}