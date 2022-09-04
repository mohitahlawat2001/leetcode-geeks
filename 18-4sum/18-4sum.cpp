class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int l , int target){
        vector<vector<int>> ans;
        int r = nums.size()-1;
        int start = l;
        while(r>l){
            if(l>start && nums[l]== nums[l-1]){
                l++; continue;
            }
            int sum = nums[l] + nums[r];
            if(sum == target ){
                ans.push_back({nums[l],nums[r]});
                l++;r--;
            } else if (sum > target) {
                r--;
            } else{
                l++;
            }
        }
        return ans;
    }
    
    vector<vector<int>> kSum(vector<int> nums, int start, long target, int k){
        vector<vector<int>> res;
        int len = nums.size();
        if (start > len - 1) {
            return res;
        }
        int average_value = target / k;
        if (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }
        if(k==2){
            return twoSum(nums, start, target);
        }
        // vector<vector<int>> res;
        for(int i = start; i<=nums.size()-k;i++){
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
             vector<vector<int>> subRes = kSum(nums,i+1,target-nums[i],k-1);
            for(auto &it: subRes){
                it.insert(it.begin(),nums[i]);
                res.push_back(it);
            }
            
        }
        return res;
        
        
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 4) {
            return {};
        }
        sort(nums.begin(),nums.end());
        return kSum(nums,0,(long)target,4);
    }
  /*   vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
    
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
        vector<vector<int>> res;
        int len = nums.size();
        if (start > len - 1) {
            return res;
        }
        int average_value = target / k;
        if (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }
        if (k == 2) {
            int l = start, r = len - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum > target) {
                    --r;
                } else if (sum < target) {
                    ++l;
                } else {
                    res.push_back({nums[l], nums[r]});
                    --r;
                    ++l;
                    while (l < r && l > start &&  nums[l] == nums[l - 1]) {
                        ++l;
                    }
                    while (l < r && r < len - 1 && nums[r] == nums[r + 1]) {
                        --r;
                    }
                }
            }
            return res;
        } 
        for (int i = start; i < len - k + 1; ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            vector<vector<int>> itemSoFar = kSum(nums, target - nums[i], i + 1 , k - 1);
            for (auto& item : itemSoFar) {
                item.insert(item.begin(), nums[i]);
                res.push_back(item);
            }
        }
        return res;
    }*/
};