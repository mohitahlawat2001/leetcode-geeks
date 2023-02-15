//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        set<char> s;
        for(char it:str) s.insert(it);
        
        int i = 0 , j = 0 ;
        int ans = INT_MAX;
        unordered_map<char,int> map;
        while(i<str.length()){
            map[str[i]]++;
            // if(map.size()==s.size()){
            //     while(map[str[j]]>1){
            //         map[str[j]]--;
            //         j++;
            //     }
            //     ans = min(ans,i-j+1);
            // }
            while(map.size()==s.size()){
                ans = min(ans,i-j+1);
                map[str[j]]--;
                if(map[str[j]]==0) map.erase(str[j]);
                j++;
  
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends