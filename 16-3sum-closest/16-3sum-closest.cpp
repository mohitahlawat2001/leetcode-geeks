class Solution {
public:
    int twoSumClosest(vector<int> &nums, int l, int target){
        int clos = INT_MAX;
        int ans ;
        int r = nums.size()-1;
        while(r>l){
            int sum = nums[l]+nums[r];
            if(abs(target -sum)<clos){
                clos = abs(target -sum);
                ans = sum;
            }
            if(sum>target)r--;
            else if(sum <target)l++;
            else{
                return target;
            }
        }
        return ans;
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        int res =0;
        for(int i=0;i<nums.size()-2;i++){
            int a = twoSumClosest(nums,i+1,target - nums[i]) +nums[i];
            if(abs(a-target)<ans){
                ans  = abs(a-target);
                res = a;
            }
        }
        return res;
    }
};