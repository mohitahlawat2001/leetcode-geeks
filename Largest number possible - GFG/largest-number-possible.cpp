//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int S, int N){
        // code here
        if(S==1 and N==0) return "0";
        if(N==0) return "-1";
        string ans="";
        for(int i=9;i>=1;i--){
            while(N>0 && N-i>=0){
                N-=i;
                ans+= to_string(i);
            }   
            // cout<<ans;
            if(ans.size()>S) return "-1";
        }
        while(ans.size()<S){
            ans+='0';
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends