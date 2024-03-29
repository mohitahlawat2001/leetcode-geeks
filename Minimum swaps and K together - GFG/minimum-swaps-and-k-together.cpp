//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int s = 0;
        for(int i =0 ; i<n ;i++){
            if(arr[i]<=k)
                s++;
        }
        int swap = 0;
        for(int i =0;i<s;i++ ){
            if(arr[i]>k){
                swap++;
            }
        }
        int minSwap = swap;
        
        for(int i=s;i<n;i++){
            if(arr[i]>k) swap++;
            // else swap--;
            if (arr[i-s]>k) swap--;
            // else swap++;
            minSwap = min(minSwap,swap);
        }
        return minSwap;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends