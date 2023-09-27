//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // first sort a both array
        sort(a.begin(), a.end(),greater<int>());
        sort(b.begin(), b.end(),greater<int>());
        
        // create a priority queue of max heap
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({a[0]+b[0],{0,0}});
        set<pair<int,int>> s;
        vector<int> ans;
        for(int i=0;i<k;i++){
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.first);
            int x = it.second.first , y = it.second.second;
            if(x+1 < n && !s.count({x+1,y})){
                pq.push( {a[x+1]+b[y],{x+1,y}});
                s.insert({x+1,y});
            }
            if(y+1 < n && !s.count({x,y+1})){
                pq.push( {a[x]+b[y+1],{x,y+1}});
                s.insert({x,y+1});
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
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends