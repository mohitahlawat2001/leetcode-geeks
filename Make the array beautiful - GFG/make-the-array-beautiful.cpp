//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool opp(int x, int y)
    {
	return ((x ^ y) >> 31);
    }

    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        if(arr.size()==0) return {};
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            // for(auto it:ans){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            
            if(ans.size()==0){
                ans.push_back(arr[i]);
            }else if(opp(ans[ans.size()-1],arr[i])){
                ans.pop_back();
            }else{
                ans.push_back(arr[i]);
            }
            // for(auto it:ans){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
        }
        return ans;
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

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends