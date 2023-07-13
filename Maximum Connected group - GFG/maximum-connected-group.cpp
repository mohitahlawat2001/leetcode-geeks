//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   class DisjointSet{
        public:
        vector<int> parent, rank, size;
            DisjointSet(int n){
                parent.resize(n+1);
                rank.resize(n+1,0);
                size.resize(n+1,1);
                for(int i=0;i<=n;i++){
                    parent[i]=i;
                }
            }

            int finduPar(int node){
                if(parent[node]==node) return node;
                return parent[node]= finduPar(parent[node]);
            }

            void unionByRank(int u, int v){
                 u = finduPar(u);
                 v = finduPar(v);
                if( u==v) return;
                if(rank[u]<rank[v]){
                    parent[u]=v;
                }else if(rank[u]>rank[v]){
                    parent[v]=u;
                }else{
                    parent[v]=u;
                    rank[v]++;
                }
            }
            void unionBySize(int u, int v){
                u = finduPar(u);
                v = finduPar(v);
                if(u==v) return;
                if(size[u]<size[v]){
                    parent[u]=v;
                    size[v]+=size[u];
                }else{
                    parent[v]=u;
                    size[u]+=size[v];
                }
            }
    };
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    continue;
                }
                int dr[] = {-1,1,0,0} , dc[] = {0,0,-1,1};
                for(int d=0;d<4;d++){
                    int nr = i+dr[d] , nc = j + dc[d];
                    if( nr>=0 && nr<n && nc>=0 && nc<n &&grid[nr][nc]==1){
                        int nodeno = i*n+j;
                        int adjno = nr*n+nc;
                        ds.unionBySize(nodeno,adjno);
                    }
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int> s;
                    int dr[] = {-1,1,0,0} , dc[] = {0,0,-1,1};
                    for(int d=0;d<4;d++){
                        int nr = i+dr[d] , nc = j + dc[d];
                        if( nr>=0 && nr<n && nc>=0 && nc<n &&grid[nr][nc]==1){
                        // int nodeno = i*n+j;
                            int adjno = nr*n+nc;
                            s.insert(ds.finduPar(adjno));
                        }
                    }
                        int sum=0;
                        for(auto it:s){
                            sum += ds.size[it];
                        }
                        ans=max(sum+1,ans);
                }
            }
        }
        
        for(int i=0;i<n*n;i++){
            ans = max(ans, ds.size[ds.finduPar(i)] );
        }
        
        return ans;
        
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends