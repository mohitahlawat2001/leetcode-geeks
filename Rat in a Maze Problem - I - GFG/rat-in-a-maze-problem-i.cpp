//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void f(int r, int c,vector<vector<int>> &vis , vector<vector<int>> &m, string temp, vector<string> &ans ){
        int n = m.size();
        if(r==n-1 && c==n-1) {
            ans.push_back(temp);
            return;
        }
        
        if(r+1<n && !vis[r+1][c] && m[r+1][c]==1){
            vis[r][c]=1;
            f(r+1,c,vis,m,temp+'D',ans);
            vis[r][c]=0;
        }
        
        if(c-1>=0 && !vis[r][c-1] && m[r][c-1]==1){
            vis[r][c]=1;
            f(r,c-1,vis,m,temp+'L',ans);
            vis[r][c]=0;
        }
        
        if(c+1<n && !vis[r][c+1] && m[r][c+1]==1){
            vis[r][c]=1;
            f(r,c+1,vis,m,temp+'R',ans);
            vis[r][c]=0;
        }
        
        if(r-1>=0 && !vis[r-1][c] && m[r-1][c]==1){
            vis[r][c]=1;
            f(r-1,c,vis,m,temp+'U',ans);
            vis[r][c]=0;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0]==1) 
            f(0,0,vis,m,"",ans);
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends