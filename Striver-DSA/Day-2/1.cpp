#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }

int main()
{
    vector<vector<int>> v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        vector<int> row;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            row.push_back(x);
        }
        v.push_back(row);
    }
  rotate(v);
  for(int i=0; i<n; i++)
  {
      for(int j=0; j<n; j++)
      {
          cout<<v[i][j]<<" ";
      }
      cout<<endl;
  }
}