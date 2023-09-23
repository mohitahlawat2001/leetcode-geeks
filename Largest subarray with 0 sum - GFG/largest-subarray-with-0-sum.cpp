//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
   
    int maxLen(vector<int>&A, int N)
    {   
        // Your code here
        int K=0;
         unordered_map<long long , int> map;
        long long sum=0;
        int ans=0;
        for(int i=0;i<N;i++){
            sum += A[i];
            if(sum==K){
                ans = max(ans,i+1);
            }
            int rem = sum-K;
            if(map.count(rem)){
                ans = max(ans,i-map[rem]);
            }
            if(map.count(sum)==0){
                map[sum]=i;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends