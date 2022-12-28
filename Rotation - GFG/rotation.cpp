//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    // code here
	    int l = 0, r = n - 1;
        
        while (l < r) {
            int mid = (l + r) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
            else if (nums[mid] > nums[l]) {
                r = mid - 1;
            }
            else if (nums[mid] < nums[r]) {
                r = mid;
            }
            else if (nums[mid] < nums[l]) {
                l = mid;
            }
        }

        return l;
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