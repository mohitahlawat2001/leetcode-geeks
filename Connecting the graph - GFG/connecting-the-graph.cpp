//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
    int Solve(int n, vector<vector<int>>& edges) {
        // code here
        
        int m = edges.size();
        DisjointSet ds(n);
        int cnt=0;
        for(auto it:edges){
            if(ds.finduPar(it[0]) == ds.finduPar(it[1])){
                cnt++;
            }else{
                ds.unionByRank(it[0],it[1]);
            }
        }
        int cop=0;
        for(int i=0;i<n;i++){
            if(ds.finduPar(i)==i) cop++;
        }
        
        int ans = cop-1;
        if(ans>cnt) return -1;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends