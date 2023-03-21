//{ Driver Code Starts



#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
// 	bool palindromeString(string s) {
//     // Write your code here.
//         unordered_map<char ,int> map;
//         for(char ch:s)
//             map[ch]++;
//         int flag = 0;
//         for(auto it:map){
//             if(it.second%2!=0) flag++;
//             if(flag>1) return false;
//         }
//         return true;
//     }
        vector<string> res;
        void permute(int idx, map<char,int> map,string s){
            if(idx==s.size()/2){
                res.push_back(s);
            }
            for(auto &it:map){
                if(it.second>0){
                    it.second -=2;
                    s[idx]=it.first;
                    s[s.length()-idx-1]=it.first;
                    permute(idx+1,map,s);
                    
                    it.second +=2;
                }
            }
        }
        
		vector<string> all_plaindromes(string s)
		{
		    // Code here
		    map<char,int> map;
		    
		    for(auto ch:s ) map[ch]++;
		    
		    char flag ='0';
		    for(auto &it:map){
		        if(it.second %2==1){
		            if(flag=='0'){
		                flag=it.first;
		                it.second--;
		            }else{
		                return {};
		            }
		        }
		    }
		    string str="";
		    for(int i=0;i<s.length();i++){
		        str+=flag;
		    }
		    permute(0,map,str);
		    return res;
		    
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s;
    	cin >> s;
        Solution ob;
    	vector<string> ans  = ob.all_plaindromes(s);
    	cout<<"{ ";
    	for(auto i: ans)
    		cout << i << " ";
    	cout<<"}";
    	cout<<"\n";
    }
	return 0;
}


// } Driver Code Ends