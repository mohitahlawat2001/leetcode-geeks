class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        
        for(auto &it:s){
            if(ans.size() && it=='*'){
                ans.pop_back();
            } else{
                ans.push_back(it);
            }
            // cout<<ans<<endl;
        }
        return ans;
    }
};