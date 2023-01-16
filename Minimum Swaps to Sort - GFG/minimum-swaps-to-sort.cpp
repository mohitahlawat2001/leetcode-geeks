//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int dfs(vector<pair<int,int>> &arr, int i ,  vector<bool> &vis){
	    int res =0;
	    int j = i;
	    while(!vis[j]){
	        vis[j]=true;
	        j = arr[j].second;
	        res++;
	    }
	    return res-1;
	}
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>> arr(nums.size());
	    for(int i = 0 ; i<nums.size();i++){
	        arr[i] = make_pair(nums[i],i);
	    }
	    sort(arr.begin(),arr.end());
	    vector<bool> vis(nums.size(),false);
	    int res = 0;
	    for(int i = 0;i<nums.size();i++){
	        if(vis[i]==false){
	            res += dfs(arr,i,vis);
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends