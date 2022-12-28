//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int pivotElement(vector<int> arr,int l , int r){
        int ans = -1;
        while(l<=r){
            int m = l +(r-l)/2;
            if(arr[m]==0){
                l=m+1;
            }else{
                ans =m;
                r=m-1;
            }
        }
        return ans;
    }
    
    
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int r =m-1;
	    int ans = -1 , noOfOnes =0;
	    for(int i =0; i<n; i++){
	        int t = pivotElement(arr[i],0,r);
	        if(t!=-1 && m-t>noOfOnes){
	            ans =i;
	            noOfOnes = m -t;
	            r = t-1;
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
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends