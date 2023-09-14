//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int f(int i,int arr[], int sum , vector<vector<int>> &dp){
	   // if(sum==0) return 1;
	   int mod = 1e9+7;
	    if(i<0) {
	        if(sum==0) return 1;
	        return 0;
	    }
	    if(dp[i][sum]!=-1) return dp[i][sum];
	    
	    int nottake = f(i-1,arr,sum,dp);
	    if(arr[i]<=sum)
	        nottake += f(i-1,arr,sum-arr[i],dp);
	    
	    return dp[i][sum] = nottake%mod;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return f(n-1,arr,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends