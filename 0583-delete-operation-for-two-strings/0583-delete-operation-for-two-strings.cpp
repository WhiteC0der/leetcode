class Solution {
public:
    int dp[501][501];
    // int solve(int i,int j,string word1, string word2){
    //     if(i==0 || j==0){
    //         return i+j;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(word1[i-1]==word2[j-1]){
    //         return dp[i][j] = solve(i-1,j-1,word1,word2);
    //     }

    //     return dp[i][j] = 1+ min(solve(i-1,j,word1,word2),solve(i,j-1,word1,word2));
    // }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int m,n;
        m=word1.length(); 
        n=word2.length();
        
        for(int i=0;i<=m;i++) dp[i][0] = i;
        for(int j=0;j<=n;j++) dp[0][j] = j;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};