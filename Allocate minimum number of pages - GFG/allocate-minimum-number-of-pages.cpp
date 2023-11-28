//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int fun(int A[], int N, int mid){
        int student=1, pages = 0;
        for(int i=0;i<N;i++){
            if(A[i]+pages <=mid){
                pages+=A[i];
            }else{
                student++;
                pages = A[i];
            }
        }
        return student;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        int l = *max_element(A,A+N), r = accumulate(A,A+N,0);
        while(r>=l){
            int mid = l + (r-l)/2;
            if(fun(A,N,mid)<=M){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends