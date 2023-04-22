//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int> temp = arr;
        sort(arr.begin(),arr.end());
        // unordered_map<int , long long> map;
        vector<long long> pre;
        long long sum=0;
        for(int i=0;i<n;i++){
            pre.push_back(sum);
            sum+=arr[i];
        }
        vector<long long> ans;
        for(int i:temp){
            int it = lower_bound(arr.begin(),arr.end(),i)-arr.begin();
            ans.push_back(pre[it]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends