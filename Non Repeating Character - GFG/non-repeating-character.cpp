//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       unordered_map<char,pair<int,int>> map;
       for(int i = 0 ; i <S.length() ; i++){
           if(map.find(S[i]) == map.end()){
               map[S[i]].first++;
               map[S[i]].second=i;
           }else{
               map[S[i]].first++;
           }
       }
        char ans='$';
        int m = INT_MAX;
       for(auto v:map){
           if(v.second.first == 1 && m>v.second.second)
            {    ans =v.first; m = v.second.second;}
       }
       return ans;
       
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends