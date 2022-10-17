class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> a(26,0);int c=0;
        for(int i=0;i<s.length();i++){
            if(a[s[i]-'a']==0)
            {  a[s[i]-'a']++;
             c++;
            }
            
        }
        if(c<26) return 0;
        /*for(auto it:a)
           if(it==0)
               return 0;
        */
        return 1;
    }
};