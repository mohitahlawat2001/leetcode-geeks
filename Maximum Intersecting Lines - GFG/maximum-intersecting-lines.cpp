//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        vector<int> s,e;
        for(auto it:lines){
            s.push_back(it[0]);
            e.push_back(it[1]);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int l=0,r=0;
        int ans=0, cnt=0;
        while(l<N){
            if(s[l]<=e[r]){
                l++;
                cnt++;
            }else{
                r++;cnt--;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends