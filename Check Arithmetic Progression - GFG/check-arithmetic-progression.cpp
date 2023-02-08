//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    bool checkIsAP(int arr[], int n)
    {
        // code here
        int &a = *min_element(arr,arr+n);
        int &an = *max_element(arr,arr+n);
        
        unordered_map<int,int> map;
        for(int i = 0 ; i <n; i++) map[arr[i]]++;
        
        int d = (an - a)/(n-1);
        for(int i=0 ; i< n; i++)
            if(map.find(a+ (i*d))==map.end()) return false;
            else{ map[a+ (i*d)]--;
            if(map[a+ (i*d)]==0) map.erase(a+ (i*d));
            }
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
         (ob.checkIsAP(arr, n))? (cout << "YES" << endl) :
                       (cout << "NO" << endl);   
    }
 
  return 0;
}

// } Driver Code Ends