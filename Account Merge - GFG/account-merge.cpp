//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        map<string,int> mp;
        DisjointSet ds(accounts.size());
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if( mp.find(accounts[i][j]) == mp.end())
                    mp[accounts[i][j]]=i;
                else
                    ds.unionByRank(i, mp[accounts[i][j]]);
            }
        }
        
        map<int,vector<string>> m;
        for(auto it: mp){
            int i = ds.finduPar(it.second);
            // cout<<it.second<<" "<<i<<endl;
            m[i].push_back(it.first);
        }
        
        for(auto it:m){
            sort(it.second.begin(), it.second.end());
        }
        
        vector<vector<string>> ans;
        for(auto it:m){
            vector<string> a;
            a.push_back(accounts[it.first][0]);
            
            for(auto i:it.second){
                a.push_back(i);
            }
            
            ans.push_back(a);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends