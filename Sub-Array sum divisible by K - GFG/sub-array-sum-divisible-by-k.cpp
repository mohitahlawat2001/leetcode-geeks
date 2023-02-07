//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long subCount(long long arr[], int N, long long K)
	{
	    // Your code goes here
	    long long sum = 0,ans=0;
	    unordered_map<long long , long long> map;
	    map[sum]++;
	    for(long long i = 0 ; i <N; i++){
	        sum+=arr[i];
	        if(map[(sum%K+K)%K]>0){
	            ans+= map[(sum%K+K)%K];
	           // map[sum%K]++;
	        }
	        
	        map[(sum%K+K)%K]++;
	    }
	    return ans;
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
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends