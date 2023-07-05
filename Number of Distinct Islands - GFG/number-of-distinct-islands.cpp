//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i, int j ,vector<vector<int>>& grid,vector<vector<bool>>& vis, vector<pair<int,int>> &vec ,int ib, int jb ){
        vis[i][j] = 1;
        vec.push_back({i-ib,j-jb});
        
        int drow[] = {0,0,-1,1} , dcol[] = {1,-1,0,0};
        
        for(int k=0;k<4;k++){
            int nr = i +drow[k] , nc = j + dcol[k];
            
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,grid,vis,vec,ib,jb);
            }
        }
        
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size() , m = grid[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vis,vec ,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends