class Solution {
public:
    int dp[101];
    
    int solve(vector<int>& nums,int i,int n){
        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1) return dp[i];

        return dp[i] =max(solve(nums,i+2,n)+nums[i],solve(nums,i+1,n)); 
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        int case_1=solve(nums,0,n-1);
        memset(dp,-1,sizeof(dp));
        
        int case_2=solve(nums,1,n);

        return max(case_1,case_2);     
    }
};