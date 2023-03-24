//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        unordered_map<char,int> map;
        for(auto ch:S){
            map[ch]++;
        }
        int l=0,r=S.size()-1;
        int flag=0;
        while(r>=l){
            if(flag==0){
                while(map[S[l]]==1){
                    l++;
                    if(l>r) return S;
                }
                if(map[S[l]]>1){
                    map[S[l]]--;
                    S.erase(l,1);
                    r=S.size()-1;
                }
                else{
                    l++;
                }
                flag=1;
                // cout<<S<<endl;
            } else{
                while(map[S[r]]==1){
                    r--;
                    if(l>r) {
                        string temp = S;
                        reverse(temp.begin(),temp.end());
                        return temp;
                    }
                }
                if(map[S[r]]>1){
                    map[S[r]]--;
                    S.erase(r,1);
                }
                else{
                    r--;
                }
                flag=0;
                // cout<<S<<endl;
            }
        
        }
        if(flag==0) {
            string temp = S;
                        reverse(temp.begin(),temp.end());
                        return temp;
        }
        return S;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends