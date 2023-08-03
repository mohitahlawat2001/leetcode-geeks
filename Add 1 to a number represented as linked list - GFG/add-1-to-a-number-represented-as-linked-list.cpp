//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addTwoNumbers(Node* l1, Node* l2) {
        Node* res = new Node(-1);
        Node* result = res;
        int c =0;
        while(l1 != NULL || l2 != NULL || c !=0){
            int h1 =0, h2=0;
            if(l1!=NULL) {
                h1 = l1->data;
                l1 = l1->next;
            } 
            if(l2!=NULL){
                h2 = l2->data;
                l2 = l2->next;
            }
            res->next = new Node( (h1+h2+c)%10);
            res = res->next;
            c = (h1+h2+c)/10;
        }
        return result->next;;
    }
    Node* rev(Node *head){
        Node* prev =NULL;
        Node * curr = head;
        while(curr!=NULL){
            Node* ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* reverse = rev(head);
        Node* one = new Node(1);
        Node * ans = addTwoNumbers(reverse,one);
        
        return rev(ans);
        
        
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends