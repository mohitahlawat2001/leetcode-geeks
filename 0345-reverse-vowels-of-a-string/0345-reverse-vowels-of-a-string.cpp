class Solution {
public:
     bool isVowel(char c) const{
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        while(j>i){
            while(j>i&&!isVowel(s[i])){
                 
                    i++;
            }
            while(j>i&&!isVowel(s[j])){
            
                j--;
            }
            if (i < j)
            swap(s[j--],s[i++]);
            
        }
        return s;
    }
};