//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
      int l = 0, maxLen = 0;
        unordered_map<char,int> f;
        for(int r=0;r<s.size();r++){
            f[s[r]]++;
            while(f.size()>k){
                    f[s[l]]--;
                    if(f[s[l]]==0)
                        f.erase(s[l]);
                l++;
            }
            if(f.size()==k)
            maxLen = max(maxLen,r-l+1);
        }
        if(maxLen==0) return -1;
        return maxLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends