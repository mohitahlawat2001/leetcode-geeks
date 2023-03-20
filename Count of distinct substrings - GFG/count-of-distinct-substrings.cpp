//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */
class Node{
        vector<Node*> children;
        bool isEnd ;
        public:
        Node(){
            children.resize(26,NULL);
            this->isEnd = false;
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
    };

// void insert(string word,Node* root) {
//         Node* curr = root;
//         for(char i:word){
//             if(curr->isContain(i)== false){
//                 curr->set(i);
//             }
//             curr = curr->get(i);
//         }
//         curr->setEnd(true);
// }
int countDistinctSubstring(string s)
{
    //Your code here
    Node* root = new Node();
    int count =0;
    for(int i=0;i<s.length();i++){
        Node *curr= root;
        for(int j=i;j<s.length();j++){
            if(curr->isContain(s[j])==false){
                curr->set(s[j]);
                count++;
            }
            curr = curr->get(s[j]);
        }
    }
     return count+1;       
    
    
    
}