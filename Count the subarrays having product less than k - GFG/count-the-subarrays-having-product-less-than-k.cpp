//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        // sort(a.begin(),a.end());
        if(k==1) return 0;
        int l=0,r=0;
        long long p =1;
        int ans=0;
        while(l<n && r<n){
            p = p*a[r];
            while(p>=k){
                p=p/a[l];
                l++;
            }
            if(p<k) ans += r-l+1;
            r++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends