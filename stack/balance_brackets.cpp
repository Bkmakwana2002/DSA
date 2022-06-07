#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            char val = st.top();
            st.pop();
            if ((val == '(' && s[i] == ')') || (val == '{' && s[i] == '}') || (val == '[' && s[i] == ']'))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    string s = "()";
    cout << isValid(s);
    return 0;
}