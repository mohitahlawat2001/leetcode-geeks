//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long f(int n , int k, int target, vector<vector<long long>> &dp){
        if(target<0) return 0;
        if(n==0 && target!=0) return 0;
        if(target==0 && n!=0) return 0;
        if(n==0 && target==0) return 1;
        if(dp[n][target]!=-1) return dp[n][target];
        long long ans=0;
        for(int i=1;i<=k;i++){
            ans = ans+ f(n-1,k,target-i,dp);
        }
        return dp[n][target] = ans;
    }
    long long noOfWays(int M , int N , int X) {
        // code here
        vector<vector<long long>> dp(N+1,vector<long long>(X+1,-1));
        return f(N,M,X,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends