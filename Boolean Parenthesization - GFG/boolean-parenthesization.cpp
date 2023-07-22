//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i, int j, int istrue , string &s, vector<vector<vector<int>>> &dp){
        if(i>j) return 0;
        if(i==j){
            if(istrue) return s[i]=='T';
            return s[i]=='F';
        }
        
        if(dp[i][j][istrue] != -1) return dp[i][j][istrue];
        int ways =0;
        
        for(int k =i+1;k<=j-1;k+=2){
            int lt = f(i,k-1,1,s,dp),
                lf = f(i,k-1,0,s,dp),
                rf = f(k+1,j,0,s,dp),
                rt = f(k+1,j,1,s,dp);
            
            if(s[k]=='&'){
                if(istrue){
                    ways+= lt*rt;
                }else{
                    ways+= rf*lt + rt*lf + lf*rf; 
                }
            } else if (s[k]=='|'){
                if(istrue){
                    ways+= rf*lt + rt*lf + lt*rt;
                }else{
                    ways+= lf*rf;
                }
            } else{
                if(istrue){
                    ways+= rf*lt + rt*lf;
                }else{
                    ways+= lt*rt + rf*lf;
                }
            }
        }
        
        return dp[i][j][istrue] = ways%1003;
    }
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        
        return f(0,N-1,1,S,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends