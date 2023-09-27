//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n==1) return 0;
        if(arr[0]==0) return -1;
        long long maxr = arr[0] , steps=arr[0],jump=1;
        long long i=1;
        while(i<n){
            
            long long last = i+steps,newi=i;
            for( i;i<last-1;i++){
                maxr = max(maxr,arr[i]+i);
            
                if(i>=n-1) return (int)jump;
            }
            maxr=max(maxr,arr[i]+i);
            if(i<n-1 and i>=maxr) return -1;
            if(i>=n-1) return (int)jump;
            jump++;
            steps = maxr-i+1;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends