//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    
    bool isMin(int nums[],int m,int n){
        int lval = (m -1)<0 ? INT_MAX:nums[m-1];
        int rval = (m+1)>=n? INT_MAX:nums[m+1];
        if(nums[m]<lval && nums[m]<rval) return true;
        return false;
    }
    bool isMax(int nums[],int m,int n){
        int lval = (m -1)<0 ? INT_MIN:nums[m-1];
        int rval = (m+1)>=n? INT_MIN:nums[m+1];
        if(nums[m]>lval && nums[m]>rval) return true;
        return false;
    }

   
	int findKRotation(int nums[], int n) {
	    // code here
	     int l =0, r=n-1;
        if(nums[0]<=nums[r]) return 0;
        while(r>=l){
            int m = l + (r-l)/2;
            if(isMax(nums,m,n)){
                return m+1;
            }
            else if(isMin(nums,m,n)){
                return m;
            } 
            else if(nums[l]<nums[m]){
                l = m+1;
            }else if(nums[r]>nums[m]){
                r=m-1;
            }
        }
        return 0;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends