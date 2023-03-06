//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
       vector<int> v;

        while(n){

            v.push_back(n%2);

            n/=2;

        }

        int count=0;

        for(int i=v.size()-1;i>=0;i--){

            if(v[i]==1)count++;else count=0;

            if(count==3){v[i]=0;count=0;}

 

        }        

        for(int i=v.size()-1;i>=0;i--){

            n+=(v[i]*pow(2,(i)));

        }

        return n;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends