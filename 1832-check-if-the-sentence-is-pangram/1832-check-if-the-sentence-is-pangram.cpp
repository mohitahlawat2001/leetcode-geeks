class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> a(26,0);
        for(int i=0;i<s.length();i++){
            a[s[i]-'a']++;
        }
        for(auto it:a)
           if(it==0)
               return 0;
        return 1;
    }
};