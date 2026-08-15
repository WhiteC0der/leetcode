class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            xr^=nums[i];
            if(nums[i]==0) zero++;
        }
        if(zero==nums.size()) return 0;

        return xr!=0 ? nums.size() : nums.size()-1;
    }
};