class Solution {
public:
     Solution(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
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