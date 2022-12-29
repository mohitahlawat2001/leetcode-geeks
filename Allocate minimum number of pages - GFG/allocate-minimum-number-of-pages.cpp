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
    bool isPossible(int pages[], int books , int maxLoad, int totalStud){
        int currStud =1 , currPages =0;
        
        for(int i=0; currStud <= totalStud && i< books; i++){
            if(currPages + pages[i]<= maxLoad){
                currPages += pages[i];
            } else{
                currStud++;
                currPages = pages[i];
            }
        }
        if(currStud > totalStud) return false;
        else return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M) return -1;
        int max = A[0], sum =0;
        for(int i=0;i<N;i++){
            if(A[i]>max){
                max = A[i];
            }
            sum+=A[i];
        }
        int l=max , r = sum;
        // cout<<l<<" "<<r<<endl;
        int ans = sum;
        while(l<=r){
            int m = l+(r-l)/2;
            if(isPossible(A,N,m,M)==true){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
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