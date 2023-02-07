//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        // code here
        unordered_map<string,int> map;
        int c0 =0, c1 = 0 , c2=0;
        string s= "0#0";
        map[s]++;
        long long ans=0;
        for(auto it:str){
            if(it=='0') c0++;
            else if(it=='1') c1++;
            else c2++;
            string l = to_string(c0-c1);
            string r = to_string(c1-c2);
            string key  =l+"#"+r;
            if(map[key]>0){
                ans+= map[key];
                map[key]++;
            }else{
                map[key]++;
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}

// } Driver Code Ends