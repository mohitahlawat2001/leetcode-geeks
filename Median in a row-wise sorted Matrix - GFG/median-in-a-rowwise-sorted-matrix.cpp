//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int small(vector<vector<int>> &mat, int R, int C, int m){
        int cnt=0;
        for(auto &it:mat){
            cnt += upper_bound(it.begin(),it.end(),m) - it.begin();
        }
        return cnt;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here          
        int minE = INT_MAX, maxE = INT_MIN;
        for(int i=0;i<R;i++){
            minE  = min(minE,matrix[i][0]);
            maxE = max(maxE,matrix[i][C-1]);
        }
        int req = (R*C)/2 ;
        
        int l=minE, r=maxE;
        while(r>=l){
            int m = l +(r-l)/2;
            int sele = small(matrix,R,C,m);
            if( sele<=req) l = m+1;
            else r =m-1;
        }
        return l;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends