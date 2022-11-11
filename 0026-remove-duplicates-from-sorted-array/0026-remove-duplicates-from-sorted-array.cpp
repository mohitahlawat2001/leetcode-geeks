class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = 0;
        for(int i = 1; i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                n++;
            }else{
                nums[i-n]=nums[i];
            }
        }
        return nums.size()-n;
    }
};