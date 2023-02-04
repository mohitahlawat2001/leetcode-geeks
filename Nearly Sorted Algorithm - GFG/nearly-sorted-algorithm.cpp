#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int &it:arr)
        cin>>it;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 0; i<k;i++){
        q.push(arr[i]);
    }
    vector<int> ans;
    for(int i = k ; i<n ; i++ ){
        ans.push_back(q.top());
        q.pop();
        q.push(arr[i]);
    }
    for(int i = 0;i<k;i++){
        ans.push_back(q.top());
        q.pop();
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
	//code
	int k ;
	cin>>k;
	while(k--){
	    solve();
	}
	
	
	return 0;
}