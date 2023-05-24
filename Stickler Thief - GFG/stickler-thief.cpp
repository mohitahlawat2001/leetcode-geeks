//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int helper(int arr[], int idx,vector<int> &dp){
        if(idx ==0 ) return arr[idx];
        if(dp[idx]!=-1) return dp[idx];
        int pick = arr[idx] + helper(arr,idx-2,dp);
        int notpick = helper(arr,idx-1,dp);
        return dp[idx]=max(pick,notpick);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n,-1);
        return helper(arr,n-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends