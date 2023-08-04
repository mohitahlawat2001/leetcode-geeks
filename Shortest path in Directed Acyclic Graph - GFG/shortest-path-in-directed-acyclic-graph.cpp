//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int i, vector<pair<int,int>> adj[],stack<int> &st,vector<bool> &vis){
        vis[i]=true;
        for(auto it:adj[i]){
            if(!vis[it.first]){
                dfs(it.first,adj,st,vis);
            }
        }
        st.push(i);
    }  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        stack<int>  st;
        vector<bool> vis(N,0);
        
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,adj,st,vis);
            }
        }
        
        vector<int> dist(N,1e8);
        dist[0]=0;
        while(!st.empty()){
            int v = st.top();
            st.pop();
            for(auto i:adj[v]){
                int node = i.first;
                int wt = i.second;
                if(dist[v] + wt < dist[node]){
                    dist[node] = dist[v]+wt;
                }
            }
        }
        
        for(int &i:dist){
            if(i==1e8) i=-1;
        }
        
        return dist;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends