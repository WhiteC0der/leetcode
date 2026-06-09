class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxelm=INT_MIN;
        int minelm=INT_MAX;
        for(int i=0;i<nums.size();i++){
            maxelm=max(nums[i],maxelm);
            minelm=min(nums[i],minelm);
        }

        return 1LL*k*(maxelm-minelm);
    }
};