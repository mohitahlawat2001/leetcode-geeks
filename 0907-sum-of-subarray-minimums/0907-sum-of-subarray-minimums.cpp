class Solution {
public:
    const int MOD = 1000000007;

    int sumSubarrayMins(vector<int>& arr) {
         int n = arr.size();
        vector<long long> dp(n,0); // sum of mins of subarray ending at i
        vector<int> stack;
        
        for (int i = 0; i < n; i++) {
            while(!stack.empty() and arr[stack.back()] > arr[i])
                stack.pop_back();
            if (stack.empty()) {
                dp[i] = (i + 1)*arr[i];
            } else {
                int prev = stack.back();
                dp[i] = dp[prev] + (i - prev)*arr[i];
            }
            stack.push_back(i);
        }
        int ans = 0;
        for (auto x: dp)
            ans = (ans + x) % MOD;
        return ans;
    }
};