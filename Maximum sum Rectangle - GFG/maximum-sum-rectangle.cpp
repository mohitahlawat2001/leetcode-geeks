//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kadane(vector<int> arr){
        int ans = INT_MIN, end_max = 0;
        for(int a:arr){
            end_max +=a;
            if(end_max>ans) ans=end_max;
            if(end_max<0) end_max=0;
        }
        return ans;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int ans = INT_MIN;
        
        for(int col=0;col<C;col++){
            
            vector<int> temp(R,0);
            for(int j=col;j<C;j++){
                for(int i=0;i<R;i++){
                    temp[i]+= M[i][j];        
                }
                ans = max(ans,kadane(temp));
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends