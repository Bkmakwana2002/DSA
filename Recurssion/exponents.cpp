#include <bits/stdc++.h>
using namespace std;

int print(int n, int num)
{
    if(n==0)
    {
        return 1;
    }
    return (num*print(n-1,num));
}

int chotta_method(int n,int num)
{
    if(n == 0)
    {
        return 1;
    }
    int chota_ans = chotta_method(n/2,num);
    if(n%2 == 0)
    {
        return (chota_ans * chota_ans);
    }
    else
        return num*chota_ans*chota_ans;
}

int main()
{
    int n;
    cin>>n;
    int num;
    cin>>num;
    cout<<print(n,num)<<endl;
    cout<<chotta_method(n,num);
    return 0;
}