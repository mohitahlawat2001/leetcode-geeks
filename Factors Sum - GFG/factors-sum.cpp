//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    long long factorSum(int N)
    {
        // Your code goes here
        long long count=0;
        for(long long i=1;i*i<=N;i++){
            if(N%i==0 and N/i ==i) {
                count+=i;;
                continue;
            }
            if(N%i==0) count+= i +N/i;;
        }
        // if(count==1) count++;
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
       	cout <<  ob.factorSum(N) << "\n";
   
    }
    return 0;
}

// } Driver Code Ends