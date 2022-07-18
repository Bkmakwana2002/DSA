//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  
 bool isValid(int i, int j, int n, int m, vector<vector<int>> &image, int og)
    {
        if(i>=0 && i<n && j>=0 && j<m && image[i][j] == og)
        {
            return true;
        }
        return false;
    }
    
    
    void dfs(vector<vector<int>>& image, int i, int j, int color, int n, int m, int og)
    {
        image[i][j] = color;
        if(isValid(i+1,j,n,m,image,og))
        {
           dfs(image,i+1,j,color,n,m,og);
        }
        
        if(isValid(i,j+1,n,m,image,og))
        {
            dfs(image,i,j+1,color,n,m,og);
        }
        
        if(isValid(i-1,j,n,m,image,og))
        {
            dfs(image,i-1,j,color,n,m,og);
        }
        
        if(isValid(i,j-1,n,m,image,og))
        {
            dfs(image,i,j-1,color,n,m,og);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int color) {
        int n = image.size();
        int m = image[0].size();
        
        int og = image[i][j];
        
        if(og == color)
        {
            return image;        
        }
        
       dfs(image,i,j,color,n,m,og);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends