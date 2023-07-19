//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int f(int i, int j, string &str1,string &str2 , vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(str1[i]==str2[j]){
            return dp[i][j] = 1+ f(i-1,j-1,str1,str2,dp);
        }
        return dp[i][j] = max(f(i-1,j,str1,str2,dp) , f(i,j-1,str1,str2,dp));
    }
    int longestPalinSubseq(string A) {
        //code here
        int n = A.size();
        string a = A;
        reverse(a.begin(),a.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return f(n-1,n-1,a,A,dp);
        
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends