class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string& a,string& b){
        if(i>=a.length() || j>=b.length()){
            return 0;
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        if(a[i] == b[j]){
            return dp[i][j] = 1 + solve(i+1,j+1,a,b);
        }

        return dp[i][j] = max(solve(i+1,j,a,b),solve(i,j+1,a,b));
    }
    int longestCommonSubsequence(string a, string b) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,a,b);
    }
};