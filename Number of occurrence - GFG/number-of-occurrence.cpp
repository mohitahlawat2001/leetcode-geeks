//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		int first(int nums[],int n, int t){
        int l=0, r= n-1;
        int ans =-1;
        while(r>=l){
            int m = l + (r-l)/2;
            if(nums[m]==t){
                ans = m;
                r = m-1;
            } else if(nums[m]>t){
                r=m-1;
            } else{
                l=m+1;
            }
        }
        return ans;
    }
     int last(int nums[],int n, int t){
        int l=0, r= n-1;
        int ans =-1;
        while(r>=l){
            int m = l + (r-l)/2;
            if(nums[m]==t){
                ans = m;
                l = m+1;
            } else if(nums[m]>t){
                r=m-1;
            } else{
                l=m+1;
            }
        }
        return ans;
    }
	int count(int arr[], int n, int x) {
	    // code here
	    int firs =first(arr,n,x);
	    int las = last(arr,n,x);
	    if(firs == -1) return 0;
	    return las - firs +1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends