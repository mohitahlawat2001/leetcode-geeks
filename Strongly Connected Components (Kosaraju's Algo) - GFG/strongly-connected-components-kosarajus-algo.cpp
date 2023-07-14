//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,adj,vis,st);
	        }
	    }
	            st.push(node);
	}
	void df(int node, vector<int> adj[], vector<bool> &vis, vector<int> &temp){
	    vis[node]=1;
	   // cout<<node<<" ";
	    temp.push_back(node);
	    for(int it:adj[node]){
	        if(!vis[it]){
	            df(it,adj,vis,temp);
	        }
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<bool> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        vector<int> graph[V];
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                graph[it].push_back(i);
            }
        }
        
        vector<bool> visited(V,0);
        vector<vector<int>> ans;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            // visited[node]=1;
    	    
    	        if(!visited[node]){
    	            vector<int> temp;
    	            df(node,graph,visited,temp);
    	           // for(auto it:temp) cout<<it<<" ";
    	           // cout<<endl;
    	            ans.push_back(temp);
    	        }
    	    
        }
        
        return ans.size();
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends