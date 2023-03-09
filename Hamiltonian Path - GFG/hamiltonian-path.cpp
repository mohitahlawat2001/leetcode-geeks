//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool dfs(vector<int> graph[], int s, set<int> &vis, int N){
        vis.insert(s);
        if(vis.size()==N){
            return true;
        }
        
        for(int i: graph[s]){
            if(vis.count(i)==0) 
                if(dfs(graph,i,vis,N))
                    return true;
        }
        vis.erase(s);
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<int> graph[N+1];
        for(vector<int> it:Edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
       set<int> vis;
       for(int i=1;i<=N;i++){
           if(dfs(graph,i,vis,N)) return true;
       }
       return 0;
        // return 0;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends