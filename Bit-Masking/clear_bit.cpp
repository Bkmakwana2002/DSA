#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    cin>>i;
    int num;
    cin>>num;
    int mask = 1<<i;
    cout<<(num&~(mask));
    return 0;
}