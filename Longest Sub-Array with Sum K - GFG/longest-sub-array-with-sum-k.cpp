//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<long long , int> map;
        long long sum=0;
        int ans=0;
        for(int i=0;i<N;i++){
            sum += A[i];
            if(sum==K){
                ans = max(ans,i+1);
            }
            int rem = sum-K;
            if(map.count(rem)){
                ans = max(ans,i-map[rem]);
            }
            if(map.count(sum)==0){
                map[sum]=i;
            }
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends