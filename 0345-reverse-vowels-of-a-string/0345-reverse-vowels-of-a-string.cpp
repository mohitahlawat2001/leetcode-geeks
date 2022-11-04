class Solution {
public:
     bool isVowel(char c) const{
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        while(j>i){
            if(isVowel(s[i])&&isVowel(s[j])){
                swap(s[j--],s[i++]);
            }
            
            
            
            else if(isVowel(s[j])&&!isVowel(s[i])){
                 
                    i++;
            }
            else if (isVowel(s[i])&&!isVowel(s[j])){
            
                j--;
            } else{
                i++;
                j--;
            }
            
            
        }
        return s;
    }
};