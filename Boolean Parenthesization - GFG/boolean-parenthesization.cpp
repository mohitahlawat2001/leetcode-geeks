//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
/*
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
    */
    
    int countWays(int N, string s){
        // code here
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(N+1,vector<int>(2,0)));
        
        // return f(0,N-1,1,S,dp);
        
        for(int i =0;i<N;i++) {
            dp[i][i][1] = s[i]=='T';
            dp[i][i][0] = s[i]=='F';
        }
        
        for(int i = N-1;i>=0;i--){
            for(int j=0;j<N;j++){
            for(int istrue=0;istrue<2;istrue++){
                int ways =0;
        
                for(int k =i+1;k<=j-1;k+=2){
                    int lt = dp[i][k-1][1],
                        lf = dp[i][k-1][0],
                        rf = dp[k+1][j][0],
                        rt = dp[k+1][j][1];
                    
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
                    dp[i][j][istrue] = ways%1003;
                }
                
                }
            }
        }
        
        
        return dp[0][N-1][1];
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