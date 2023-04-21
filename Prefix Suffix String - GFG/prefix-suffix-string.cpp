//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    class Node{
        vector<Node*> children;
        bool isEnd;
        // int prefix;
        public:
            Node(){
                children.resize(26,NULL);
                isEnd =0;
                // prefix=0;
            }
            bool isContain(char ch){
            return children[ch-'a'] != NULL;
            }
            Node* get(char ch){
                return children[ch-'a'];
            }
            void set(char ch){
                children[ch-'a'] = new Node();
            }
            bool getEnd(){
                return isEnd;
            }
            void setEnd(bool isEnd){
                this->isEnd = isEnd;
            }
            // void setPre(){
            //     prefix++;
            // }
            // int getPre(){
            //     return prefix;
            // }
    };
    void insert(string word,Node* root) {
        Node* curr = root;
        for(char i:word){
            if(curr->isContain(i)== false){
                curr->set(i);
            }
            curr = curr->get(i);
            // root->setPre();
        }
        curr->setEnd(true);
    }

    void insertr(string word,Node* root) {
        Node* curr = root;
        for(int  i= word.size()-1;i>=0;i--){
            if(curr->isContain(word[i])== false){
                curr->set(word[i]);
            }
            curr = curr->get(word[i]);
            // root->setPre();
        }
        curr->setEnd(true);
    }
    bool search(string word,Node* root) {
        Node* curr = root;
        for(char i:word){
            if(curr->isContain(i)== false){
                return false;
            }
            curr = curr->get(i);
        }
        return true;
    }
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        
        Node* rootp = new Node();
        Node* roots = new Node();
        for(string s:s1){
            insert(s,rootp);
            insertr(s,roots);
        }
        int ans=0;
        for(string s:s2){
            string se =s;
            reverse(s.begin(),s.end());
            if(search(se,rootp) || search(s,roots)){
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends