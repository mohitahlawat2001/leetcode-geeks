//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int lcs(string &str, int i, int j, vector<vector<int>> &dp){
	        if(i<0 || j<0) return 0;
	        
	        if(dp[i][j] != -1) return dp[i][j];
	        
	        if(i!=j && str[i]==str[j]){
	            return dp[i][j] = 1+ lcs(str,i-1,j-1,dp);
	        }
	        
	        return dp[i][j] = max(lcs(str,i,j-1,dp) , lcs(str,i-1,j,dp));
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    vector<vector<int>> dp(n,vector<int>(n,-1));
		    
		    return lcs(str,n-1,n-1,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends