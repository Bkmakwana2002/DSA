#include <bits/stdc++.h>
using namespace std;

int print_all_ways(int n)
{
    if(n<0)
    {
       return 0;
    } 
    if(n == 0 || n==1)
    {
        return 1;
    }
    return (print_all_ways(n-1)+print_all_ways(n-2)+print_all_ways(n-3));
}

int main()
{
    int n;
    cin>>n;
    cout<<print_all_ways(n);
    return 0;
}