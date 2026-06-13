class Solution {
public:
    bool solve(int idx,int sum,vector<int>& nums,vector<vector<int>>& dp){
        if(sum==0) return true;
        if(idx>= nums.size() || sum<0) return false;
        if(dp[idx][sum] !=-1) return dp[idx][sum];
        
        return dp[idx][sum] = solve(idx+1,sum-nums[idx],nums,dp) || solve(idx+1,sum,nums,dp);
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &num : nums) sum+=num;
        if(sum%2!=0) return false;
        vector<vector<int>> dp(nums.size(),vector<int> ((sum/2)+1,-1));

        return solve(0,sum/2,nums,dp);
    }
};