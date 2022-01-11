#include <bits/stdc++.h>
using namespace std;

void ans(vector<int> input, vector<int> output,int index)
{
    if(index>=input.size())
    {
        for(auto it:output)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return ;
    }
    //excluding input[index]
    ans(input,output,index+1);
    
    //including input[index]
    output.push_back(input[index]);
    ans(input,output,index+1);
}

int main()
{
    vector<int> input;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        input.push_back(x);
    }
    vector<int> output;
    int index = 0;
    ans(input,output,index);
    return 0;
}