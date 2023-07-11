//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    	class DisjointSet
	{
	    vector<int> rank,parent;
	    public:
	    DisjointSet(int n){
	        rank.resize(n+1,0);
	        parent.resize(n+1,0);
	        for(int i=0;i<=n;i++){
	            parent[i]=i;
	        }
	    }
	    
	    int finduPar(int node ){
	        if(parent[node]==node){
	            return node;
	        }
	        return parent[node] = finduPar(parent[node]);
	    }
	    
	    void unionByRank(int u, int v){
	        int ulp_u = finduPar(u);
	        int ulp_v = finduPar(v);
	        if(ulp_u == ulp_v) return;
	        if(rank[ulp_u] < rank[ulp_v]){
	            parent[ulp_u] = ulp_v;
	        } else if(rank[ulp_u] > rank[ulp_v]){
	            parent[ulp_v] = ulp_u;
	        }else{
	            parent[ulp_v] = ulp_u;
	            rank[ulp_v]++;
	        }
	    }
	    
	};
     
    int numProvinces(vector<vector<int>>& isConnected, int V) {
        int n = isConnected.size();
        // vector<int> adj[n];
        DisjointSet ds(V);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    ds.unionByRank(i,j);
                }
            }
        }

        // vector<bool> vis(n,false);

        int cnt =0;
        for(int i=0;i<V;i++){
            if(ds.finduPar(i)==i){
                // dfs(i,adj,vis);
                cnt++;
            }
        }

        return cnt;
    }
  
    // int numProvinces(vector<vector<int>> adj, int V) {
    //     // code here
    // }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends