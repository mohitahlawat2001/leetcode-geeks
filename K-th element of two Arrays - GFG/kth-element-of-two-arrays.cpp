//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m) return kthElement(arr2,arr1,m,n,k);
        
        int l = max(0,k-m), r =min(n,k);
        while(r>=l){
            int mid1 = (r+l)>>1;
            int mid2 = k-mid1;
            int l1 = (mid1==0) ? INT_MIN : arr1[mid1-1];
            int l2 = (mid2==0) ? INT_MIN : arr2[mid2-1];
            int r1 = (mid1<n) ? arr1[mid1]:INT_MAX;
            int r2 = (mid2<m) ? arr2[mid2]:INT_MAX;
            
            
            if(l1<=r2 and l2<=r1){
                return max(l1,l2);
            }else if(l1>r2){
                r = mid1-1;
            }else{
                l = mid1+1;
            }
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends