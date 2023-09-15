//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool f(int ind, int arr[], int sum, vector<vector<int>> &dp){
        if(ind<0) {
            if(sum==0) return 1;
            return 0;
        } 
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        int notTake = f(ind-1,arr, sum,dp);
        int take =0;
        if(arr[ind]<=sum) take = f(ind-1,arr,sum-arr[ind],dp);
        
        return dp[ind][sum] = take||notTake;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        
        if(sum%2 != 0) return 0;
        
        vector<vector<int>> dp(N,vector<int>(sum/2 +1 , -1));
        
        return f(N-1,arr,sum/2,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends