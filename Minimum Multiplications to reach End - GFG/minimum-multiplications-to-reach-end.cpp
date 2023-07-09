//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start ==  end ) return 0;
        int n = arr.size();
        queue<pair<int,int>> q;
        q.push({0,start});
        
        vector<int> dist(100001,1e9);
        dist[start]=0;
        while(!q.empty()){
            int step = q.front().first;
            int node = q.front().second;
            
            q.pop();
            for(int i=0;i<n;i++){
                int val = (node*arr[i])%100000;
                if(step+1 < dist[val] ){
                    dist[val] = step+1;
                    if(val == end) return step+1;
                    q.push({step+1,val});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends