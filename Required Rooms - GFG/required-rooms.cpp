//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int rooms(int N, int M){
        // code here
        return (N+M)/gcd(N,M);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        
        Solution ob;
        cout<<ob.rooms(N, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends