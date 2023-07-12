//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   class DisjointSet{
        vector<int> parent, rank;
        public:
            DisjointSet(int n){
                parent.resize(n+1);
                rank.resize(n+1,0);
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
                    rank[u]++;
                }
            }
    };
    
    bool isValid(int i, int j , int n, int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int cnt=0;
        vector<int> ans;
        for(auto &it: operators){
            int r = it[0] , c = it[1];
            
            if(vis[r][c] == 1) {
                ans.push_back(cnt);
                continue;
            }
            
                
            vis[r][c]=1;
            cnt++;
            int dr[] = {0,0,1,-1} , dc[] = {-1,1,0,0};
            for(int i=0;i<4;i++){
                int nr = r+dr[i] , nc = c + dc[i];
                if(isValid(nr,nc,n,m)==true){
                    if(vis[nr][nc]==1){
                        int nodeno = m*r+c;
                        int adjno = nr*m+nc;
                        if(ds.finduPar(nodeno) != ds.finduPar(adjno)){
                            cnt--;
                            ds.unionByRank(nodeno,adjno);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        
            
        }
        
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends