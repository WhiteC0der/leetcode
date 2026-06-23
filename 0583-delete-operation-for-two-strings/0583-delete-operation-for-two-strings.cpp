class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,string word1, string word2){
        if(i==0 || j==0){
            return i+j;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i-1]==word2[j-1]){
            return dp[i][j] = solve(i-1,j-1,word1,word2);
        }

        return dp[i][j] = 1+ min(solve(i-1,j,word1,word2),solve(i,j-1,word1,word2));
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int m,n;
        m=word1.length();
        n=word2.length();
        return solve(m,n,word1,word2);
    }
};