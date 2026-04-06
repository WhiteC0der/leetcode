class Solution {
public:
    int dp[2501][2501];
    int solver(int i,int prev,vector<int>& nums){
        if(i == nums.size()) return 0;

        if(prev!=-1 && dp[i][prev]!=-1) return dp[i][prev];

        int take = 0;
        if(prev==-1|| nums[i] > nums[prev]){
            take = 1 + solver(i+1,i, nums);
        }

        int skip = solver(i+1, prev, nums);
        if(prev == -1) return max(take,skip);

        return dp[i][prev] = max(take,skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solver(0,-1,nums);
    }
};