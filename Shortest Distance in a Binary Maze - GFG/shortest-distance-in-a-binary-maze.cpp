//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size() , m = grid[0].size();
        int drow[] = {0,0,-1,1} , dcol[] = {1,-1,0,0};
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,source});
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        
        dist[source.first][source.second] = 0;
        
        while(!q.empty()){
            int wt = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            
            if(destination == q.front().second) return wt;
            q.pop();
            
            for(int a=0;a<4;a++){
                int nr = i+drow[a];
                int nc = j+dcol[a];
                if( nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && (wt +1) < dist[nr][nc] && grid[nr][nc]==1 ){
                    dist[nr][nc] = wt+1;
                    q.push({wt+1,{nr,nc}});
                }
            }
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends