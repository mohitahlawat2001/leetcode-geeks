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
        unordered_map<char,int> map;
        int ans=0;
        int i,l=0;
        for(i=0;i<s.size();i++){
            map[s[i]]++;
            while(l<s.size() && map.size()>k){
                map[s[l]]--;
                if(map[s[l]]==0) map.erase(s[l]);
                l++;
            }
            
            if(map.size()==k) ans = max(ans,i-l+1);
        }
        if(ans==0) return -1;
        return ans;
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