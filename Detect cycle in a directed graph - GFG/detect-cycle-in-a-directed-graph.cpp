//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCycle(int i, vector<int> adj[] , vector<bool> &vis, vector<bool> &pathVis){
        vis[i]=true;
        pathVis[i] = true;
        
        for(auto it:adj[i]){
            if(!vis[it]){
                if(isCycle(it,adj,vis,pathVis) == true) return true;
            } else if(pathVis[it]){
                return true;
            }
        }
        pathVis[i] = false;
        
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,0) , pathVis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycle(i,adj,vis,pathVis) == true) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends