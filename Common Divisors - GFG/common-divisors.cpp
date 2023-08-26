//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int gcd(long long int a, long long int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    long long int commDiv(long long int a,long long int b) {
        // code here
        long long int N = gcd(a,b); 
         int count=0;
        for(long long int i=1;i*i<=N;i++){
            if(N%i==0 and N/i ==i) {
                count++;
                continue;
            }
            if(N%i==0) count+=2;;
        }
        // if(count==1) count++;
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int a, b;
        cin >> a >> b;
        Solution ob;
        cout<<ob.commDiv(a, b)<<endl;
    }
    return 0;
}

// } Driver Code Ends