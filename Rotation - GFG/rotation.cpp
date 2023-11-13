//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    // code here
	    int l =0, h = n-1,ans=INT_MAX;
	    int index=-1;
        while(h>=l){
            int mid = l+(h-l)/2;

            // slight optimisation 
            if(nums[l]<=nums[h]){
                // ans = min(ans,nums[l]);
                if(nums[l]<ans){
                    ans = nums[l];
                    index = l;
                }
                break;
            }
            if(nums[l]<=nums[mid]){
                // ans = min(ans,nums[l]);
                if(nums[l]<ans){
                    ans = nums[l];
                    index = l;
                }
                l=mid+1;
            }else{
                // ans = min(ans,nums[mid]);
                if(nums[mid]<ans){
                    ans = nums[mid];
                    index = mid;
                }
                h=mid-1;
            }
        }
        return index;
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