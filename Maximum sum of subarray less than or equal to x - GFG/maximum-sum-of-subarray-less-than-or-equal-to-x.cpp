//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	int findMaxSubarraySum(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    int l =0;
	    long long csum =0, maxsum=0;
	    for(int r=0; r<n;r++){
	        csum += arr[r];
	        
	        while(csum>sum){
	            csum -= arr[l];
	            l++;
	        }
	        maxsum = max(csum,maxsum);
	    }
	   // if(maxsum==INT_MIN) return 0;
	    return maxsum;
	    
	}  

		 

};
	  



//{ Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        long long a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        long long sum;
        cin >> sum;
        

        Solution ob;
		cout << ob.findMaxSubarraySum(a, n, sum);
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends