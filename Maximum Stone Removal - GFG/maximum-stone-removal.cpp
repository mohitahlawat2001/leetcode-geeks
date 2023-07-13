//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
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
                    rank[v]++;
                }
            }
    };
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxRow=0 , maxCol=0;
        for(int i=0;i<stones.size();i++){
            maxRow = max(stones[i][0],maxRow);
            maxCol = max(stones[i][1],maxCol);
        }
        
        DisjointSet ds(maxRow+maxCol +1);
        unordered_map<int,int> map;
        for(auto i:stones){
            int rownode = i[0] , colnode = i[1]+maxRow+1;
            ds.unionByRank(rownode,colnode);
            map[rownode]=1;
            map[colnode]=1;
                        
        }
        
        int cnt=0;
        for(auto it:map){
            if(ds.finduPar(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends