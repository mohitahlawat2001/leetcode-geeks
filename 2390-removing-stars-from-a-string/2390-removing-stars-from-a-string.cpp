class Solution {
public:
     Solution(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
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