#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num1;
    cin>>num1;
    int num2;
    cin>>num2;
    int ansMaks = num1^num2;
    int count = 0;
    while(ansMaks>0)
    {
        ansMaks = ansMaks &(ansMaks-1);
        count++;
    }
    cout<<count;
    return 0;
}