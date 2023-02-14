//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int sortingCost(int N, int arr[]){
        // code here
        unordered_map<int,int> map;
        int maxLen = 0;
        for(int i = 0 ; i< N; i++){
            if(map.find(arr[i]-1) == map.end()){
                map[arr[i]]=1;
            }else{
                map[arr[i]]+= 1 + map[arr[i]-1];
            }
            if(map[arr[i]]>maxLen) maxLen = map[arr[i]];
        }
        return N-maxLen;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        Solution ob;
        
        cout<<ob.sortingCost(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends