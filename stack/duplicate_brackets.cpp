#include <bits/stdc++.h>
using namespace std;

bool checkDuplicateBrackets(string s)
{
    int n = s.length();
    stack<char> st;
    for(int i=0; i<n; i++)
    {
        if(s[i] == ')')
        {
           if(st.top() == '(')
           {
               return true;
           }
           else{
               while(st.top()!='(' && !st.empty())
               {
                     st.pop();
               }
           }
        }
        else{
            st.push(s[i]);
        }
    }
    return false;
}

int main()
{
    string s = "(a+b)*(c+d)";
    cout<<checkDuplicateBrackets(s);
    return 0;
}