//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int f(int a, int b){
	    if(b==0) return a;
	    return f(b,a%b);
	}
    int gcd(int N, int arr[])
    {
    	// Your code goes here
    	int ans = arr[0];
    	for(int i=1;i<N;i++){
    	    ans = f(ans,arr[i]);
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
        int N;
        cin >> N;

        int arr[N];
        for(int i = 0; i < N; i++)
        	cin >> arr[i];
        Solution ob;
       	cout <<  ob.gcd(N, arr) << "\n";
   
    }
    return 0;
}
// } Driver Code Ends