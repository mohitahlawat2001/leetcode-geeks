//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int merge(int arr[],int l,int m , int r){
	    int i = l , j = m+1 , k =0;
	    int res[r-l+1];
	    int invCount =0;
	    while(i<=m && j<=r){
	        if(arr[i]<= arr[j]){
	            res[k++] = arr[i++];
	        }else{
	            invCount += m - i +1;
	            res[k++] = arr[j++];
	        }
	    }
	    while(i<=m) res[k++] = arr[i++];
	    while(j<=r) res[k++] = arr[j++];
	    
	    for(int i = l; i<= r; i++){
	        arr[i] = res[i-l];
	    }
	    return invCount;
	}
		
	int mergeSort(int arr[], int l, int r){
	    if(l>=r) return 0;
	    int m = l+(r-l)/2;
	    int left = mergeSort(arr,l,m);
	    int right = mergeSort(arr,m+1,r);
	    int count = merge(arr,l,m,r);
	    return left + count + right;
	}
		
	int countSwaps(int arr[], int n)
	{
	    // Your code goes here
	    return mergeSort(arr,0,n-1);
	}
};

//{ Driver Code Starts.

int main() 
{
   
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countSwaps(arr, n);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends