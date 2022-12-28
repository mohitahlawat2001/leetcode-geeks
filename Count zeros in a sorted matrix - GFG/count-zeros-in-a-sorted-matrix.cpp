//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

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
    
    
	int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
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
	int countZeros(vector<vector<int>>A)
	{
		//code here
		int n = A.size();
		int r =n-1;
		
	    int ans = 0;
	    for(int i =0; i<n; i++){
	        int t = pivotElement(A[i],0,r);
	       // cout<<t<<" ";
	       if(t==-1) 
	            ans+=A[0].size();
	       else{ 
	           ans +=t;
	            r = t;
	       }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>A(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                cin>>A[i][j];
            }
        }
        Solution ob;
        cout<<ob.countZeros(A)<<'\n';
    }
    return 0;
}

// } Driver Code Ends