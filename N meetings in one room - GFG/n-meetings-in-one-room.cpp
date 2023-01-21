//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> interval;
        for(int i = 0 ; i< n ; i++){
            interval.push_back(make_pair(start[i],end[i]));
        }
        sort(interval.begin(),interval.end(),comp);
        // for(auto it:interval){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        int limit = INT_MIN;
        int count = 0;
        for(int i = 0;i<n;i++){
            if(limit<interval[i].first){ count++;
            limit = interval[i].second;}
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends