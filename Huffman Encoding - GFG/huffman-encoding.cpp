//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct node {
    int data;
    node *left,*right;
    
    node(int val=0){
        data=val;
        left = NULL;
        right = NULL;
    }
};
struct compare{
    bool operator()(node *a, node*b){
        if(a->data > b->data) return true;
        return false;
    }
};
void preorder(node *root, string str,vector<string> &ans){
    if(root != NULL){
        if(root->left ==NULL && root->right ==NULL){
            ans.push_back(str);
            str="";
        }
        if(root->left) preorder(root->left,str+"0",ans);
        if(root->right) preorder(root->right, str+"1",ans);
    }
}

class Solution
{
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N){
		    priority_queue<node*,vector<node*>,compare> q;
		    node *a;
		    node *b;
		    node *root;
		    for(int i = 0; i<f.size() ; i++){
		        root = new node(f[i]);
		        q.push(root);
		    }
		    while(q.size()>1){
		        a = q.top(); q.pop();
		        b = q.top(); q.pop();
		        root = new node(a->data + b->data);
		        root->left = a;
		        root->right = b;
		        q.push(root);
		    }
		    vector<string>ans;
		    preorder(root,"",ans);
		    return ans;
		    // Code here
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends