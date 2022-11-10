class Solution {
public:
    int balancedStringSplit(string s) {
        string res = "a";
        int ans =0;
        for(auto &it:s){
            if(res.back()!='a'&&res.back()!=it){
                res.pop_back();
            }else{
                res.push_back(it);
            }
            if(res.back()=='a') ans++;
        }
        return ans;
    }
};