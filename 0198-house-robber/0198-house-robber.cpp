class Solution {
public:
    int t[101];
    int solve(int i,vector<int>& nums){
        if(i>=nums.size()){
            return 0;
        }

        if(t[i]!=-1) return t[i];

        return t[i] = max(nums[i]+solve(i+2,nums),solve(i+1,nums));
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t)); // Array dynamic memset function
        return solve(0,nums);
    }
};