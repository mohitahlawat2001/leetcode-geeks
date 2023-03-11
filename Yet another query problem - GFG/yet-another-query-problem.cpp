//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        unordered_map<int,int> map;
        vector<int> sum(A.size(),0);
        vector<int> ans;
        for(int i = A.size()-1; i>=0;i--){
            map[A[i]]++;
            sum[i]=map[A[i]];
        }
        for(int i=0;i<num;i++){
            int l = Q[i][0] , r = Q[i][1] , k = Q[i][2];
            int count=0;
            for(int j=l;j<=r;j++){
                if(sum[j]==k) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends