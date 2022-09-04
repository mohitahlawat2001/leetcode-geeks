class Solution {
public:
    int twoSumGreater(vector<int>& nums ,int r, int target){
        int count =0;
        int l=0;
        while(l<r){
            int sum = nums[l]+nums[r];
            if(sum > target){
                count += r-l;
                r--;
            } else{
                l++;
            }
        }
        return count;
    }
    
    int triangleNumber(vector<int>& nums) {
        int count =0;
        sort(nums.begin(),nums.end());
        for(int i = nums.size()-1;i>0;i--){
            count += twoSumGreater(nums,i-1,nums[i]);
        }
        return count;
    }
};