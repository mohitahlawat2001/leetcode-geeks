//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        
        deque<long long> deq;
        for(int i =0; i<K ; i++){
            if(A[i]<0) deq.push_back(i);
        }
        vector<long long> ans(N-K+1);
        ans[0] = (deq.size()==0)? 0 : A[deq.front()];
        
        int window =1;
        for(int i = K; i< N; i++){
            if(deq.size()>0 && deq.front() <= i-K){
                deq.pop_front();
            }
            if(A[i]<0){
                deq.push_back(i);
            }
            ans[window++]=(deq.size()==0)? 0 : A[deq.front()];
        }
        return ans;
        
 }