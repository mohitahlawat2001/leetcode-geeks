//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        // code here
        vector<int> preSum , sufSum;
        int sum=0;
        for(auto it:A){
            sum+=it;
            preSum.push_back(sum);
        }
        sum=0;
        for(int i=A.size()-1;i>=0;i--){
            sum+=A[i];
            sufSum.push_back(sum);
        }
        reverse(sufSum.begin(),sufSum.end());
        // for(auto it:preSum) cout<<it<<" ";
        // cout<<endl;
        // for(auto it:sufSum) cout<<it<<" ";
        for(int i=0;i<N;i++){
            if(preSum[i]-A[i] == sufSum[i]-A[i]){
                return i+1;
            }
        }
        return -1;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends