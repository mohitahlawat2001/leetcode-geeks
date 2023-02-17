//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    pair<vector<int>, vector<int>> findTasks(int *arr, int m, int n) {
        // code here
        set<int> s;
        for(int i = 0 ; i<m; i++) s.insert(arr[i]);
        pair<vector<int>, vector<int>> ans;
        
        bool flag=0;
        for(int i=1;i<=n;i++){
            if(!s.count(i)){
                if(flag ==false){
                    ans.first.push_back(i);
                    flag = true;
                }else{
                    ans.second.push_back(i);
                    flag = false;
                }
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
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        Solution obj;
        auto ans = obj.findTasks(arr, m, n);
        for (auto x: ans.first) {
            cout << x << " ";
        }
        cout << "\n";
        for (auto x: ans.second) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends