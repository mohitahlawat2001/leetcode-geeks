class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        if(s.size()==1){
            return {{s[0]}};
        }
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        for(int i =0; i <s.size();i++){
            string st = s[i];
            sort(st.begin(),st.end());
            m[st].push_back(s[i]);
        }
        
        for(auto i = m.begin(); i!=m.end();i++){
            ans.push_back(i -> second);
        }
        return ans;
    }
};