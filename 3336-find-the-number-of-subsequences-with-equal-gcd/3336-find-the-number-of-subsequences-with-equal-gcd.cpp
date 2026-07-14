class Solution {
public:
    int dp[201][201][201];
    const int mod = 1e9+7;
    long long solve(int i,vector<int>& nums,int g1,int g2){
        if(i==nums.size()){
            return (g1!=0 && g2!=0 && g1==g2) ? 1 : 0;
        }
        if(dp[i][g1][g2]!=-1) return dp[i][g1][g2];
        long long skip = solve(i+1,nums,g1,g2);
        long long take1= solve(i+1,nums,g1,gcd(g2,nums[i]));
        long long take2 = solve(i+1,nums,gcd(g1,nums[i]),g2);
        long long total = skip + take1 + take2;

        return dp[i][g1][g2] = total % mod;  
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,0,0);
    }
};