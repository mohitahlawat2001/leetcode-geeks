class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp;
        for(auto val1:nums1)
            for(auto val2:nums2)
                mp[val1+val2]++;
        int count=0;
        for(auto val3:nums3)
            for(auto val4:nums4)
                count += mp[-val3-val4];
        
        return count;
    }
};