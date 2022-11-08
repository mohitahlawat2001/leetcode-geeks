class Solution {
public:
    string makeGood(string s) {
       int n = s.length();
        stack <char> st;
        
        for(int i=0;i<n;i++){ 
            if(st.size()==0)
             {
                st.push(s[i]);   
             }
            
            else if(st.size()>0){
                char currchar=s[i];         
                char upperchar=toupper(currchar);
                char lowerchar=tolower(currchar);

                if(st.top()==upperchar and s[i]==lowerchar){
                    st.pop();
                }
                else if(st.top()==lowerchar and s[i]==upperchar){
                    st.pop();
                }

                else{
                    st.push(s[i]);
                }
            }
        }
                
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};