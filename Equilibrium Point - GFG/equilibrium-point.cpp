//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        vector<long long> pre,post;
        long long sum=0;
        for(int i=0;i<n;i++){
            pre.push_back(sum);
            sum+=a[i];
            // cout<<sum
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            post.push_back(sum);
            sum+=a[i];
        }
        reverse(post.begin(),post.end());
        for(int i=0;i<n;i++){
            if(pre[i]==post[i]) return i+1;
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends