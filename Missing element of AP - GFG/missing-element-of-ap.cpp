//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMissing(int arr[], int n) {
        // code here
        int a = arr[0];
        int d = (arr[n-1]-arr[0])/n;
        int l =0, r = n-1;
        int ans =arr[0];
        while(r>=l){
            int m = l+(r-l)/2;
            if(arr[m]>(arr[0]+m*d)){
                ans = arr[0]+m*d;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMissing(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends